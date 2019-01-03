# Created by: alepulver
# $FreeBSD$

PORTNAME=	tribler
PORTVERSION=	6.5.2
PORTREVISION=	13
CATEGORIES=	net-p2p
MASTER_SITES=	https://github.com/Tribler/tribler/releases/download/v${PORTVERSION}/
DISTNAME=	Tribler-v${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Streaming capable P2P network client based on BitTorrent

LICENSE=	LGPL21 MIT
LICENSE_COMB=	multi

BUILD_DEPENDS=	xpmtoppm:graphics/netpbm
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}apsw>0:databases/py-apsw@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}leveldb>0:databases/py-leveldb@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}decorator>0:devel/py-decorator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gmpy>0:math/py-gmpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netifaces>0:net/py-netifaces@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libtorrent-rasterbar>=0.16.4:net-p2p/py-libtorrent-rasterbar@${PY_FLAVOR} \
		libsodium>0:security/libsodium \
		${PYTHON_PKGNAMEPREFIX}m2crypto>0:security/py-m2crypto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycrypto>0:security/py-pycrypto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}feedparser>0:textproc/py-feedparser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cherrypy>0:www/py-cherrypy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}twisted>=0:devel/py-twisted@${PY_FLAVOR}

NO_ARCH=	yes
NO_WRKSUBDIR=	yes

USES=		desktop-file-utils python:2.7,run ssl:run tar:xz
USE_WX=		2.8
WX_COMPS=	python
INSTALLS_ICONS=	yes

SUB_FILES=	tribler
SUB_LIST=	PYTHON_SITELIBDIR="${PYTHON_SITELIBDIR}" \
		PYTHON_VERSION="${PYTHON_VERSION}"

OPTIONS_DEFINE=		DOCS VLC
OPTIONS_DEFAULT=	VLC

VLC_DESC=		Multimedia support via VLC
VLC_RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg \
			vlc:multimedia/vlc

post-patch:
	@${REINPLACE_CMD} -e \
		's|Application;|| ; \
		 /^Categories/s|$$|;| ; \
		 /^MimeType/s|$$|;|' \
		${WRKSRC}/tribler/Tribler/Main/Build/Ubuntu/tribler.desktop
	@${REINPLACE_CMD} -e \
		's|linux|${OPSYS:tl}|' \
		${WRKSRC}/tribler/Tribler/vlc.py

do-build:
	@${MKDIR} ${WRKDIR}/icons/hicolor/32x32/apps
	(cd ${WRKDIR} && xpmtoppm --alphaout=tribler.pgm \
		${WRKSRC}/tribler/Tribler/Main/Build/Ubuntu/tribler.xpm \
		> tribler.ppm)
	(cd ${WRKDIR} && pnmtopng -alpha=tribler.pgm tribler.ppm \
		> ${WRKDIR}/icons/hicolor/32x32/apps/tribler.png)
	@${MKDIR} ${WRKDIR}/icons/hicolor/48x48/apps
	(cd ${WRKDIR} && xpmtoppm --alphaout=tribler_big.pgm \
		${WRKSRC}/tribler/Tribler/Main/Build/Ubuntu/tribler_big.xpm \
		> tribler_big.ppm)
	(cd ${WRKDIR} && pnmtopng -alpha=tribler_big.pgm tribler_big.ppm \
		> ${WRKDIR}/icons/hicolor/48x48/apps/tribler.png)

do-install:
	(cd ${WRKDIR} && ${INSTALL_SCRIPT} tribler \
		${STAGEDIR}${PREFIX}/bin)
	@${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/tribler
	(cd ${WRKSRC}/tribler && ${INSTALL_DATA} logger.conf \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/tribler)
	@(cd ${WRKSRC}/tribler/Tribler && ${COPYTREE_SHARE} \
		"Category Core Test Utilities community dispersy" \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/tribler/Tribler)
	@(cd ${WRKSRC}/tribler/Tribler/Main && ${COPYTREE_SHARE} "[^B]*" \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/tribler/Tribler/Main)
	(cd ${WRKSRC}/tribler/Tribler && ${INSTALL_DATA} *.sql *.py \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/tribler/Tribler)
	(cd ${WRKSRC}/tribler/Tribler/Main/Build/Ubuntu && ${INSTALL_MAN} \
		tribler.1 ${STAGEDIR}${MANPREFIX}/man/man1)
	(cd ${WRKSRC}/tribler/Tribler/Main/Build/Ubuntu && ${INSTALL_DATA} \
		tribler.desktop ${STAGEDIR}${PREFIX}/share/applications)
	@(cd ${WRKDIR} && ${COPYTREE_SHARE} icons \
		${STAGEDIR}${PREFIX}/share)
	@(cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} -m compileall \
		-d ${PYTHONPREFIX_SITELIBDIR} \
		-f ${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;})
	@(cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} -O -m compileall \
		-d ${PYTHONPREFIX_SITELIBDIR} \
		-f ${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;})

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/tribler/Tribler/*.txt \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
