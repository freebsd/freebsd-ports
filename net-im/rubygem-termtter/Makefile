# Created by: Dennis Herrmann <dhn@FreeBSD.org>
# $FreeBSD$

PORTNAME=	termtter
PORTVERSION=	2.2.1
PORTREVISION=	1
CATEGORIES=	net-im rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Terminal based Twitter client

LICENSE=	MIT

RUN_DEPENDS=	rubygem-highline>=1.5.0:${PORTSDIR}/devel/rubygem-highline \
		rubygem-json>=1.1.3:${PORTSDIR}/devel/rubygem-json \
		rubygem-notify>=0.5.1:${PORTSDIR}/devel/rubygem-notify \
		rubygem-rubytter>=1.5.1:${PORTSDIR}/net/rubygem-rubytter \
		rubygem-termcolor>=1.0.0:${PORTSDIR}/textproc/rubygem-termcolor

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/termtter bin/termtter_frame

.include <bsd.port.mk>
