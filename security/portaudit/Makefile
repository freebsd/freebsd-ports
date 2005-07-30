# New ports collection makefile for:	portaudit
# Date created:				25 Jan 2004
# Whom:					Oliver Eikemeier
#
# $FreeBSD$
#

PORTNAME=	portaudit
PORTVERSION=	0.5.10
CATEGORIES=	security
DISTFILES=

MAINTAINER=	secteam@FreeBSD.org
COMMENT=	Checks installed ports against a list of security vulnerabilities

MAN1=		portaudit.1

PERIODICDIR?=	${PREFIX}/etc/periodic
DATABASEDIR?=	/var/db/portaudit

PKGREQ=		${WRKDIR}/pkg-req
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall

PLIST_SUB+=	PERIODICDIR="${PERIODICDIR:S,^${PREFIX}/,,}" \
		DATABASEDIR="${DATABASEDIR}"

REQPKGVER=	20040623

SED_SCRIPT=	-e 's|%%PREFIX%%|${PREFIX}|g' \
		-e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		-e "s|%%PORTSDIR%%|${PORTSDIR}|g" \
		-e "s|%%INDEXFILE%%|${INDEXFILE}|g" \
		-e "s|%%DATABASEDIR%%|${DATABASEDIR}|g" \
		-e "s|%%PORTVERSION%%|${PORTVERSION}|g" \
		-e "s|%%REQPKGVER%%|${REQPKGVER}|g" \
		-e "s|%%BZIP2_CMD%%|${BZIP2_CMD}|g" \

.include <bsd.port.pre.mk>

.if !defined(DFOSVERSION)
.if ${OSVERSION} < 491101 || ${OSVERSION} >= 500000 && ${OSVERSION} < 502120
RUN_DEPENDS=	${LOCALBASE}/sbin/pkg_info:${PORTSDIR}/sysutils/pkg_install-devel
.endif
.else
.if ${DFOSVERSION} < 110000
RUN_DEPENDS=	${LOCALBASE}/sbin/pkg_info:${PORTSDIR}/sysutils/pkg_install-devel
.endif
.endif

.if defined(BZIP2DEPENDS)
RUN_DEPENDS+=	bzip2:${PORTSDIR}/archivers/bzip2
.endif

do-build:
.for f in portaudit-cmd.sh portaudit.sh portaudit.1 portaudit.conf
	@${SED} ${SED_SCRIPT} ${FILESDIR}/${f} >${WRKDIR}/${f}
.endfor

post-build:
.for f in pkg-req pkg-install pkg-deinstall
	@${SED} ${SED_SCRIPT} ${PKGDIR}/${f} >${WRKDIR}/${f}
.endfor

pre-install:
.if !defined(PACKAGE_BUILDING)
	@${SETENV} "PKG_PREFIX=${PREFIX}" ${SH} ${PKGREQ} ${PKGNAME} INSTALL
.endif
	@${SETENV} "PKG_PREFIX=${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/portaudit-cmd.sh ${PREFIX}/sbin/portaudit
	@${INSTALL_DATA} ${WRKDIR}/portaudit.conf ${PREFIX}/etc/portaudit.conf.sample
	@${INSTALL_MAN} ${WRKDIR}/portaudit.1 ${MAN1PREFIX}/man/man1
	@${MKDIR} ${PERIODICDIR}/security
	@${INSTALL_SCRIPT} ${WRKDIR}/portaudit.sh ${PERIODICDIR}/security/410.portaudit
	@${MKDIR} ${DATABASEDIR}

post-install:
	@${SETENV} "PKG_PREFIX=${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
