# Created by: Oliver Eikemeier
# $FreeBSD$

PORTNAME=	portaudit
PORTVERSION=	0.6.1
CATEGORIES=	ports-mgmt security
DISTFILES=

MAINTAINER=	ports-secteam@FreeBSD.org
COMMENT=	Checks installed ports against a list of security vulnerabilities

PERIODICDIR?=	${PREFIX}/etc/periodic
DATABASEDIR?=	/var/db/portaudit

PLIST_SUB+=	PERIODICDIR="${PERIODICDIR:S,^${PREFIX}/,,}" \
		DATABASEDIR="${DATABASEDIR}"

SUB_FILES=	pkg-message

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

.if ${OSVERSION} > 1000000
IGNORE=	use 'pkg audit' instead
.endif

do-build:
.for f in portaudit-cmd.sh portaudit.sh portaudit.1 portaudit.conf
	@${SED} ${SED_SCRIPT} ${FILESDIR}/${f} >${WRKDIR}/${f}
.endfor

post-build:
	@${SED} ${SED_SCRIPT} ${PKGDIR}/pkg-deinstall >${WRKDIR}/pkg-deinstall

do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/portaudit-cmd.sh ${STAGEDIR}${PREFIX}/sbin/portaudit
	@${INSTALL_DATA} ${WRKDIR}/portaudit.conf ${STAGEDIR}${PREFIX}/etc/portaudit.conf.sample
	@${INSTALL_DATA} ${FILESDIR}/portaudit.pubkey ${STAGEDIR}${PREFIX}/etc
	@${INSTALL_MAN} ${WRKDIR}/portaudit.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${PERIODICDIR}/security
	@${INSTALL_SCRIPT} ${WRKDIR}/portaudit.sh ${STAGEDIR}${PERIODICDIR}/security/410.portaudit
	@${MKDIR} ${STAGEDIR}${DATABASEDIR}

.include <bsd.port.post.mk>
