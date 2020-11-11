# $FreeBSD$

PORTNAME=	spectre-meltdown-checker
DISTVERSIONPREFIX=	v
DISTVERSION=	0.44
CATEGORIES=	security

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Checks your system for the speculative execution CVEs

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	speed47
NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/spectre-meltdown-checker.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/spectre-meltdown-checker.sh ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
