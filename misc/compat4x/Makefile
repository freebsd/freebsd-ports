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
MASTER_SITE_SUBDIR=	${COMPAT4X_MASTER_SITE_SUBDIR}
PKGNAMESUFFIX=	-${ARCH}
DISTFILES=	${COMPAT4X_DISTFILES}
DIST_SUBDIR=	${ARCH}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A convenience package to install the compat4x libraries

WRKSRC=		${WRKDIR}/usr/lib/compat
NO_MTREE=	yes

TARGET_DIR=	${PREFIX}/lib/compat

INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib/compat

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
COMPAT4X_OSVERSION=	5.0
COMPAT4X_OSBRANCH=	CURRENT
COMPAT4X_MASTER_SITES=	ftp://current.FreeBSD.org/pub/FreeBSD/%SUBDIR%/
.if ${ARCH} == i386
COMPAT4X_OSRELDATE=	20020917
COMPAT4X_DISTFILES=	${PORTNAME}.aa \
			${PORTNAME}.ab \
			${PORTNAME}.ac \
			${PORTNAME}.ad \
			${PORTNAME}.ae \
			${PORTNAME}.af
.elif ${ARCH} == alpha
FORBIDDEN=		"FreeBSD-SA-02:28.resolv - buffer overflow in resolver in libc"

COMPAT4X_OSRELDATE=	20020809
COMPAT4X_DISTFILES=	${PORTNAME}.aa \
			${PORTNAME}.ab \
			${PORTNAME}.ac \
			${PORTNAME}.ad \
			${PORTNAME}.ae \
			${PORTNAME}.af \
			${PORTNAME}.ag
.else
IGNORE=			unsupported architecture
.endif
CURRENT_ONLY=		""
.else
COMPAT4X_OSVERSION=	4.6.2
.if ${ARCH} == i386
COMPAT4X_MASTER_SITES=	${MASTER_SITE_FREEBSD_ORG}
COMPAT4X_DISTFILES=	${PORTNAME}.aa \
			${PORTNAME}.ab
.elif ${ARCH} == alpha
COMPAT4X_MASTER_SITES=	${MASTER_SITE_FREEBSD_ORG}
COMPAT4X_DISTFILES=	${PORTNAME}.aa \
			${PORTNAME}.ab
.else
IGNORE=			unsupported architecture
.endif
.endif

CURRENT_ONLY?=		"@comment "

PLIST_SUB+=		CURRENT_ONLY:=${CURRENT_ONLY}

OPENSSL_LIBS=		libcrypto.so.1 libssl.so.1
.if defined(FORCE_VULNERABLE_OPENSSL)
FORBIDDEN=		"FreeBSD-SA-02:33.openssl - openssl contains multiple vulnerabilities"

PLIST_SUB+=		FORBIDDEN:=""
.else
PLIST_SUB+=		FORBIDDEN:="@comment "
.endif

FREEBSD4_LIBS=		libc_r.so.4 libperl.so.3

.if defined(COMPAT4X_OSRELDATE) && !empty(COMPAT4X_OSRELDATE)
COMPAT4X_PORTVERSION=	${COMPAT4X_OSVERSION}.${COMPAT4X_OSRELDATE}
COMPAT4X_MASTER_SITE_SUBDIR=	snapshots/${ARCH}/${COMPAT4X_OSVERSION}-${COMPAT4X_OSBRANCH}-${COMPAT4X_OSRELDATE}-JPSNAP/${PORTNAME}
.else
COMPAT4X_PORTVERSION=	${COMPAT4X_OSVERSION}
COMPAT4X_MASTER_SITE_SUBDIR=	releases/${ARCH}/${COMPAT4X_OSVERSION}-RELEASE/${PORTNAME}
.endif

do-extract:
	${MKDIR} ${WRKDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${CAT} ${DISTFILES} | ${TAR} -xzf - -C ${WRKDIR}
.for lib in ${FREEBSD4_LIBS}
.if ${OSVERSION} >= 500000
	${MV} ${WRKSRC}/${lib} ${WRKSRC}/${lib}.compat4x
.endif
.endfor
.if !defined(FORCE_VULNERABLE_OPENSSL)
.for lib in ${OPENSSL_LIBS}
	${RM} -f ${WRKSRC}/${lib}
.endfor
.endif

do-build:
	@( ${ECHO_CMD} '#!/bin/sh'; ${ECHO_CMD} '${LDCONFIG} -m ${LDCONFIG_RUNLIST}'; \
	) > ${WRKDIR}/000.${PORTNAME}.sh

do-install:
	${MKDIR} ${TARGET_DIR} ${PREFIX}/etc/rc.d
	${INSTALL_DATA} ${WRKSRC}/* ${TARGET_DIR}/
.for lib in ${FREEBSD4_LIBS}
.if ${OSVERSION} >= 500000
	${LN} -sf ${lib}.compat4x ${TARGET_DIR}/${lib}
.endif
.endfor
	${INSTALL_SCRIPT} ${WRKDIR}/000.${PORTNAME}.sh ${PREFIX}/etc/rc.d/

.include <bsd.port.post.mk>
