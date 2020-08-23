# Created by: Dennis Herrmann <dhn@FreeBSD.org>
# $FreeBSD$

PORTNAME=	termtter
PORTVERSION=	2.2.9
PORTREVISION=	1
CATEGORIES=	net-im rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Terminal based Twitter client

LICENSE=	MIT

RUN_DEPENDS=	rubygem-activerecord4>=4.1.0<5:databases/rubygem-activerecord4 \
		rubygem-builder>=3.1.4<4:devel/rubygem-builder \
		rubygem-fluent-logger>=0.5.1<1:devel/rubygem-fluent-logger \
		rubygem-highline1>=1.7.0<1.8:devel/rubygem-highline1 \
		rubygem-json1>=1.8.0<1.9:devel/rubygem-json1 \
		rubygem-notify>=0.5.1<0.6:devel/rubygem-notify \
		rubygem-rubytter>=1.5.1<1.6:net/rubygem-rubytter \
		rubygem-termcolor>=1.0<2:textproc/rubygem-termcolor

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/termtter bin/termtter_frame

.include <bsd.port.mk>
