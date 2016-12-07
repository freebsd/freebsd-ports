# Created by: Jonathan Weiss (<jw@innerewut.de>)
# $FreeBSD$

PORTNAME=	actionmailer
PORTVERSION=	3.2.22.2
CATEGORIES=	mail rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Easy email delivery and testing for Ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack>=${PORTVERSION}:www/rubygem-actionpack \
		rubygem-mail25>=2.5.4:mail/rubygem-mail25

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

DEPRECATED=	Upstream support ended
EXPIRATION_DATE=	2017-01-07

.include <bsd.port.mk>
