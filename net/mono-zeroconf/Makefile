# New ports collection makefile for:	mono-zeroconf
# Date created:				Aug 27 2008
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mono-zeroconf
PORTVERSION=	0.9.0
CATEGORIES=	net
MASTER_SITES=	http://download.banshee-project.org/${PORTNAME}/

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Cross platform Zero Configuration Networking library for Mono

BUILD_DEPENDS=	mono:${PORTSDIR}/lang/mono \
		${LOCALBASE}/libdata/pkgconfig/avahi-sharp.pc:${PORTSDIR}/net/avahi-sharp
RUN_DEPENDS=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	pkgconfig gnomehack
CONFIGURE_ARGS+=	--program-transform-name="" \
			--disable-mdnsresponder

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"

.if defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--disable-docs
.else
CONFIGURE_ARGS+=	--enable-docs
#BUILD_DEPENDS+=	${LOCALBASE}/bin/monodocer:${PORTSDIR}/devel/monodoc
.endif

.include <bsd.port.post.mk>
