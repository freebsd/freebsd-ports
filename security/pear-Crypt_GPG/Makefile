# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Crypt_GPG
PORTVERSION=	1.4.3
CATEGORIES=	security www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU Privacy Guard (GPG)

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PEAR_PKGNAMEPREFIX}Console_CommandLine>=1.1.10:devel/pear-Console_CommandLine@${PHP_FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		pear php
USE_PHP=	mbstring posix

.include <bsd.port.mk>
