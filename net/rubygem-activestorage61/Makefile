# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	activestorage
PORTVERSION=	6.1.4.6
CATEGORIES=	net rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	61

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Attach cloud and local files in Rails applications

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack61>=${PORTVERSION}:www/rubygem-actionpack61 \
		rubygem-activejob61>=${PORTVERSION}:devel/rubygem-activejob61 \
		rubygem-activerecord61>=${PORTVERSION}:databases/rubygem-activerecord61 \
		rubygem-activesupport61>=${PORTVERSION}:devel/rubygem-activesupport61 \
		rubygem-marcel>=1.0.0<1.1:devel/rubygem-marcel \
		rubygem-mini_mime>=1.1.0:mail/rubygem-mini_mime

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^6\.1\.

.include <bsd.port.mk>
