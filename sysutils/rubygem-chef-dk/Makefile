# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	chef-dk
PORTVERSION=	2.5.13
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Systems integration framework. Development Kit

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-addressable25>=2.3.5<2.6:www/rubygem-addressable25 \
		rubygem-chef>=13.0:sysutils/rubygem-chef \
		rubygem-chef-provisioning>=2.0:devel/rubygem-chef-provisioning \
		rubygem-cookbook-omnifetch>=0.5:devel/rubygem-cookbook-omnifetch \
		rubygem-diff-lcs>=1.0:textproc/rubygem-diff-lcs \
		rubygem-ffi-yajl>=1.0:devel/rubygem-ffi-yajl \
		rubygem-minitar>=0.6:archivers/rubygem-minitar \
		rubygem-mixlib-cli>=1.7:devel/rubygem-mixlib-cli \
		rubygem-mixlib-shellout>=2.0:devel/rubygem-mixlib-shellout \
		rubygem-paint1>=1.0:devel/rubygem-paint1 \
		rubygem-solve>=2.0:devel/rubygem-solve

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/chef

.include <bsd.port.mk>
