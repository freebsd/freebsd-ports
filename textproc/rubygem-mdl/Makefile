# $FreeBSD$

PORTNAME=	mdl
PORTVERSION=	0.11.0
PORTREVISION=	1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Check markdown files and flag style issues

LICENSE=	MIT

RUN_DEPENDS=	rubygem-kramdown>=2.3<3:textproc/rubygem-kramdown \
		rubygem-kramdown-parser-gfm>=1.1<2:textproc/rubygem-kramdown-parser-gfm \
		rubygem-chef-utils>=16.8.14:sysutils/rubygem-chef-utils \
		rubygem-mixlib-cli>=2.1.1<3:devel/rubygem-mixlib-cli \
		rubygem-mixlib-config>=2.2.1<4:devel/rubygem-mixlib-config \
		rubygem-mixlib-shellout>=0:devel/rubygem-mixlib-shellout

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/mdl

.include <bsd.port.mk>
