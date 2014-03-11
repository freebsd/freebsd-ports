# Created by: Steve Wills <swills@freebsd.org>
# $FreeBSD$

PORTNAME=	puma
PORTVERSION=	1.6.3
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	16

MAINTAINER=	ruby@freebsd.org
COMMENT=	Fast, multithreaded and highly concurrent ruby web server

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	rubygem-rack>=1.1.0:${PORTSDIR}/www/rubygem-rack

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/puma bin/pumactl

.include <bsd.port.mk>
