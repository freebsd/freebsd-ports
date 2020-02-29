# $FreeBSD$

PORTNAME=	daemonize
DISTVERSION=	1.7.8
DISTVERSIONPREFIX=	release-
CATEGORIES=	sysutils

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tool to run a command as a daemon

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		gmake

GNU_CONFIGURE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	bmc

PLIST_FILES=	bin/daemonize \
		share/man/man1/daemonize.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/daemonize ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/daemonize.1 ${STAGEDIR}${MAN1PREFIX}/share/man/man1

.include <bsd.port.mk>
