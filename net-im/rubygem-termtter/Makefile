# Created by: Dennis Herrmann <dhn@FreeBSD.org>
# $FreeBSD$

PORTNAME=	termtter
PORTVERSION=	2.2.1
CATEGORIES=	net-im rubygems
MASTER_SITES=	RG

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Terminal based Twitter client

RUN_DEPENDS=	rubygem-json>=1.1.3:${PORTSDIR}/devel/rubygem-json \
		rubygem-termcolor>=1.0.0:${PORTSDIR}/textproc/rubygem-termcolor \
		rubygem-rubytter>=1.5.1:${PORTSDIR}/net/rubygem-rubytter \
		rubygem-highline>=1.5.0:${PORTSDIR}/devel/rubygem-highline \
		rubygem-notify>=0.5.1:${PORTSDIR}/devel/rubygem-notify

USE_RUBY=	yes
USE_RUBYGEMS=	yes
USE_RAKE=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/termtter bin/termtter_frame

NO_STAGE=	yes
.include <bsd.port.mk>
