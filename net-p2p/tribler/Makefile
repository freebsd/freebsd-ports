# Created by: alepulver
# $FreeBSD$

PORTNAME=	tribler
PORTVERSION=	6.3.3
CATEGORIES=	net-p2p
MASTER_SITES=	GH \
		https://github.com/Tribler/tribler/releases/download/${PORTVERSION:S/^/v/}/:tribler
DISTFILES=	${GH_ACCOUNT}-${GH_PROJECT}-${GH_COMMIT}${EXTRACT_SUFX} \
		${PORTNAME}_${PORTVERSION}_all.deb:tribler

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Streaming capable P2P network client based on BitTorrent

LICENSE=	LGPL21 MIT
LICENSE_COMB=	multi

LIB_DEPENDS=	libevent.so:${PORTSDIR}/devel/libevent2
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}apsw>0:${PORTSDIR}/databases/py-apsw \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}asn1>0:${PORTSDIR}/devel/py-asn1 \
		${PYTHON_PKGNAMEPREFIX}gmpy>0:${PORTSDIR}/math/py-gmpy \
		${PYTHON_PKGNAMEPREFIX}netifaces>0:${PORTSDIR}/net/py-netifaces \
		${PYTHON_PKGNAMEPREFIX}libtorrent-rasterbar>0:${PORTSDIR}/net-p2p/libtorrent-rasterbar-python \
		${PYTHON_PKGNAMEPREFIX}m2crypto>0:${PORTSDIR}/security/py-m2crypto \
		${PYTHON_PKGNAMEPREFIX}pycrypto>0:${PORTSDIR}/security/py-pycrypto \
		${PYTHON_PKGNAMEPREFIX}feedparser>0:${PORTSDIR}/textproc/py-feedparser

USE_GITHUB=	yes
GH_ACCOUNT=	LipuFei
GH_PROJECT=	libswift
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	01745ce

USES=		desktop-file-utils gmake python:2 shebangfix twisted:run
SHEBANG_FILES=	../usr/share/tribler/Tribler/Core/DecentralizedTracking/pymdht/*.py \
		../usr/share/tribler/Tribler/Core/DecentralizedTracking/pymdht/*/*.py \
		../usr/share/tribler/Tribler/Debug/memory.py \
		../usr/share/tribler/Tribler/Main/*.py \
		../usr/share/tribler/Tribler/dispersy/*/*.py \
		../usr/share/tribler/Tribler/vlc.py
USE_WX=		2.8+
WX_COMPS=	python
WX_UNICODE=	yes
USE_OPENSSL=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=		DOCS VLC
OPTIONS_DEFAULT=	VLC

VLC_DESC=		Multimedia support via VLC
VLC_RUN_DEPENDS=	ffmpeg:${PORTSDIR}/multimedia/ffmpeg \
			vlc:${PORTSDIR}/multimedia/vlc

TRIBLER_DIR=	${PYTHONPREFIX_SITELIBDIR}/tribler

post-extract:
	@${TAR} -C ${WRKDIR} -xf ${WRKDIR}/data.tar.gz

post-patch:
	@${REINPLACE_CMD} -e \
		's|-O2|$${CXXFLAGS}| ; \
		 s|-g|| ; \
		 s|-lstdc++|| ; \
		 s|g++|$${CXX}|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e \
		's|%%OPSYS%%|${OPSYS}| ; \
		 s|%%PYTHON_SITELIBDIR%%|${PYTHON_SITELIBDIR}| ; \
		 s|%%PYTHON_VERSION%%|${PYTHON_VERSION}|' \
		${WRKDIR}/usr/bin/tribler
	@${REINPLACE_CMD} -e \
		's|Application;|| ; \
		 /^Categories/s|$$|;| ; \
		 /^MimeType/s|$$|;|' \
		${WRKDIR}/usr/share/applications/tribler.desktop
	@${REINPLACE_CMD} -i '' -e \
		's|linux|${OPSYS:tl}|' \
		${WRKDIR}/usr/share/tribler/Tribler/vlc.py

do-install:
	@${MKDIR} ${STAGEDIR}${TRIBLER_DIR}/Tribler \
		${STAGEDIR}${DESKTOPDIR} \
		${STAGEDIR}${DOCSDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/swift ${STAGEDIR}${PREFIX}/libexec
	${INSTALL_SCRIPT} ${WRKDIR}/usr/bin/tribler ${STAGEDIR}${PREFIX}/bin
	${LN} -sf ${PREFIX}/libexec/swift ${STAGEDIR}${TRIBLER_DIR}
	(${TAR} -C ${WRKDIR}/usr/share/tribler/Tribler \
		--exclude "Build" \
		--exclude "LGPL-2.1.txt" \
		--exclude "SwiftEngine" \
		--exclude "readme.txt" \
		--exclude "*LICENSE*.txt" \
		--exclude "*.orig" \
		-cf - . | ${TAR} -C ${STAGEDIR}${TRIBLER_DIR}/Tribler -xf -)
	${FIND} ${STAGEDIR}${TRIBLER_DIR}/Tribler -type f -print0 | \
		${XARGS} -0 ${CHMOD} ${SHAREMODE}
	${FIND} ${STAGEDIR}${TRIBLER_DIR}/Tribler -type d -print0 | \
		${XARGS} -0 ${CHMOD} a+rx
	(cd ${WRKDIR}/usr/share/applications && ${INSTALL_DATA} \
		tribler.desktop ${STAGEDIR}${DESKTOPDIR})
	(cd ${WRKDIR}/usr/share/pixmaps && ${INSTALL_DATA} \
		tribler.xpm ${STAGEDIR}${PREFIX}/share/pixmaps)
	(cd ${WRKDIR}/usr/share/tribler/Tribler && ${INSTALL_DATA} \
		*LICENSE*.txt readme.txt ${STAGEDIR}${DOCSDIR})
	(cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} -m compileall \
		-d ${PYTHONPREFIX_SITELIBDIR} \
		-f ${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;})
	(cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} -O -m compileall \
		-d ${PYTHONPREFIX_SITELIBDIR} \
		-f ${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;})

.include <bsd.port.mk>
