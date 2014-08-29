# Created by: alepulver
# $FreeBSD$

PORTNAME=	tribler
PORTVERSION=	6.0.3
PORTREVISION=	6
CATEGORIES=	net-p2p
#MASTER_SITES=	http://dl.tribler.org/
MASTER_SITES=	GENTOO/distfiles \
		GOOGLE_CODE:apsw
PROJECTHOST=	apsw
DISTFILES=	${PORTNAME}_${PORTVERSION}_all.deb \
		${APSW_DISTFILE}:apsw
EXTRACT_ONLY=	${PORTNAME}_${PORTVERSION}_all.deb

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Streaming capable P2P network client based on BitTorrent

LICENSE=	LGPL21 MIT
LICENSE_COMB=	multi

EXTRACT_DEPENDS=${UNZIP_CMD}:${PORTSDIR}/archivers/unzip
LIB_DEPENDS=	libevent.so:${PORTSDIR}/devel/libevent2 \
		libvlc.so:${PORTSDIR}/multimedia/vlc
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}netifaces>0:${PORTSDIR}/net/py-netifaces \
		${PYTHON_PKGNAMEPREFIX}m2crypto>0:${PORTSDIR}/security/py-m2crypto \
		${PYTHON_PKGNAMEPREFIX}feedparser>0:${PORTSDIR}/textproc/py-feedparser

WRKSRC=		${WRKDIR}/${APSW_DISTNAME}

USES=		python:2
USE_PYTHON=	distutils
PYDISTUTILS_EGGINFO=	${APSW_DISTNAME:S/-r/_r/}-py${PYTHON_VER}.egg-info
USE_WX=		3.0
WX_COMPS=	python
WX_UNICODE=	yes

USE_SQLITE=	3

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

TRIBLER_DIR=	${PYTHONPREFIX_SITELIBDIR}/tribler

APSW_DISTNAME=	apsw-3.7.14.1-r1
APSW_DISTFILE=	${APSW_DISTNAME}.zip

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-extract:
	@(${GZCAT} ${WRKDIR}/data.tar.gz | ${TAR} -C ${WRKDIR} -xf -)
	@(${UNZIP_CMD} -qo ${DISTDIR}/${APSW_DISTFILE} -d ${WRKDIR})

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|/bin/netstat|netstat|' \
		${WRKDIR}/usr/share/tribler/Tribler/Core/NATFirewall/guessip.py
	@${REINPLACE_CMD} -i '' -e 's|^from Tribler.Main.Utility.Feeds ||' \
		${WRKDIR}/usr/share/tribler/Tribler/Main/Utility/Feeds/rssparser.py
	@${REINPLACE_CMD} -e 's|%%OPSYS%%|${OPSYS}| ; \
		 s|%%PYTHON_SITELIBDIR%%|${PYTHON_SITELIBDIR}| ; \
		 s|%%PYTHON_VERSION%%|${PYTHON_VERSION}|' ${WRKDIR}/usr/bin/tribler
	@${REINPLACE_CMD} -e 's|-O2|| ; \
		 s|CPPFLAGS|CXXFLAGS| ; \
		 s|-g -I$${LIBEVENT_HOME}/include|-I$${LOCALBASE}/include| ; \
		 s|-lstdc++|| ; \
		 s|g++|$${CXX}| ; \
		 s|$${LIBEVENT_HOME}/lib|$${LOCALBASE}/lib|g' \
		${WRKDIR}/usr/share/tribler/Tribler/SwiftEngine/Makefile
	@${REINPLACE_CMD} 's|linux|freebsd|' \
		${WRKDIR}/usr/share/tribler/Tribler/vlc.py

post-build:
	@(cd ${WRKDIR}/usr/share/tribler/Tribler/SwiftEngine \
		&& ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} \
			${ALL_TARGET})
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKDIR}/usr/share/tribler
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKDIR}/usr/share/tribler

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/usr/bin/tribler ${STAGEDIR}${PREFIX}/bin
	(cd ${WRKDIR}/usr/share/tribler/Tribler/SwiftEngine \
		&& ${INSTALL_PROGRAM} swift ${STAGEDIR}${PREFIX}/libexec)
	@${MKDIR} ${STAGEDIR}${TRIBLER_DIR}/Tribler
	@${LN} -sf ${PREFIX}/libexec/swift ${STAGEDIR}${TRIBLER_DIR}
	@(${TAR} -C ${WRKDIR}/usr/share/tribler/Tribler \
		--exclude "Build" \
		--exclude "LGPL-2.1.txt" \
		--exclude "SwiftEngine" \
		--exclude "feedparset.*" \
		--exclude "readme.txt" \
		--exclude "*LICENSE*.txt" \
		--exclude "*.orig" \
		-cf - . | ${TAR} -C ${STAGEDIR}${TRIBLER_DIR}/Tribler -xf -)
	@${FIND} ${STAGEDIR}${TRIBLER_DIR}/Tribler -type f -print0 | \
		${XARGS} -0 ${CHMOD} ${SHAREMODE}
	@${FIND} ${STAGEDIR}${TRIBLER_DIR}/Tribler -type d -print0 | \
		${XARGS} -0 ${CHMOD} a+rx
	@${MKDIR} ${STAGEDIR}${DESKTOPDIR}
	(cd ${WRKDIR}/usr/share/applications \
		&& ${INSTALL_DATA} tribler.desktop ${STAGEDIR}${DESKTOPDIR})
	(cd ${WRKDIR}/usr/share/pixmaps \
		&& ${INSTALL_DATA} tribler.xpm ${STAGEDIR}${PREFIX}/share/pixmaps)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKDIR}/usr/share/tribler/Tribler \
		&& ${INSTALL_DATA} *LICENSE*.txt readme.txt ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
