# $FreeBSD$

PORTNAME=	kurly
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.2
CATEGORIES=	www

MAINTAINER=	seanc@FreeBSD.org
COMMENT=	Alternative implementation of curl written in Golang

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go

USE_GITLAB=	yes
GL_ACCOUNT=	davidjpeacock
GL_COMMIT=	369c1998dfbfca7043f8c995c8ef8714496530ea

USE_GITHUB=	nodefault
GH_TUPLE=	aki237:nscjar:e2df936:nscjar/vendor/github.com/aki237/nscjar \
		alsm:ioprogress:063c372:ioprogress/vendor/github.com/alsm/ioprogress \
		urfave:cli:8e01ec4:ucli/vendor/github.com/urfave/cli

GO_PKGNAME=	gitlab.com/davidjpeacock/kurly

PLIST_FILES=	bin/kurly

.include <bsd.port.mk>
