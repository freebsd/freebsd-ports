# New ports collection makefile for:	psimedia
# Date created:		2009-08-10
# Whom:			Max Brazhnikov <makc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	psimedia
PORTVERSION=	1.0.3
CATEGORIES=	net-im audio multimedia
MASTER_SITES=	http://delta.affinix.com/download/psimedia/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Voice and video API for Psi-like IM clients

LIB_DEPENDS=	oil-0.3:${PORTSDIR}/devel/liboil

USE_BZIP2=	yes
HAS_CONFIGURE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui qmake_build moc_build uic_build
USE_GSTREAMER=	jpeg speex theora vorbis

QT_NONSTANDARD=	yes
CONFIGURE_ARGS=	--qtdir=${LOCALBASE} \
		--verbose
MAKE_JOBS_UNSAFE=	yes

PSI_PLUGIN_DIR=	lib/psi/plugins

.if !defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--release
PLIST_SUB+=	DEBUG="@comment "
.else
CONFIGURE_ARGS+=	--debug
PLIST_SUB+=	DEBUG=""
.endif

do-install:
	${MKDIR} ${PREFIX}/${PSI_PLUGIN_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/gstprovider/libgstprovider.so \
		${PREFIX}/${PSI_PLUGIN_DIR}
.if defined(WITH_DEBUG)
	${INSTALL_DATA} ${WRKSRC}/gstprovider/libgstprovider.so.debug \
		${PREFIX}/${PSI_PLUGIN_DIR}
.endif

.include <bsd.port.mk>
