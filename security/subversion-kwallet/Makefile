# Created by: Autrijus Tang <autrijus@autrijus.org>
# $FreeBSD$

PKGNAMESUFFIX=	-kwallet
PORTREVISION=	2
CATEGORIES=	security kde

MAINTAINER=	lev@FreeBSD.org
COMMENT=	KDE KWallet integration for Version control system

MASTERDIR=	${.CURDIR}/../../devel/subversion
PKGDIR=		${.CURDIR}

SVN_BUILD_ADDONS=	yes

USE_KDE4=		kdelibs runtime

.include "${MASTERDIR}/Makefile.common"

CONFIGURE_ARGS+=	--with-kwallet=${KDE4_PREFIX}

ALL_TARGET=	kwallet-lib
INSTALL_TARGET=	install-kwallet-lib

.include <bsd.port.post.mk>
