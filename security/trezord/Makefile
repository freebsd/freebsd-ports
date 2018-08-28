# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	trezord
PORTVERSION=	2.0.21
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	ale@FreeBSD.org
COMMENT=	TREZOR Communication Daemon aka TREZOR Bridge

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		go
USE_RC_SUBR=	${PORTNAME}
USE_GITHUB=	yes
GH_ACCOUNT=	trezor
GH_PROJECT=	${PORTNAME}-go
GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}

PATCH_STRIP=	-p1

PLIST_FILES=	bin/${GH_PROJECT}

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1102000
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-usb_webusb.go
.endif

.include <bsd.port.post.mk>
