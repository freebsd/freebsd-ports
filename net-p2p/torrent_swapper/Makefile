# New ports collection makefile for:	torrent_swapper
# Date created:				2007-04-17
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	torrent_swapper
PORTVERSION=	1.0
PORTREVISION=	7
CATEGORIES=	net-p2p
MASTER_SITES=	SF/bit-torrent/bit-torrent/Torrent%20Swapper
DISTNAME=	swapper

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Sociable P2P network client based on Bittorrent

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}m2crypto>=0.19.1:${PORTSDIR}/security/py-m2crypto \
		${PYTHON_SITELIBDIR}/_bsddb.so:${PORTSDIR}/databases/py-bsddb

DEPRECATED=	development has ceased (last release is of 2006)
EXPIRATION_DATE=	2011-04-11

USE_PYTHON=	2.5+
USE_WX=		2.6+
WX_COMPS=	python
WX_UNICODE=	yes
NO_WRKSUBDIR=	yes

post-extract:
	@${FIND} ${WRKSRC} -type f -name "*.pyc" -print0 | ${XARGS} -0 ${RM} -f
	@cd ${WRKSRC} && \
		${RM} -rf *.bat *.exe.* *.nsi *.sh LICENSE.txt debian mac && \
		${MKDIR} _extras && \
		${MV} how_to_compile.txt lastest_version.txt protocol_v3.txt \
			readme.txt swapper.xpm _extras

do-build:
	@(${ECHO_CMD} "#!${SH}"; ${ECHO_CMD} "cd ${DATADIR} || exit 1"; \
	  ${ECHO_CMD} 'exec ${PYTHON_CMD} abc.py "$$@"') > \
	  ${WRKSRC}/_extras/${PORTNAME}
	@${PYTHON_CMD} -Oc 'import compileall; \
		compileall.compile_dir("${WRKSRC}", force=1)'

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/_extras/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${CP} -R ${WRKSRC}/[^_]* ${DATADIR}
	@${FIND} ${DATADIR} -type d -print0 | ${XARGS} -0 ${CHMOD} ${BINMODE}
	@${FIND} ${DATADIR} -type f -print0 | ${XARGS} -0 ${CHMOD} ${SHAREMODE}
	${MKDIR} ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/_extras/swapper.xpm \
		${PREFIX}/share/pixmaps
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/_extras/*.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
