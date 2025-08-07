PORTNAME=	gauth
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.0
PORTREVISION=	4
CATEGORIES=	security

MAINTAINER=	nxjoseph@protonmail.com
COMMENT=	Google Authenticator in your terminal
WWW=		https://github.com/pcarrier/gauth \
		https://pkg.go.dev/github.com/pcarrier/gauth

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.23,modules

GO_MODULE=	github.com/pcarrier/gauth

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
