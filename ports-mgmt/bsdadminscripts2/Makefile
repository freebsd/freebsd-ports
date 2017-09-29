# $FreeBSD$

PORTNAME=	bsdadminscripts2
DISTVERSION=	0.2.0
CATEGORIES=	ports-mgmt

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Collection of administration scripts

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USE_GITHUB=	yes
GH_ACCOUNT=	lonkamikaze
GH_PROJECT=	bsda2

NO_BUILD=	yes
NO_ARCH=	yes

CONFLICTS_INSTALL=	bsdadminscripts

do-install:
	@cd ${WRKSRC} && ${SH} install.sh \
		-destdir="${STAGEDIR}" -prefix="${PREFIX}" \
		-datadir="${DATADIR}" -docsdir="${DOCSDIR}"

.include <bsd.port.mk>
