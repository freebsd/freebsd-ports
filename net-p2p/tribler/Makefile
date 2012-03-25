# New ports collection makefile for:	tribler
# Date created:				2007-04-10
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	tribler
PORTVERSION=	5.5.20
CATEGORIES=	net-p2p
#MASTER_SITES=	http://dl.tribler.org/
MASTER_SITES=	GENTOO/distfiles \
		GOOGLE_CODE:apsw
DISTFILES=	${PORTNAME}_${PORTVERSION}-1ubuntu1_all.deb \
		${APSW_DISTFILE}:apsw
EXTRACT_ONLY=	${PORTNAME}_${PORTVERSION}-1ubuntu1_all.deb

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Streaming capable P2P network client based on BitTorrent

LICENSE=	LGPL21 MIT
LICENSE_COMB=	multi

EXTRACT_DEPENDS=unzip:${PORTSDIR}/archivers/unzip
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>=0:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}m2crypto>=0:${PORTSDIR}/security/py-m2crypto

WRKSRC=		${WRKDIR}/${APSW_DISTNAME}

USE_PYTHON=	2.5-2.7
USE_PYDISTUTILS=yes
PYDISTUTILS_EGGINFO=	${APSW_DISTNAME:S/-r/_r/}-py${PYTHON_VER}.egg-info

USE_WX=		2.8+
WX_COMPS=	python
WX_UNICODE=	yes

PROJECTHOST=	apsw
USE_SQLITE=	3
APSW_DISTNAME=	apsw-3.7.10-r1
APSW_DISTFILE=	${APSW_DISTNAME}.zip

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

TRIBLER_DIR=	${PYTHONPREFIX_SITELIBDIR}/Tribler

post-extract:
	@(${GZCAT} ${WRKDIR}/data.tar.gz | ${TAR} -C ${WRKDIR} -xf -)
	@(${UNZIP_CMD} -qo ${DISTDIR}/${APSW_DISTFILE} -d ${WRKDIR})

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|/bin/netstat|netstat|' \
		${WRKDIR}/usr/share/tribler/Tribler/Core/NATFirewall/guessip.py
	@${REINPLACE_CMD} -e 's|%%OPSYS%%|${OPSYS}| ; \
		 s|%%PYTHON_SITELIBDIR%%|${PYTHON_SITELIBDIR}| ; \
		 s|%%PYTHON_VERSION%%|${PYTHON_VERSION}|' ${WRKDIR}/usr/bin/tribler

post-build:
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKDIR}/usr/share/tribler
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKDIR}/usr/share/tribler

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/usr/bin/tribler ${PREFIX}/bin
	@${MKDIR} ${TRIBLER_DIR}
	@(${TAR} -C ${WRKDIR}/usr/share/tribler/Tribler \
		--exclude "Build" \
		--exclude "LGPL-2.1.txt" \
		--exclude "readme.txt" \
		--exclude "*LICENSE*.txt" \
		--exclude "*.orig" \
		-cf - . | ${TAR} -C ${TRIBLER_DIR} -xf -)
	@${FIND} ${TRIBLER_DIR} -print0 | ${XARGS} -0 ${CHOWN} ${SHAREOWN}
	@${FIND} ${TRIBLER_DIR} -type f -print0 | ${XARGS} -0 ${CHMOD} ${SHAREMODE}
	@${FIND} ${TRIBLER_DIR} -type d -print0 | ${XARGS} -0 ${CHMOD} a+rx
	@${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKDIR}/usr/share/applications/tribler.desktop \
		${PREFIX}/share/applications
	@${MKDIR} ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKDIR}/usr/share/pixmaps/tribler.xpm \
		${PREFIX}/share/pixmaps
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/usr/share/tribler/Tribler/*LICENSE*.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/usr/share/tribler/Tribler/readme.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
