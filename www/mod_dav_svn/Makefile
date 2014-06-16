# Created by: lev@FreeBSD.org
# $FreeBSD$

PORTNAME=	mod_dav_svn
DISTNAME=	subversion-${PORTVERSION}

MAINTAINER=	lev@FreeBSD.org
COMMENT=	Apache module for subversion serving.

MASTERDIR=	${.CURDIR}/../../devel/subversion
PKGDIR=		${.CURDIR}

SVN_BUILD_ADDONS=	yes

.include "${MASTERDIR}/Makefile.common"

CATEGORIES+=	www

USE_APACHE=	22+

CONFIGURE_ARGS+=	--with-apxs=${APXS} \
			--with-apache-libexecdir

SUB_FILES=	pkg-install

PLIST_SUB+=	SED=${SED}

ALL_TARGET=	apache-mod
INSTALL_TARGET=	install-mods-shared

.include <bsd.port.post.mk>
