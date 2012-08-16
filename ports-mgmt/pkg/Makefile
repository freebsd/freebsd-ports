# New ports collection makefile for:	pkg
# Date created:		2012-01-18
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pkg
DISTVERSION=	1.0-rc6
CATEGORIES=	ports-mgmt
MASTER_SITES=	LOCAL/portmgr \
		http://files.etoilebsd.net/pkg/

MAINTAINER=	portmgr@FreeBSD.org
COMMENT=	New generation package manager

LICENSE=	BSD

USE_XZ=		yes

USE_LDCONFIG=	yes
MANCOMPRESSED=	yes

MAKE_ENV+=	WITHOUT_PROFILE=yes
USE_STAGE=	yes

MAN8=	pkg.8 \
	pkg-add.8 \
	pkg-autoremove.8 \
	pkg-audit.8 \
	pkg-backup.8 \
	pkg-check.8 \
	pkg-clean.8 \
	pkg-create.8 \
	pkg-delete.8 \
	pkg-fetch.8 \
	pkg-info.8 \
	pkg-install.8 \
	pkg-query.8 \
	pkg-register.8 \
	pkg-repo.8 \
	pkg-rquery.8 \
	pkg-search.8 \
	pkg-set.8 \
	pkg-shell.8 \
	pkg-shlib.8 \
	pkg-stats.8 \
	pkg-update.8 \
	pkg-updating.8 \
	pkg-upgrade.8 \
	pkg-version.8 \
	pkg-which.8
MAN5=	pkg.conf.5
MLINKS=	pkg-delete.8 pkg-remove.8 \
	pkg.8 pkg-static.8

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
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' ${WRKSRC}/scripts/periodic/410.pkg-audit
	@${MKDIR} ${PREFIX}/etc/periodic/security
	@${MKDIR} ${PREFIX}/etc/periodic/daily
	@${INSTALL_SCRIPT} ${WRKSRC}/scripts/periodic/410.pkg-audit ${PREFIX}/etc/periodic/security
	@${INSTALL_SCRIPT} ${WRKSRC}/scripts/periodic/411.pkg-backup ${PREFIX}/etc/periodic/daily
	@${INSTALL_SCRIPT} ${WRKSRC}/ports/pkg2ng ${PREFIX}/sbin
	@${INSTALL_DATA} ${WRKSRC}/pkg/pkg.conf.sample ${PREFIX}/etc
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
