# New ports collection makefile for:	portaudit
# Date created:				25 Jan 2004
# Whom:					Oliver Eikemeier
#
# $FreeBSD$
#

PORTNAME=	portaudit
PORTVERSION=	0.1
CATEGORIES=	security
DISTFILES=

MAINTAINER=	eik@FreeBSD.org
COMMENT=	Checks installed ports against a list of security vulnerabilities

PERIODICDIR?=	${PREFIX}/etc/periodic
DATABASEDIR?=	/var/db/portaudit

PLIST_SUB+=	PERIODICDIR="${PERIODICDIR:S,^${PREFIX}/,,}" \
		DATABASEDIR="${DATABASEDIR}"

PKG_INFO_BASE?=	/usr/sbin/pkg_info
BASEPKGVER!=	${PKG_INFO_BASE} -qP 2>/dev/null

.if ${BASEPKGVER} < 20040125
RUN_DEPENDS=	${LOCALBASE}/sbin/pkg_info:${PORTSDIR}/sysutils/pkg_install-devel
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 420001 || ${OSVERSION} >= 500000 && ${OSVERSION} < 500014
IGNORE=		"You need tar with bzip support to run portaudit"
.endif

do-build:
.for f in portaudit.sh fetchaudit.sh portaudit.functions
	@${SED} -e "s|%%DATADIR%%|${DATADIR}|g" \
		-e "s|%%DATABASEDIR%%|${DATABASEDIR}|g" \
		${FILESDIR}/${f} > ${WRKDIR}/${f}
.endfor

do-install:
	@${MKDIR} ${PERIODICDIR}/security
	@${INSTALL_SCRIPT} ${WRKDIR}/portaudit.sh ${PERIODICDIR}/security/910.portaudit
	@${MKDIR} ${PERIODICDIR}/daily
	@${INSTALL_SCRIPT} ${WRKDIR}/fetchaudit.sh ${PERIODICDIR}/daily/330.fetchaudit
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKDIR}/portaudit.functions ${DATADIR}
	@${MKDIR} ${DATABASEDIR}

.include <bsd.port.post.mk>
