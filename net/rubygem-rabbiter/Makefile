# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rabbiter
PORTVERSION=	2.0.1
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Rabbiter is a twitter client for Rabbit

LICENSE=	GPLv2+

RUN_DEPENDS=	rubygem-gio2>=1.1.4:devel/rubygem-gio2 \
		rubygem-rabbit>=2.0.0:misc/rubygem-rabbit \
		rubygem-twitter_oauth>0:security/rubygem-twitter_oauth \
		rubygem-twitter-stream>=0.1.16:net/rubygem-twitter-stream

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem
PLIST_FILES=	bin/rabbiter

.include <bsd.port.mk>
