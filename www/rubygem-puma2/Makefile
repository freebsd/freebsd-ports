# Created by: Steve Wills <swills@freebsd.org>
# $FreeBSD$

PORTNAME=	puma
PORTVERSION=	2.16.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	2

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast, multithreaded and highly concurrent ruby web server

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

PORTSCOUT=	limit:^2\.

USE_RUBY=	yes
USES=		gem shebangfix ssl

PLIST_FILES=	bin/puma bin/pumactl

SHEBANG_FILES=	tools/jungle/init.d/run-puma

.include <bsd.port.mk>
