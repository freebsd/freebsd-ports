# Created by: rene@FreeBSD.org
# $FreeBSD$

PORTNAME=	SpotifyWebsocketAPI
PORTVERSION=	0.2
PORTREVISION=	6
CATEGORIES=	multimedia python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Websocket API and client for Spotify

NO_ARCH=	yes

USE_GITHUB=	yes
GH_COMMIT=	08ee326
GH_ACCOUNT=	Hexxeh
GH_PROJECT=	spotify-websocket-api
GH_TAGNAME=	${GH_COMMIT}

USE_PYTHON=	yes # tested with 2.7
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options
OPTIONS_DEFINE=	EXAMPLES

PORTEXAMPLES=	blocking.py nonblocking.py decode_mercury.py play.py \
		serve.py ctype.py gstreamer.py

CLIENTFILES=	respotify.py respotify-helper.py

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=1.1.0:${PORTSDIR}/www/py-requests \
		${PYTHON_PKGNAMEPREFIX}ws4py>=0.2.4:${PORTSDIR}/www/py-ws4py \
		${PYTHON_PKGNAMEPREFIX}protobuf>=2.4.1:${PORTSDIR}/devel/py-protobuf \
		${PYTHON_PKGNAMEPREFIX}lxml>=3.1:${PORTSDIR}/devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}mpd2>=0:${PORTSDIR}/audio/py-mpd2 \
		musicpd:${PORTSDIR}/audio/musicpd

EXAMPLES_LIB_DEPENDS=libao.so:${PORTSDIR}/audio/libao \
	libmpg123.so:${PORTSDIR}/audio/mpg123
EXAMPLES_RUN_DEPENDS=${PYTHON_PKGNAMEPREFIX}curl>=0:${PORTSDIR}/ftp/py-curl \
	${PYTHON_PKGNAMEPREFIX}gobject>=0:${PORTSDIR}/devel/py-gobject
EXAMPLES_USE=	GSTREAMER=python

post-patch:
	${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|" \
		${WRKSRC}/clients/respotify/respotify.py

post-install:
.for f in ${CLIENTFILES}
	@${INSTALL_SCRIPT} ${WRKSRC}/clients/respotify/${f} ${STAGEDIR}${PREFIX}/bin
	@${PYTHON_CMD} -O -mcompileall ${STAGEDIR}${PREFIX}/bin/${f}
	@${PYTHON_CMD} -mcompileall ${STAGEDIR}${PREFIX}/bin/${f}
.endfor
	@${LN} -s ${PREFIX}/bin/respotify.py ${STAGEDIR}${PREFIX}/bin/respotify

	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for f in ${PORTEXAMPLES}
	@${INSTALL_SCRIPT} ${WRKSRC}/examples/${f} ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
