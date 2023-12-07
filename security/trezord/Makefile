PORTNAME=	trezord
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.33
PORTREVISION=	3
CATEGORIES=	security

MAINTAINER=	ale@FreeBSD.org
COMMENT=	TREZOR Communication Daemon aka TREZOR Bridge
WWW=		https://github.com/trezor/trezord-go

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		go:modules

USE_RC_SUBR=	${PORTNAME}

USE_GITHUB=	yes
GH_ACCOUNT=	trezor
GH_PROJECT=	${PORTNAME}-go
GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}

PLIST_FILES=	bin/${GH_PROJECT}

.include "${.CURDIR}/Makefile.modules"

.include <bsd.port.mk>
