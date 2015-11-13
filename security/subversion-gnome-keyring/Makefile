# Created by: Autrijus Tang <autrijus@autrijus.org>
# $FreeBSD$

PKGNAMESUFFIX=	-gnome-keyring
CATEGORIES=	security gnome

MAINTAINER=	lev@FreeBSD.org
COMMENT=	Gnome KWyring integration for Version control system

.if defined(WITH_SUBVERSION_VER) && ${WITH_SUBVERSION_VER} == 16
BROKEN=		does not build with subversion16
MASTERDIR=	${.CURDIR}/../../devel/subversion16
.elif defined(WITH_SUBVERSION_VER) && ${WITH_SUBVERSION_VER} == 17
BROKEN=		does not build with subversion17
MASTERDIR=	${.CURDIR}/../../devel/subversion17
.elif defined(WITH_SUBVERSION_VER) && ${WITH_SUBVERSION_VER} == 18
MASTERDIR=	${.CURDIR}/../../devel/subversion18
.else
MASTERDIR=	${.CURDIR}/../../devel/subversion
.endif
PKGDIR=		${.CURDIR}

SVN_BUILD_ADDONS=	yes

.include "${MASTERDIR}/Makefile.common"

LIB_DEPENDS+=		libgnome-keyring.so:${PORTSDIR}/security/libgnome-keyring

CONFIGURE_ARGS+=	--with-gnome-keyring

ALL_TARGET=	gnome-keyring-lib
INSTALL_TARGET=	install-gnome-keyring-lib

.include <bsd.port.post.mk>
