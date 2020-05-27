# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rabbiter
PORTVERSION=	2.0.4
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Twitter client for Rabbit

LICENSE=	GPLv2+

RUN_DEPENDS=	rubygem-gio2>=2.1.1:devel/rubygem-gio2 \
		rubygem-rabbit>=2.0.0:misc/rubygem-rabbit \
		rubygem-twitter_oauth>0:security/rubygem-twitter_oauth \
		rubygem-twitter>0:net/rubygem-twitter

NO_ARCH=	yes
USES=		gem
USE_RUBY=	yes
PLIST_FILES=	bin/rabbiter

.include <bsd.port.mk>
