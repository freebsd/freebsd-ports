# New ports collection makefile for:	pkg_install
# Date created:				25 Jan 2004
# Whom:					Oliver Eikemeier
#
# $FreeBSD$
#

PORTNAME=		pkg_install
PORTVERSION=		20040125
PORTREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	eik
PKGNAMESUFFIX=		-devel

MAINTAINER=		eik@FreeBSD.org
COMMENT=		Development version of the FreeBSD 5.x package tools

CONFLICTS=		pkg_install-[0-9]*

MANCOMPRESSED=		yes

MAN1=			pkg_add.1 pkg_create.1 pkg_delete.1 \
			pkg_info.1 pkg_version.1

.if defined(PREFIX)
.if ${PREFIX} == "/usr"
PKGNAMESUFFIX=		-base-devel
.endif
.endif

BACKUPDIR?=		/var/backups

.if !defined(NOCRYPT) && !defined(NO_OPENSSL)
USE_OPENSSL=		yes
.if exists(/usr/lib/libcrypto.so)
USE_OPENSSL_BASE=	yes
.else
.if ${PREFIX} = "/usr"
.error
.else
USE_OPENSSL_PORT=	yes
.endif
.endif
MAN1+=			pkg_check.1 pkg_sign.1
PLIST_SUB+=		OPENSSL=""
.else
MAKE_ARGS=		-DNO_OPENSSL
PLIST_SUB+=		OPENSSL="@comment "
.endif

.include <bsd.port.pre.mk>

pre-everything::
	@${ECHO} "======================================================================================="
	@${ECHO}
	@${ECHO} "Build ${PKGNAME} with PREFIX=/usr to replace the base package tools"
	@${ECHO}
	@${ECHO} "======================================================================================="

.if ${OSVERSION} < 460102
check-already-installed:
.if !defined(NO_PKG_REGISTER) && !defined(FORCE_PKG_REGISTER)
	@if [ -d ${PKG_DBDIR}/${PKGNAME} ]; then \
		${ECHO_CMD} "===>  ${PKGNAME} is already installed - perhaps an older version?"; \
		${ECHO_CMD} "      If so, you may wish to \`\`make deinstall'' and install"; \
		${ECHO_CMD} "      this port again by \`\`make reinstall'' to upgrade it properly."; \
		${ECHO_CMD} "      If you really wish to overwrite the old port of ${PKGNAME}"; \
		${ECHO_CMD} "      without deleting it first, set the variable \"FORCE_PKG_REGISTER\""; \
		${ECHO_CMD} "      in your environment or the \"make install\" command line."; \
		exit 1; \
	fi
.else
	@${DO_NADA}
.endif
.endif

pre-configure:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' \
		-e 's,%%MANPREFIX%%,${MANPREFIX},g' \
		${FILESDIR}/Makefile.inc > ${WRKDIR}/Makefile.inc

# __FBSDID is undefied for old FreeBSD versions
.if ${OSVERSION} < 440001 || ( ${OSVERSION} >= 500000 && ${OSVERSION} < 500024 )
post-patch:
	@${FIND} ${WRKSRC} -name '*.c' \
		| ${XARGS} ${PERL} -pi.orig -e 's/__FBSDID\(("[^"]*")\)/static const char rcsid[] = $$1/'
.endif

test: build
	@(cd ${BUILD_WRKSRC}/version && ${SH} test-pkg_version.sh)

# Call pkg-install in `do-install:' instead of `pre-install:' because it might
# deinstall pkg_info, which is fatal during `check-already-installed:'.
do-install:
	${SETENV} "PKG_PREFIX=${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
	@(cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})

.include <bsd.port.post.mk>
