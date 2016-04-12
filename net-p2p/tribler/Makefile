# Created by: alepulver
# $FreeBSD$

PORTNAME=	tribler
PORTVERSION=	6.4.3
PORTREVISION=	2
CATEGORIES=	net-p2p
MASTER_SITES=	https://github.com/Tribler/tribler/releases/download/${PORTVERSION:S/^/v/}/
DISTFILES=	${PORTNAME}_${PORTVERSION}_all.deb

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Streaming capable P2P network client based on BitTorrent

LICENSE=	LGPL21 MIT
LICENSE_COMB=	multi

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}apsw>0:databases/py-apsw \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}pyasn1>=0.1.7:devel/py-pyasn1 \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow \
		${PYTHON_PKGNAMEPREFIX}gmpy>0:math/py-gmpy \
		${PYTHON_PKGNAMEPREFIX}netifaces>0:net/py-netifaces \
		${PYTHON_PKGNAMEPREFIX}libtorrent-rasterbar>=0.16.4:net-p2p/libtorrent-rasterbar-python \
		${PYTHON_PKGNAMEPREFIX}m2crypto>0:security/py-m2crypto \
		${PYTHON_PKGNAMEPREFIX}pycrypto>0:security/py-pycrypto \
		${PYTHON_PKGNAMEPREFIX}feedparser>0:textproc/py-feedparser \
		${PYTHON_PKGNAMEPREFIX}cherrypy>0:www/py-cherrypy \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

USES=		desktop-file-utils python:2 shebangfix twisted:run
SHEBANG_FILES=	usr/share/tribler/Tribler/Core/DecentralizedTracking/pymdht/*.py \
		usr/share/tribler/Tribler/Core/DecentralizedTracking/pymdht/*/*.py \
		usr/share/tribler/Tribler/Debug/memory.py \
		usr/share/tribler/Tribler/Main/*.py \
		usr/share/tribler/Tribler/dispersy/*/*.py \
		usr/share/tribler/Tribler/vlc.py
USE_OPENSSL=	yes
USE_PYTHON=	run
USE_WX=		2.8
WX_COMPS=	python

CFLAGS+=	-D__STDC_LIMIT_MACROS=1
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=		DOCS VLC
OPTIONS_DEFAULT=	VLC

VLC_DESC=		Multimedia support via VLC
VLC_RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg \
			vlc:multimedia/vlc

TRIBLER_DIR=	${PYTHONPREFIX_SITELIBDIR}/tribler

post-extract:
	@(cd ${WRKSRC} && ${TAR} -xf data.tar.xz)

post-patch:
	@${REINPLACE_CMD} -e \
		's|%%OPSYS%%|${OPSYS}| ; \
		 s|%%PYTHON_SITELIBDIR%%|${PYTHON_SITELIBDIR}| ; \
		 s|%%PYTHON_VERSION%%|${PYTHON_VERSION}|' \
		${WRKSRC}/usr/bin/tribler
	@${REINPLACE_CMD} -e \
		's|Application;|| ; \
		 /^Categories/s|$$|;| ; \
		 /^MimeType/s|$$|;|' \
		${WRKSRC}/usr/share/applications/tribler.desktop
	@${REINPLACE_CMD} -i '' -e \
		's|linux|${OPSYS:tl}|' \
		${WRKSRC}/usr/share/tribler/Tribler/vlc.py

do-install:
	(cd ${WRKSRC}/usr/bin && ${INSTALL_SCRIPT} tribler \
		${STAGEDIR}${PREFIX}/bin)
	@${MKDIR} ${STAGEDIR}${TRIBLER_DIR}/Tribler
	@(${TAR} -C ${WRKSRC}/usr/share/tribler/Tribler \
		--exclude "Build" \
		--exclude "LGPL-2.1.txt" \
		--exclude "SwiftEngine" \
		--exclude "readme.txt" \
		--exclude "*LICENSE*.txt" \
		--exclude "*.orig" \
		-cf - . | ${TAR} -C ${STAGEDIR}${TRIBLER_DIR}/Tribler -xf -)
	@${FIND} ${STAGEDIR}${TRIBLER_DIR}/Tribler -type f -print0 | \
		${XARGS} -0 ${CHMOD} ${SHAREMODE}
	@${FIND} ${STAGEDIR}${TRIBLER_DIR}/Tribler -type d -print0 | \
		${XARGS} -0 ${CHMOD} a+rx
	@${MKDIR} ${STAGEDIR}${DESKTOPDIR}
	(cd ${WRKSRC}/usr/share/applications && ${INSTALL_DATA} \
		*.desktop ${STAGEDIR}${PREFIX}/share/applications)
	(cd ${WRKSRC}/usr/share/pixmaps && ${INSTALL_DATA} \
		*.xpm ${STAGEDIR}${PREFIX}/share/pixmaps)
	@(cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} -m compileall \
		-d ${PYTHONPREFIX_SITELIBDIR} \
		-f ${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;})
	@(cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} -O -m compileall \
		-d ${PYTHONPREFIX_SITELIBDIR} \
		-f ${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;})

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/usr/share/tribler/Tribler && ${INSTALL_DATA} \
		*LICENSE*.txt readme.txt ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
