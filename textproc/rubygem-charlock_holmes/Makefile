# $FreeBSD$

PORTNAME=	charlock_holmes
DISTVERSION=	0.7.5
PORTREVISION=	1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

PATCH_SITES=	https://github.com/brianmario/charlock_holmes/commit/
PATCHFILES=	018be8532670.patch:-p1

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Gems for character encoding detection

LICENSE=	MIT

LIB_DEPENDS=	libicui18n.so:devel/icu \
		libunwind.so:devel/libunwind

USES=		gem
USE_RUBY=	yes

CONFIGURE_ARGS=	--with-icu-include=${LOCALBASE}/include

.include <bsd.port.mk>
