# $FreeBSD$

PORTNAME=	psimedia
PORTVERSION=	1.0.3
PORTREVISION=	1
CATEGORIES=	net-im audio multimedia
MASTER_SITES=	http://delta.affinix.com/download/psimedia/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Voice and video API for Psi-like IM clients

LIB_DEPENDS=	liboil-0.3.so:${PORTSDIR}/devel/liboil \
		libspeexdsp.so:${PORTSDIR}/audio/speex

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

.include <bsd.port.options.mk>

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${PSI_PLUGIN_DIR}
	${INSTALL_LIB} ${WRKSRC}/gstprovider/libgstprovider.so \
		${STAGEDIR}${PREFIX}/${PSI_PLUGIN_DIR}
.if ${PORT_OPTIONS:MDEBUG}
	${INSTALL_DATA} ${WRKSRC}/gstprovider/libgstprovider.so.debug \
		${STAGEDIR}${PREFIX}/${PSI_PLUGIN_DIR}
.endif

.include <bsd.port.mk>
