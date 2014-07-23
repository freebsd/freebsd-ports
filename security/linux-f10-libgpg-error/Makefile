# Created by: Stas Timoklhin <devel@stasyan.com>
# $FreeBSD$

PORTNAME=	libgpg-error
PORTVERSION=	1.6
CATEGORIES=	security linux
PKGNAMEPREFIX=	linux-f10-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Common error values for all GnuPG components

USE_LINUX_RPM=	yes
LINUX_DIST_VER=	10
RPMVERSION=	2
USE_LDCONFIG=	yes
BRANDELF_FILES=	usr/bin/gpg-error

PLIST_SUB=	PORTVERSION="${PORTVERSION}"
DESCR=		${.CURDIR}/../libgpg-error/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
