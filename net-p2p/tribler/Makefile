# New ports collection makefile for:	tribler
# Date created:				2007-04-10
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	tribler
PORTVERSION=	4.0.4
PORTREVISION=	2
CATEGORIES=	net-p2p
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Tribler%20V${PORTVERSION}
DISTNAME=	Tribler_${PORTVERSION}_src

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Streaming capable P2P network client based on BitTorrent

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}m2crypto>=0.19.1:${PORTSDIR}/security/py-m2crypto \
		${PYTHON_SITELIBDIR}/_bsddb.so:${PORTSDIR}/databases/py-bsddb

USE_ZIP=	yes
USE_PYTHON=	2.4+
USE_WX=		2.6+
WX_COMPS=	python
WX_UNICODE=	yes

post-extract:
	@cd ${WRKSRC} && \
		${RM} -rf *.bat *.exe.* *.nsi *.sh contrib-win32.txt \
		    *LICENSE.txt debian mac *.command && \
		${MV} protocol_v3.txt readme.txt tribler*.xpm ..

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|/bin/netstat|netstat|' \
		${WRKSRC}/Tribler/NATFirewall/guessip.py

do-build:
	@(${ECHO_CMD} "#!${SH}"; ${ECHO_CMD} "cd ${DATADIR} || exit 1"; \
	  ${ECHO_CMD} 'exec ${PYTHON_CMD} ${PORTNAME}.py "$$@"') \
	  > ${WRKDIR}/${PORTNAME}
	@${PYTHON_CMD} -Oc 'import compileall; \
		compileall.compile_dir("${WRKSRC}", force=1)'

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${CP} -R ${WRKSRC}/* ${DATADIR}
	@${FIND} ${DATADIR} -type d -print0 | ${XARGS} -0 ${CHMOD} ${BINMODE}
	@${FIND} ${DATADIR} -type f -print0 | ${XARGS} -0 ${CHMOD} ${SHAREMODE}
	${MKDIR} ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKDIR}/tribler*.xpm ${PREFIX}/share/pixmaps
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/*.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
