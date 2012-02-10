# New ports collection makefile for:	pkg
# Date created:		2012-01-18
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pkg
DISTVERSION=	1.0-beta3
CATEGORIES=	ports-mgmt
MASTER_SITES=	LOCAL/portmgr \
		http://files.etoilebsd.net/pkg/

MAINTAINER=	portmgr@FreeBSD.org
COMMENT=	New generation package manager

LICENSE=	BSD

USE_BZIP2=	yes

#define PKG_DEPENDS to nothing to avoid infinite loop looking for pkg :)
.if defined(WITH_PKGNG)
PKG_DEPENDS=
.if !exists(${LOCALBASE}/sbin/pkg)
PKG_BIN=	${WRKSRC}/pkg-static/pkg-static
.endif
.endif

USE_LDCONFIG=	yes
MANCOMPRESSED=	yes

MAKE_ENV+=	WITHOUT_PROFILE=yes

MAN1=	pkg.1 \
	pkg-add.1 \
	pkg-autoremove.1 \
	pkg-backup.1 \
	pkg-create.1 \
	pkg-delete.1 \
	pkg-info.1 \
	pkg-install.1 \
	pkg-query.1 \
	pkg-register.1 \
	pkg-repo.1 \
	pkg-search.1 \
	pkg-update.1 \
	pkg-upgrade.1 \
	pkg-version.1 \
	pkg-which.1
MAN5=	pkg.conf.5

PLIST_FILES=	sbin/pkg \
		sbin/pkg-static \
		sbin/pkg2ng \
		include/pkg.h \
		lib/libpkg.so.0 \
		lib/libpkg.so \
		lib/libpkg.a

post-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/ports/pkg2ng ${PREFIX}/sbin

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800000
IGNORE=		not supported on 7.x
.endif

.include <bsd.port.post.mk>
