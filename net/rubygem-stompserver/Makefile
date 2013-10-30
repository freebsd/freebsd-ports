# Created by: Mike Carlson <carlson39@llnl.gov>
# $FreeBSD$

PORTNAME=	stompserver
PORTVERSION=	0.9.9
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Provide reliable messaging using the stomp protocol

USE_RUBY=		yes
USE_RUBYGEMS=		yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/stompserver

RUN_DEPENDS:=	rubygem-eventmachine>=0.7.2:${PORTSDIR}/devel/rubygem-eventmachine \
		rubygem-hoe>=1.3.0:${PORTSDIR}/devel/rubygem-hoe \
		rubygem-daemons>=1.0.2:${PORTSDIR}/devel/rubygem-daemons

.include <bsd.port.mk>
