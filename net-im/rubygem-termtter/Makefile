# Created by: Dennis Herrmann <dhn@FreeBSD.org>
# $FreeBSD$

PORTNAME=	termtter
PORTVERSION=	2.2.6
CATEGORIES=	net-im rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Terminal based Twitter client

LICENSE=	MIT

RUN_DEPENDS=	rubygem-activerecord4>=4.1.0:databases/rubygem-activerecord4 \
		rubygem-builder32>=3.1.4:devel/rubygem-builder32 \
		rubygem-fluent-logger>=0.4.6:devel/rubygem-fluent-logger \
		rubygem-highline>=1.6.0:devel/rubygem-highline \
		rubygem-json>=1.8.0:devel/rubygem-json \
		rubygem-notify>=0.5.1:devel/rubygem-notify \
		rubygem-rubytter>=1.5.1:net/rubygem-rubytter \
		rubygem-termcolor>=1.0:textproc/rubygem-termcolor

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/termtter bin/termtter_frame

.include <bsd.port.mk>
