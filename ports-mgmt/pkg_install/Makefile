# New ports collection makefile for:	pkg_install
# Date created:				14 Jul 2003
# Whom:					Oliver Eikemeier
#
# $FreeBSD$
#

PORTNAME=		pkg_install
PORTVERSION=		20090902
PORTREVISION=		0
CATEGORIES=		ports-mgmt
MASTER_SITES=		${MASTER_SITE_LOCAL} \
			http://people.FreeBSD.org/~flz/distfiles/pkg_install/
MASTER_SITE_SUBDIR=	flz/pkg_install

MAINTAINER=		portmgr@FreeBSD.org
COMMENT=		FreeBSD -STABLE version of the package tools

MANCOMPRESSED=		yes
MAN1=			pkg_add.1 pkg_create.1 pkg_delete.1 \
			pkg_info.1 pkg_updating.1 pkg_version.1

MAKE_ARGS=		-DNO_OBJ -DNO_CRYPT -DNO_OPENSSL

OPTIONS=		WRAPPER "Use ports version instead of base if more recent" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_WRAPPER)
PLIST_SUB+=	WRAPPER=""
.else
PLIST_SUB+=	WRAPPER="@comment "
.endif

pre-configure:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' \
		-e 's,%%MANPREFIX%%,${MANPREFIX},g' \
		${FILESDIR}/Makefile.inc > ${WRKDIR}/Makefile.inc

# This enables the wrapper 
.if !defined(WITHOUT_WRAPPER)
post-install:
	${ECHO} "${PORTVERSION} ${PREFIX}/sbin" > /var/db/${PORTNAME}.conf
.endif

deinstall:
	@if ${PKG_INFO} -e ${PKGNAME}; then \
		${PKG_DELETE} -f ${PKGNAME}; \
	else \
		${ECHO_MSG} "===> ${PKGNAME} not installed; skipping"; \
	fi
	@${RM} -f ${INSTALL_COOKIE} ${PACKAGE_COOKIE}

.include <bsd.port.post.mk>
