# $FreeBSD$

PORTNAME=	charlock_holmes
PORTVERSION=	0.6.9
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Gems for character encoding detection

LIB_DEPENDS=	icui18n:${PORTSDIR}/devel/icu

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
CONFIGURE_ARGS=	--with-icu-include=${LOCALBASE}/include
PLIST_FILES=	lib/ruby/gems/${RUBY_VER}/gems/charlock_holmes-${PORTVERSION}/ext/charlock_holmes/src/file-5.08/src/.libs/libmagic.la

NO_STAGE=	yes
.include <bsd.port.mk>
