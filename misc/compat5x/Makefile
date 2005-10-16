# New ports collection makefile for:	compat5x libraries
# Date created:				19 Aug 2005
# Whom:					hrs, lesi
#
# $FreeBSD$
#

PORTNAME=	compat5x
PORTVERSION=	5.4.0.6
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=lesi/compat5x
PKGNAMESUFFIX=	-${ARCH}
DISTNAME=	${PORTNAME}-${ARCH}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A convenience package to install the compat5x libraries

ONLY_FOR_ARCHS=	alpha amd64 i386 sparc64
USE_BZIP2=	yes
NO_MTREE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib/compat
TARGET_DIR=	${PREFIX}/lib/compat
TARGET32_DIR=	${PREFIX}/lib32/compat
RCSCRIPT=	${WRKDIR}/000.compat5x.sh

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600000
IGNORE=	is for FreeBSD 6.x and newer
.endif

.if ${OSVERSION} >= 600016
RUN_DEPENDS=	${LOCALBASE}/share/compat/locale/UTF-8/LC_CTYPE:${PORTSDIR}/misc/localedata
.endif

.if ${ARCH} == alpha
PLIST_SUB+=	ALPHA=""
.else
PLIST_SUB+=	ALPHA="@comment "
.endif
.if ${ARCH} == amd64
PLIST_SUB+=	AMD64=""
PLIST_SUB+=	LDCONFIG_LIB32="${LDCONFIG} -32"
.else
PLIST_SUB+=	AMD64="@comment "
.endif
.if ${ARCH} == i386
PLIST_SUB+=	I386=""
.else
PLIST_SUB+=	I386="@comment "
.endif
.if ${ARCH} == sparc64
PLIST_SUB+=	SPARC64=""
.else
PLIST_SUB+=	SPARC64="@comment "
.endif

do-build:
	${ECHO_CMD} '#!/bin/sh' > ${RCSCRIPT}
	${ECHO_CMD} '${LDCONFIG} -m ${LDCONFIG_RUNLIST}' >> ${RCSCRIPT}
.if ${ARCH} == amd64
	${ECHO_CMD} '${LDCONFIG} -32 -m ${TARGET32_DIR}' >> ${RCSCRIPT}
.endif

do-install:
	${MKDIR} ${TARGET_DIR}
	(cd ${WRKSRC} && ${RM} liblwres.so.3)
	(cd ${WRKSRC} && ${INSTALL_DATA} *.so.* ${TARGET_DIR})
.if ${ARCH} == amd64
	${MKDIR} ${TARGET32_DIR}
	(cd ${WRKSRC}/lib32 && ${INSTALL_DATA} *.so.* ${TARGET32_DIR})
	${LDCONFIG} -32 -m ${TARGET32_DIR}
.endif
	${INSTALL_SCRIPT} ${RCSCRIPT} ${PREFIX}/etc/rc.d/

.include <bsd.port.post.mk>
