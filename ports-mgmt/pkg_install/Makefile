# New ports collection makefile for:	pkg_install
# Date created:				14 Jul 2003
# Whom:					Oliver Eikemeier
#
# $FreeBSD$
#

PORTNAME=		pkg_install
PORTVERSION=		20080411
CATEGORIES=		ports-mgmt
MASTER_SITES=		${MASTER_SITE_LOCAL} \
			http://people.FreeBSD.org/~flz/distfiles/pkg_install/
MASTER_SITE_SUBDIR=	flz/pkg_install

MAINTAINER=		portmgr@freebsd.org
COMMENT=		FreeBSD -CURRENT version of the pkg tools for older system releases

MANCOMPRESSED=		yes

MAN1=			pkg_add.1 pkg_create.1 pkg_delete.1 \
			pkg_info.1 pkg_updating.1 pkg_version.1

.include <bsd.port.pre.mk>

# Arbitrary OSVERSION but support for 5.x will go away soon anyway...
.if ${OSVERSION} < 600000
MAKE_ARGS=		-DNOOBJ -DNOCRYPT -DNO_OPENSSL
.else
MAKE_ARGS=		-DNO_OBJ -DNO_CRYPT -DNO_OPENSSL
.endif

pre-configure:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' \
		-e 's,%%MANPREFIX%%,${MANPREFIX},g' \
		${FILESDIR}/Makefile.inc > ${WRKDIR}/Makefile.inc

deinstall:
	@if ${PKG_INFO} -e ${PKGNAME}; then \
		${PKG_DELETE} -f ${PKGNAME}; \
	else \
		${ECHO_MSG} "===> ${PKGNAME} not installed; skipping"; \
	fi
	@${RM} -f ${INSTALL_COOKIE} ${PACKAGE_COOKIE}

.include <bsd.port.post.mk>
