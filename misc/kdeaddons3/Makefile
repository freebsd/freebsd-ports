# New ports collection makefile for:	addons for kde
# Date created:				7 August 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	kdeaddons
PORTVERSION=	3.0
PORTREVISION=	1
CATEGORIES?=	misc kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER?=	ports@FreeBSD.org

LIB_DEPENDS+=	noatun.0:${PORTSDIR}/audio/kdemultimedia3 \
		SDL-1.1.3:${PORTSDIR}/devel/sdl12

WITH_SDL=	yes
USE_KDEBASE_VER=3
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GMAKE=	yes
PLIST_SUB+=	RM=${RM}
CONFIGURE_ENV+=	SDL_CONFIG="${LOCALBASE}/bin/sdl11-config"
CONFIGURE_ARGS=	--enable-objprelink
.if defined(PARALLEL_PACKAGE_BUILD) || defined(WANT_KDE_FINAL)
CONFIGURE_ARGS+=--enable-final
.endif
.if defined(PARALLEL_PACKAGE_BUILD) || defined(WANT_KDE_NDEBUG)
CONFIGURE_ARGS+=--disable-debug
.endif

post-configure:
	${FIND} ${WRKSRC} -type f | ${XARGS} ${PERL} -pi -e \
		"s@sdl-config@${SDL_CONFIG}@g"

.include <bsd.port.pre.mk>

.include <bsd.port.post.mk>
