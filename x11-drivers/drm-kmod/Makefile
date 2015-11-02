# Created by: Jean-Sebastien Pedron <dumbbell@FreeBSD.org>
# $FreeBSD$

PORTNAME=	drm-kmod
DISTVERSION=	9.280208
CATEGORIES=	x11-drivers
MASTER_SITES=	LOCAL/dumbbell
DISTNAME=	drm-${DISTVERSION}

MAINTAINER=	x11@FreeBSD.org
COMMENT=	FreeBSD 9.3 Kernel DRM driver

LICENSE=	MIT

USES=		kmod uidfix tar:xz
ONLY_FOR_ARCHS=	i386 amd64

PLIST_FILES=	${KMODDIR}/drm2_port.ko \
		${KMODDIR}/i915kms_port.ko \
		${KMODDIR}/radeonkms_port.ko \

.include <bsd.port.options.mk>

.if (${OSVERSION} < 903000 || ${OSVERSION} > 1000000)
IGNORE=		this port is only for 9.3 systems
.endif

.if ${PORT_OPTIONS:MDEBUG}
MAKE_ARGS+=" HAVE_DEBUG=YES"
.endif

.include <bsd.port.mk>
