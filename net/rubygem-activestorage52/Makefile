# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	activestorage
PORTVERSION=	5.2.4
CATEGORIES=	net rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	52

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Attach cloud and local files in Rails applications

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack52>=${PORTVERSION}:www/rubygem-actionpack52 \
		rubygem-activerecord52>=${PORTVERSION}:databases/rubygem-activerecord52 \
		rubygem-marcel>=0.3.1<0.4:devel/rubygem-marcel

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^5\.2\.

.include <bsd.port.mk>
