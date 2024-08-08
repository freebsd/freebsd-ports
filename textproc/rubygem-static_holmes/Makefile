PORTNAME=	static_holmes
DISTVERSION=	0.7.11
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Gems for character encoding detection
WWW=		https://gitlab.com/gitlab-org/ruby/gems/charlock_holmes

LICENSE=	MIT

LIB_DEPENDS=	libicui18n.so:devel/icu

USES=		gem

CONFIGURE_ARGS=	--with-icu-include=${LOCALBASE}/include

.include <bsd.port.mk>
