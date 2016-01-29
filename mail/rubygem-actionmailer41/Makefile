# Created by: Torsten Zuhlsdorff <ports@toco-domains.de>
# $FreeBSD$

PORTNAME=	actionmailer
PORTVERSION=	4.1.14
CATEGORIES=	mail rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	41

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Easy email delivery and testing for Ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

DEPRECATED=	Rails 4.1 is no longer supported - please switch to Rails 4.2
EXPIRATION_DATE=	2016-03-31

RUN_DEPENDS=	rubygem-actionpack41>=${PORTVERSION}:${PORTSDIR}/www/rubygem-actionpack41 \
		rubygem-actionview41>=${PORTVERSION}:${PORTSDIR}/devel/rubygem-actionview41 \
		rubygem-mail>=2.5.4:${PORTSDIR}/mail/rubygem-mail

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PORTSCOUT=	limit:^4\.1

.include <bsd.port.mk>
