# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	activestorage
PORTVERSION=	6.1.3
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
		rubygem-marcel>=0.3.1<0.4:devel/rubygem-marcel \
		rubygem-mimemagic>=0.3.2<0.4:misc/rubygem-mimemagic

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^6\.1\.

.include <bsd.port.mk>
