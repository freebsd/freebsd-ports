PORTNAME=	bsdadminscripts2
PORTVERSION=	0.5.1
CATEGORIES=	ports-mgmt

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	BSD Administration Scripts 2
WWW=		https://github.com/lonkamikaze/bsda2

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USE_GITHUB=	yes
GH_ACCOUNT=	lonkamikaze
GH_PROJECT=	bsda2

NO_ARCH=	yes
NO_BUILD=	yes

CONFLICTS_INSTALL=	bsdadminscripts

OPTIONS_DEFINE=	DOCS

do-install:
	cd ${WRKSRC} && ${SH} install.sh -datadir="${DATADIR}" -destdir="${STAGEDIR}" -docsdir="${DOCSDIR}" -prefix="${PREFIX}"

.include <bsd.port.mk>
