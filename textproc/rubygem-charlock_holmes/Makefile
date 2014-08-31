# $FreeBSD$

PORTNAME=	charlock_holmes
PORTVERSION=	0.7.3
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Gems for character encoding detection

LIB_DEPENDS=	libicui18n.so:${PORTSDIR}/devel/icu

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
CONFIGURE_ARGS=	--with-icu-include=${LOCALBASE}/include

.include <bsd.port.mk>
