# Created by: Autrijus Tang <autrijus@autrijus.org>
# $FreeBSD$

PKGNAMESUFFIX=	-gnome-keyring

MAINTAINER=	lev@FreeBSD.org
COMMENT=	Gnome KWyring integration for Version control system

MASTERDIR=	${.CURDIR}/../../devel/subversion
PKGDIR=		${.CURDIR}

SVN_BUILD_ADDONS=	yes

.include "${MASTERDIR}/Makefile.common"

LIB_DEPENDS+=		libgnome-keyring.so:${PORTSDIR}/security/libgnome-keyring

CONFIGURE_ARGS+=	--with-gnome-keyring

CATEGORIES+=	gnome security

ALL_TARGET=	gnome-keyring-lib
INSTALL_TARGET=	install-gnome-keyring-lib

.include <bsd.port.post.mk>
