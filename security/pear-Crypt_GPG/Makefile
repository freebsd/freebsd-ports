# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Crypt_GPG
PORTVERSION=	1.4.2
CATEGORIES=	security www pear

MAINTAINER=	dem.procopiou@gmail.com
COMMENT=	GNU Privacy Guard (GPG)

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	pear-Console_CommandLine>=1.1.10:devel/pear-Console_CommandLine
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		pear php
USE_PHP=	mbstring posix

.include <bsd.port.mk>
