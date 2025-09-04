PORTNAME=	doctl
DISTVERSIONPREFIX=	v
DISTVERSION=	1.141.0
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/digitalocean/${PORTNAME}/releases/download/v${DISTVERSION}/
DISTNAME=	${PORTNAME}-${DISTVERSION}-source

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Command line tool for DigitalOcean services
WWW=		https://github.com/digitalocean/doctl

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		go:1.24,modules

GO_TARGET=	./cmd/${PORTNAME}

NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/doctl

.include <bsd.port.mk>
