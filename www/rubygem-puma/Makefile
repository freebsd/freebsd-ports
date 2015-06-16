# Created by: Steve Wills <swills@freebsd.org>
# $FreeBSD$

PORTNAME=	puma
PORTVERSION=	2.9.1
PORTREVISION=	1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Fast, multithreaded and highly concurrent ruby web server

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	rubygem-rack>=1.1.0:${PORTSDIR}/www/rubygem-rack

USES=		shebangfix
SHEBANG_FILES=	tools/jungle/init.d/run-puma
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/puma bin/pumactl

.include <bsd.port.mk>
