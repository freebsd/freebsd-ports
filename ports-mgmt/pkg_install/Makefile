# New ports collection makefile for:	pkg_install
# Date created:				14 Jul 2003
# Whom:					Oliver Eikemeier
#
# $FreeBSD$
#

PORTNAME=		pkg_install
PORTVERSION=		20040416
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_LOCAL} \
			http://people.FreeBSD.org/~marcus/
MASTER_SITE_SUBDIR=	marcus

MAINTAINER=		portmgr@freebsd.org
COMMENT=		FreeBSD 5.x version of the package tools for older system releases

MANCOMPRESSED=		yes

MAN1=			pkg_add.1 pkg_create.1 pkg_delete.1 \
			pkg_info.1 pkg_version.1

MAKE_ARGS=		-DNOOBJ -DNOCRYPT -DNO_OPENSSL

.include <bsd.port.pre.mk>

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

.if ${OSVERSION} < 440001 || ( ${OSVERSION} >= 500000 && ${OSVERSION} < 500024 )
post-patch:
	@${FIND} ${WRKSRC} -name '*.c' \
		| ${XARGS} ${PERL} -pi.orig -e 's/__FBSDID\(("[^"]*")\)/static const char rcsid[] = $$1/'
.endif

deinstall:
	@if ${PKG_INFO} -e ${PKGNAME}; then \
		${PKG_DELETE} -f ${PKGNAME}; \
	else \
		${ECHO_MSG} "===> ${PKGNAME} not installed; skipping"; \
	fi
	@${RM} -f ${INSTALL_COOKIE} ${PACKAGE_COOKIE}

.include <bsd.port.post.mk>
