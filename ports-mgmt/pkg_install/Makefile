# Created by: Oliver Eikemeier
# $FreeBSD$

PORTNAME=		pkg_install
PORTVERSION=		20120822
CATEGORIES=		ports-mgmt
MASTER_SITES=		LOCAL/bapt \
			http://people.FreeBSD.org/~bapt/distfiles/

MAINTAINER=		portmgr@FreeBSD.org
COMMENT=		FreeBSD -STABLE version of the package tools

DEPRECATED=		Replaced by ports-mgmt/pkg
EXPIRATION_DATE=	2014-04-30

LICENSE=		BSD

MANCOMPRESSED=		yes
MAN1=			pkg_add.1 pkg_create.1 pkg_delete.1 \
			pkg_info.1 pkg_updating.1 pkg_version.1

MAKE_ARGS=		-DNO_OBJ -DNO_CRYPT -DNO_OPENSSL

OPTIONS_DEFINE=	WRAPPER
OPTIONS_DEFAULT=	WRAPPER
WRAPPER_DESC=	Use ports version instead of base if more recent

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MWRAPPER}
PLIST_SUB+=	WRAPPER=""
.else
PLIST_SUB+=	WRAPPER="@comment "
.endif

pre-configure:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' \
		-e 's,%%MANPREFIX%%,${MANPREFIX},g' \
		${FILESDIR}/Makefile.inc > ${WRKDIR}/Makefile.inc

# This enables the wrapper 
.if ${PORT_OPTIONS:MWRAPPER}
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

.include <bsd.port.mk>
