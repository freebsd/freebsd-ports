PORTNAME=	doctl
DISTVERSIONPREFIX=	v
DISTVERSION=	2.11.0
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/digitalocean/${PORTNAME}/releases/download/v${DISTVERSION}/
DISTNAME=	${PORTNAME}-${DISTVERSION}-source

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Command line tool for DigitalOcean services
WWW=		https://github.com/digitalocean/doctl

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		go:modules

GO_TARGET=	./cmd/${PORTNAME}

# tests expect CI
GO_ENV+=	CI=true

NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/doctl

# tests expect .git/; empty directory is enough
pre-test:
	@${MKDIR} ${WRKSRC}/.git

.include <bsd.port.mk>
