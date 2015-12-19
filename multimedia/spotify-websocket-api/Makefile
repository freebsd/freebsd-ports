# Created by: rene@FreeBSD.org
# $FreeBSD$

PORTNAME=	SpotifyWebsocketAPI
PORTVERSION=	0.2
PORTREVISION=	13
CATEGORIES=	multimedia python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Websocket API and client for Spotify

IGNORE=		login fails due to protocol changes
DEPRECATED=	${IGNORE}
EXPIRATION_DATE=2016-01-01

NO_ARCH=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	Hexxeh
GH_PROJECT=	spotify-websocket-api
GH_TAGNAME=	d397ed2

USES=		python shebangfix
SHEBANG_FILES=	spotify_web/spotify.py ${CLIENTFILES}
USE_PYTHON=	autoplist concurrent distutils

OPTIONS_DEFINE=	EXAMPLES

PORTEXAMPLES=	blocking.py nonblocking.py decode_mercury.py play.py \
		serve.py ctype.py gstreamer.py

CLIENTFILES=	clients/respotify/respotify.py \
		clients/respotify/respotify-helper.py

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests1>=1.1.0:${PORTSDIR}/www/py-requests1 \
		${PYTHON_PKGNAMEPREFIX}ws4py>=0.2.4:${PORTSDIR}/www/py-ws4py \
		${PYTHON_PKGNAMEPREFIX}protobuf>=2.4.1:${PORTSDIR}/devel/py-protobuf \
		${PYTHON_PKGNAMEPREFIX}lxml>=3.1:${PORTSDIR}/devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}mpd2>=0:${PORTSDIR}/audio/py-mpd2 \
		musicpd:${PORTSDIR}/audio/musicpd

EXAMPLES_LIB_DEPENDS=libao.so:${PORTSDIR}/audio/libao \
	libmpg123.so:${PORTSDIR}/audio/mpg123
EXAMPLES_RUN_DEPENDS=${PYTHON_PKGNAMEPREFIX}pycurl>=0:${PORTSDIR}/ftp/py-pycurl \
	${PYTHON_PKGNAMEPREFIX}gobject>=0:${PORTSDIR}/devel/py-gobject
EXAMPLES_USE=	GSTREAMER=python

PLIST_FILES=	bin/respotify bin/respotify-helper.py bin/respotify.py

post-patch:
	${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|" \
		${WRKSRC}/clients/respotify/respotify.py

post-install:
.for f in ${CLIENTFILES}
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
.endfor
	${LN} -s ${PREFIX}/bin/respotify.py ${STAGEDIR}${PREFIX}/bin/respotify

	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for f in ${PORTEXAMPLES}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/${f} ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
