PORTNAME=	doctl
DISTVERSION=	1.77.0
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/digitalocean/${PORTNAME}/releases/download/v${DISTVERSION}/
DISTNAME=	${PORTNAME}-${DISTVERSION}-source

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Command line tool for DigitalOcean services

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		go:modules

GO_TARGET=	./cmd/${PORTNAME}

NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/doctl

.include <bsd.port.mk>
