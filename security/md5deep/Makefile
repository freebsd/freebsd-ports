# Created by: Frank Laszlo <laszlof@vonostingroup.com>
# $FreeBSD$

PORTNAME=	md5deep
PORTVERSION=	4.4
CATEGORIES=	security

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Program to compute various message digests recursively

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GH_ACCOUNT=	jessek
GH_PROJECT=	hashdeep
GH_TAGNAME=	cd2ed74

USE_GITHUB=	yes
USE_AUTOTOOLS=	autoconf:env autoheader:env automake:env aclocal:env
USES=		gmake
GNU_CONFIGURE=	yes

pre-configure:
	(cd ${WRKSRC}; ${SH} bootstrap.sh)

.include <bsd.port.mk>
