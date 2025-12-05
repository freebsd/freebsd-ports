PORTNAME=	trezord
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.33
PORTREVISION=	4
CATEGORIES=	security

MAINTAINER=	ale@FreeBSD.org
COMMENT=	TREZOR Communication Daemon aka TREZOR Bridge
WWW=		https://github.com/trezor/trezord-go

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		go:1.20,modules

DEPRECATED=	Uses old go, but try building without USES=go:someversion
EXPIRATION_DATE=2026-01-01

USE_RC_SUBR=	${PORTNAME}

USE_GITHUB=	yes
GH_ACCOUNT=	trezor
GH_PROJECT=	${PORTNAME}-go
GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}

PLIST_FILES=	bin/${GH_PROJECT}

.include "${.CURDIR}/Makefile.modules"

.include <bsd.port.mk>
