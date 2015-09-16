# Created by: Dennis Herrmann <dhn@FreeBSD.org>
# $FreeBSD$

PORTNAME=	termtter
PORTVERSION=	2.2.3
PORTREVISION=	1
CATEGORIES=	net-im rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Terminal based Twitter client

LICENSE=	MIT

RUN_DEPENDS=	rubygem-activerecord4>=4.1.0:${PORTSDIR}/databases/rubygem-activerecord4 \
		rubygem-builder32>=3.1.4:${PORTSDIR}/devel/rubygem-builder32 \
		rubygem-fluent-logger>=0.4.6:${PORTSDIR}/devel/rubygem-fluent-logger \
		rubygem-highline>=1.6.0:${PORTSDIR}/devel/rubygem-highline \
		rubygem-json>=1.8.0:${PORTSDIR}/devel/rubygem-json \
		rubygem-notify>=0.5.1:${PORTSDIR}/devel/rubygem-notify \
		rubygem-rubytter>=1.5.1:${PORTSDIR}/net/rubygem-rubytter \
		rubygem-termcolor>=1.0:${PORTSDIR}/textproc/rubygem-termcolor

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/termtter bin/termtter_frame

.include <bsd.port.mk>
