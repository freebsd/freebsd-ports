# $FreeBSD$

PORTNAME=	doctl
DISTVERSIONPREFIX=	v
DISTVERSION=	1.57.0
CATEGORIES=	sysutils

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Command line tool for DigitalOcean services

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	digitalocean

GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/doctl

.include <bsd.port.mk>
