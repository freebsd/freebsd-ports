# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	activestorage
PORTVERSION=	7.0.1
CATEGORIES=	net rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	70

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Attach cloud and local files in Rails applications

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack70>=${PORTVERSION}:www/rubygem-actionpack70 \
		rubygem-activejob70>=${PORTVERSION}:devel/rubygem-activejob70 \
		rubygem-activerecord70>=${PORTVERSION}:databases/rubygem-activerecord70 \
		rubygem-activesupport70>=${PORTVERSION}:devel/rubygem-activesupport70 \
		rubygem-marcel>=1.0<2:devel/rubygem-marcel \
		rubygem-mini_mime>=1.1.0:mail/rubygem-mini_mime

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^7\.0\.

.include <bsd.port.mk>
