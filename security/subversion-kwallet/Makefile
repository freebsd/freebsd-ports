# Created by: Autrijus Tang <autrijus@autrijus.org>
# $FreeBSD$

PKGNAMESUFFIX=	-kwallet
CATEGORIES=	security kde

MAINTAINER=	lev@FreeBSD.org
COMMENT=	KDE KWallet integration for Version control system

.if defined(WITH_SUBVERSION_VER) && ${WITH_SUBVERSION_VER} == 16
BROKEN=		does not build with subversion16
MASTERDIR=	${.CURDIR}/../../devel/subversion16
.elif defined(WITH_SUBVERSION_VER) && ${WITH_SUBVERSION_VER} == 17
BROKEN=		does not build with subversion17
MASTERDIR=	${.CURDIR}/../../devel/subversion17
.elif defined(WITH_SUBVERSION_VER) && ${WITH_SUBVERSION_VER} == 18
PORTREVISION=	2
MASTERDIR=	${.CURDIR}/../../devel/subversion18
.else
MASTERDIR=	${.CURDIR}/../../devel/subversion
.endif
PKGDIR=		${.CURDIR}

SVN_BUILD_ADDONS=	yes

USE_KDE4=		kdelibs runtime

.include "${MASTERDIR}/Makefile.common"

CONFIGURE_ARGS+=	--with-kwallet=${KDE4_PREFIX}

ALL_TARGET=	kwallet-lib
INSTALL_TARGET=	install-kwallet-lib

.include <bsd.port.post.mk>
