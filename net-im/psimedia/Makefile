# $FreeBSD$

PORTNAME=	psimedia
PORTVERSION=	1.0.3
PORTREVISION=	1
CATEGORIES=	net-im audio multimedia
MASTER_SITES=	http://delta.affinix.com/download/psimedia/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Voice and video API for Psi-like IM clients

LIB_DEPENDS=	liboil-0.3.so:${PORTSDIR}/devel/liboil

USES=		pkgconfig
USE_BZIP2=	yes
HAS_CONFIGURE=	yes
USE_QT4=	gui qmake_build moc_build uic_build
USE_GSTREAMER=	jpeg speex theora vorbis

QT_NONSTANDARD=	yes
CONFIGURE_ARGS=	--qtdir=${LOCALBASE} \
		--verbose
MAKE_JOBS_UNSAFE=	yes
DESTDIRNAME=	INSTALL_ROOT

PSI_PLUGIN_DIR=	lib/psi/plugins

.if !defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--release
PLIST_SUB+=	DEBUG="@comment "
.else
CONFIGURE_ARGS+=	--debug
PLIST_SUB+=	DEBUG=""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|glib/.*\.h>|glib.h>|g' \
		${WRKSRC}/gstprovider/rwcontrol.h \
		${WRKSRC}/gstprovider/gstthread.h \
		${WRKSRC}/gstprovider/gstelements/static/gstelements.h \
		${WRKSRC}/gstprovider/gstcustomelements/gstcustomelements.h	

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${PSI_PLUGIN_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/gstprovider/libgstprovider.so \
		${STAGEDIR}${PREFIX}/${PSI_PLUGIN_DIR}
.if defined(WITH_DEBUG)
	${INSTALL_DATA} ${WRKSRC}/gstprovider/libgstprovider.so.debug \
		${STAGEDIR}${PREFIX}/${PSI_PLUGIN_DIR}
.endif

.include <bsd.port.mk>
