# Created by: Steve Wills <swills@freebsd.org>
# $FreeBSD$

PORTNAME=	puma
PORTVERSION=	2.11.3
PORTREVISION=	1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Fast, multithreaded and highly concurrent ruby web server

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	rubygem-rack16>=1.1:${PORTSDIR}/www/rubygem-rack16

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
USES=		shebangfix
SHEBANG_FILES=	tools/jungle/init.d/run-puma

PLIST_FILES=	bin/puma bin/pumactl

.include <bsd.port.mk>
