# New ports collection makefile for:	compat4x libraries
# Date created:		01 Aug 2001
# Whom:			Scot W. Hetzel
#
# $FreeBSD$
#

PORTNAME=	compat4x
PORTVERSION=	${COMPAT4X_PORTVERSION}
CATEGORIES=	misc
MASTER_SITES=	${COMPAT4X_MASTER_SITES}
PKGNAMESUFFIX=	-${ARCH}
DISTFILES=	${COMPAT4X_DISTFILES}
DIST_SUBDIR=	${ARCH}/${PORTVERSION}

MAINTAINER=	hetzels@westbend.net

PREFIX?=	/usr

WRKSRC=		${WRKDIR}/usr/lib/compat
NO_MTREE=	yes
NO_BUILD=	yes

TARGET_DIR=	${PREFIX}/lib/compat

INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib/compat

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
COMPAT4X_PORTVERSION=	5.0
COMPAT4X_MASTER_SITES=	ftp://current.FreeBSD.org/pub/FreeBSD/%SUBDIR%/
.if ${ARCH} == i386
MASTER_SITE_SUBDIR=	snapshots/${ARCH}/${PORTVERSION}-20010618-CURRENT/${PORTNAME}
COMPAT4X_DISTFILES=	${PORTNAME}.aa \
			${PORTNAME}.ab \
			${PORTNAME}.ac \
			${PORTNAME}.ad
.elif ${ARCH} == alpha
MASTER_SITE_SUBDIR=	snapshots/${ARCH}/${PORTVERSION}-20010721-CURRENT/${PORTNAME}
COMPAT4X_DISTFILES=	${PORTNAME}.aa \
			${PORTNAME}.ab \
			${PORTNAME}.ac \
			${PORTNAME}.ad \
			${PORTNAME}.ae
.endif
PLIST_SUB=		CURRENT_ONLY:=""
.else
COMPAT4X_PORTVERSION=	4.3
COMPAT4X_MASTER_SITES=	${MASTER_SITE_FREEBSD_ORG}
MASTER_SITE_SUBDIR=	releases/${ARCH}/${PORTVERSION}-RELEASE/${PORTNAME}
COMPAT4X_DISTFILES=	${PORTNAME}.aa \
			${PORTNAME}.ab
PLIST_SUB=		CURRENT_ONLY:="@comment "
.endif

do-extract:
	${MKDIR} ${WRKDIR}
	cd ${_DISTDIR} && ${CAT} ${DISTFILES} | ${TAR} -xzf - -C ${WRKDIR}
.if ${OSVERSION} >= 500000
	${MV} ${WRKSRC}/libc_r.so.4 ${WRKSRC}/libc_r.so.4.compat4x
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/* ${TARGET_DIR}/
.if ${OSVERSION} >= 500000
	${LN} -sf ${TARGET_DIR}/libc_r.so.4.compat4x ${TARGET_DIR}/libc_r.so.4
.endif

.include <bsd.port.post.mk>
