# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	activestorage
PORTVERSION=	6.0.3.1
CATEGORIES=	net rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	60

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Attach cloud and local files in Rails applications

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack60>=${PORTVERSION}:www/rubygem-actionpack60 \
		rubygem-activejob60>=${PORTVERSION}:devel/rubygem-activejob60 \
		rubygem-activerecord60>=${PORTVERSION}:databases/rubygem-activerecord60 \
		rubygem-marcel>=0.3.1<0.4:devel/rubygem-marcel

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^6\.0\.

.include <bsd.port.mk>
