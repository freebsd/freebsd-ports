# New ports collection makefile for:	compat3x libraries
# Date created:		01 Aug 2001
# Whom:			Scot W. Hetzel
#
# $FreeBSD$
#

PORTNAME=	compat3x
PORTVERSION=	${COMPAT3X_PORTVERSION}
CATEGORIES=	misc
MASTER_SITES=	${COMPAT3X_MASTER_SITES}
MASTER_SITE_SUBDIR=	${COMPAT3X_MASTER_SITE_SUBDIR}
PKGNAMESUFFIX=	-${ARCH}
DISTFILES=	${COMPAT3X_DISTFILES}
DIST_SUBDIR=	${ARCH}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

ONLY_FOR_ARCHS=	i386

WRKSRC=		${WRKDIR}/usr/lib/compat
NO_MTREE=	yes

TARGET_DIR=	${PREFIX}/lib/compat

INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib/compat

.include <bsd.port.pre.mk>
.if ${OSVERSION} >= 500000
COMPAT3X_OSVERSION=	5.0
COMPAT3X_OSRELDATE=	20011011
COMPAT3X_OSBRANCH=	CURRENT
COMPAT3X_MASTER_SITES=	ftp://current.FreeBSD.org/pub/FreeBSD/%SUBDIR%/
COMPAT3X_DISTFILES=	${PORTNAME}.aa \
			${PORTNAME}.ab \
			${PORTNAME}.ac \
			${PORTNAME}.ad \
			${PORTNAME}.ae \
			${PORTNAME}.af \
			${PORTNAME}.ag
PLIST_SUB=		CURRENT_ONLY:=""
.else
COMPAT3X_OSVERSION=	4.4
COMPAT3X_OSRELDATE=	20011227
COMPAT3X_OSBRANCH=	STABLE
COMPAT3X_MASTER_SITES=	ftp://stable.FreeBSD.org/pub/FreeBSD/%SUBDIR%/
COMPAT3X_DISTFILES=	${PORTNAME}.aa \
			${PORTNAME}.ab \
			${PORTNAME}.ac \
			${PORTNAME}.ad \
			${PORTNAME}.ae
PLIST_SUB=		CURRENT_ONLY:="@comment "
.endif

.if defined(COMPAT3X_OSRELDATE) && !empty(COMPAT3X_OSRELDATE)
COMPAT3X_PORTVERSION=	${COMPAT3X_OSVERSION}.${COMPAT3X_OSRELDATE}
COMPAT3X_MASTER_SITE_SUBDIR=	snapshots/${ARCH}/${COMPAT3X_OSVERSION}-${COMPAT3X_OSRELDATE}-${COMPAT3X_OSBRANCH}/${PORTNAME}
.else
COMPAT3X_PORTVERSION=	${COMPAT3X_OSVERSION}
COMPAT3X_MASTER_SITE_SUBDIR=	releases/${ARCH}/${COMPAT3X_OSVERSION}-RELEASE/${PORTNAME}
.endif

do-extract:
	${MKDIR} ${WRKDIR}
	cd ${_DISTDIR} && ${CAT} ${DISTFILES} | ${TAR} -xzf - -C ${WRKDIR}
	if [ -e ${WRKSRC}/libc_r.so.4 ]; then \
		${MV} ${WRKSRC}/libc_r.so.4 ${WRKSRC}/libc_r.so.4.compat3x; \
	fi

do-build:
	@( ${ECHO} '#!/bin/sh'; ${ECHO} '${LDCONFIG} -m ${LDCONFIG_RUNLIST}'; \
	) > ${WRKDIR}/000.${PORTNAME}.sh

do-install:
	${MKDIR} ${TARGET_DIR} ${PREFIX}/etc/rc.d
	${INSTALL_DATA} ${WRKSRC}/* ${TARGET_DIR}/
	if [ -e ${TARGET_DIR}/libc_r.so.4.compat3x -a ! -e ${TARGET_DIR}/libc_r.so.4.compat4x ]; then \
		${LN} -sf ${TARGET_DIR}/libc_r.so.4.compat3x ${TARGET_DIR}/libc_r.so.4; \
	fi
	${INSTALL_SCRIPT} ${WRKDIR}/000.${PORTNAME}.sh ${PREFIX}/etc/rc.d/

.include <bsd.port.post.mk>
