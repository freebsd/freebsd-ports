# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	container-diff
PORTVERSION=	0.6.1
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Diff your Docker containers

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}
USES=		go

PLIST_FILES=	bin/container-diff

GH_ACCOUNT=	GoogleCloudPlatform
USE_GITHUB=	yes

.include <bsd.port.options.mk>

# Change inode size from 64 bits to 32 bits for systems without ino64 support
.if ${OSVERSION} < 1200031
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-without-ino64
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/container-diff ${STAGEDIR}${PREFIX}/bin/container-diff

.include <bsd.port.mk>
