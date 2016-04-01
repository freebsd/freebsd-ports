# $FreeBSD$

PORTNAME=	psimedia
PORTVERSION=	1.0.3
PORTREVISION=	2
CATEGORIES=	net-im audio multimedia
MASTER_SITES=	http://delta.affinix.com/download/psimedia/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Voice and video API for Psi-like IM clients

LIB_DEPENDS=	liboil-0.3.so:devel/liboil \
		libspeexdsp.so:audio/speexdsp

USES=		pkgconfig tar:bzip2
HAS_CONFIGURE=	yes
USE_QT4=	gui qmake_build moc_build uic_build
USE_GSTREAMER=	jpeg speex theora vorbis

QT_NONSTANDARD=	yes
CONFIGURE_ARGS=	--qtdir=${LOCALBASE} \
		--verbose
DESTDIRNAME=	INSTALL_ROOT

PSI_PLUGIN_DIR=	lib/psi/plugins

OPTIONS_DEFINE=	DEBUG
OPTIONS_SUB=	yes
DEBUG_CONFIGURE_ON=	--debug
DEBUG_CONFIGURE_OFF=	--release

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${PSI_PLUGIN_DIR}
	${INSTALL_LIB} ${WRKSRC}/gstprovider/libgstprovider.so \
		${STAGEDIR}${PREFIX}/${PSI_PLUGIN_DIR}

do-install-DEBUG-on:
	${INSTALL_DATA} ${WRKSRC}/gstprovider/libgstprovider.so.debug \
		${STAGEDIR}${PREFIX}/${PSI_PLUGIN_DIR}

.include <bsd.port.mk>
