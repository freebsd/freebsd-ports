# New ports collection makefile for:	portaudit
# Date created:				25 Jan 2004
# Whom:					Oliver Eikemeier
#
# $FreeBSD$
#

PORTNAME=	portaudit
PORTVERSION=	0.3
CATEGORIES=	security
DISTFILES=

MAINTAINER=	eik@FreeBSD.org
COMMENT=	Checks installed ports against a list of security vulnerabilities

MAN1=		portaudit.1

PERIODICDIR?=	${PREFIX}/etc/periodic
DATABASEDIR?=	/var/db/portaudit

PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall

PLIST_SUB+=	PERIODICDIR="${PERIODICDIR:S,^${PREFIX}/,,}" \
		DATABASEDIR="${DATABASEDIR}"

SED_SCRIPT=	-e 's,%%PREFIX%%,${PREFIX},g' \
		-e 's,%%DATABASEDIR%%,${DATABASEDIR},g'

PKG_INFO_BASE?=	/usr/sbin/pkg_info
BASEPKGVER!=	${PKG_INFO_BASE} -qP 2>/dev/null

.if ${BASEPKGVER} < 20040125
RUN_DEPENDS=	${LOCALBASE}/sbin/pkg_info:${PORTSDIR}/sysutils/pkg_install-devel
.endif

.include <bsd.port.pre.mk>

.if defined(BZIP2DEPENDS)
RUN_DEPENDS+=	bzip2:${PORTSDIR}/archivers/bzip2
.endif

do-build:
.for f in portaudit-cmd.sh portaudit.sh fetchaudit.sh portaudit.functions portaudit.1 portaudit.conf
	@${SED} -e "s|%%DATADIR%%|${DATADIR}|g" \
		-e "s|%%DATABASEDIR%%|${DATABASEDIR}|g" \
		-e "s|%%PREFIX%%|${PREFIX}|g" \
		-e "s|%%LOCALBASE%%|${LOCALBASE}|g" \
		-e "s|%%PORTVERSION%%|${PORTVERSION}|g" \
		-e "s|%%BZIP2_CMD%%|${BZIP2_CMD}|g" \
		${FILESDIR}/${f} > ${WRKDIR}/${f}
.endfor

post-build:
.for text in pkg-install pkg-deinstall
	@if [ -f ${PKGDIR}/${text} ]; then \
		${SED} ${SED_SCRIPT} ${PKGDIR}/${text} >${WRKDIR}/${text}; \
	fi
.endfor

do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/portaudit-cmd.sh ${PREFIX}/bin/portaudit
	@${INSTALL_MAN} ${WRKDIR}/portaudit.1 ${MAN1PREFIX}/man/man1
	@${MKDIR} ${PERIODICDIR}/security
	@${INSTALL_SCRIPT} ${WRKDIR}/portaudit.sh ${PERIODICDIR}/security/910.portaudit
	@${MKDIR} ${PERIODICDIR}/daily
	@${INSTALL_SCRIPT} ${WRKDIR}/fetchaudit.sh ${PERIODICDIR}/daily/330.fetchaudit
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKDIR}/portaudit.functions ${DATADIR}
	@${INSTALL_DATA} ${WRKDIR}/portaudit.conf ${PREFIX}/etc/portaudit.conf.sample
	@${MKDIR} ${DATABASEDIR}

post-install:
	@if [ -f ${PKGINSTALL} ]; then \
		${SETENV} "PKG_PREFIX=${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL; \
	fi

.include <bsd.port.post.mk>
