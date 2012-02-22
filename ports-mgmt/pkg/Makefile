# New ports collection makefile for:	pkg
# Date created:		2012-01-18
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pkg
DISTVERSION=	1.0-beta7
CATEGORIES=	ports-mgmt
MASTER_SITES=	LOCAL/portmgr \
		http://files.etoilebsd.net/pkg/

MAINTAINER=	portmgr@FreeBSD.org
COMMENT=	New generation package manager

LICENSE=	BSD

USE_BZIP2=	yes

USE_LDCONFIG=	yes
MANCOMPRESSED=	yes

MAKE_ENV+=	WITHOUT_PROFILE=yes

MAN8=	pkg.8 \
	pkg-add.8 \
	pkg-autoremove.8 \
	pkg-backup.8 \
	pkg-create.8 \
	pkg-delete.8 \
	pkg-info.8 \
	pkg-install.8 \
	pkg-query.8 \
	pkg-register.8 \
	pkg-repo.8 \
	pkg-search.8 \
	pkg-update.8 \
	pkg-updating.8 \
	pkg-upgrade.8 \
	pkg-version.8 \
	pkg-which.8
MAN5=	pkg.conf.5

PLIST_FILES=	sbin/pkg \
		sbin/pkg-static \
		sbin/pkg2ng \
		include/pkg.h \
		lib/libpkg.so.0 \
		lib/libpkg.so \
		lib/libpkg.a

.include <bsd.port.pre.mk>

#define PKG_DEPENDS to nothing to avoid infinite loop looking for pkg :)
.if defined(WITH_PKGNG)
PKG_DEPENDS=
.undef INSTALLS_DEPENDS
.if !exists(${LOCALBASE}/sbin/pkg)
PKG_BIN=	${WRKSRC}/pkg-static/pkg-static
.endif
.endif

.if ${OSVERSION} < 800505
IGNORE=		not supported on 7.x or early 8.0
.endif

post-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/ports/pkg2ng ${PREFIX}/sbin

.include <bsd.port.post.mk>
