# New ports collection makefile for:	compat3x libraries
# Date created:		01 Aug 2001
# Whom:			Scot W. Hetzel
#
# $FreeBSD$
#

PORTNAME=	compat3x
PORTVERSION=	4.3
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_FREEBSD_ORG}
MASTER_SITE_SUBDIR=	releases/${ARCH}/${PORTVERSION}-RELEASE/${PORTNAME}
PKGNAMESUFFIX=	-${ARCH}
DISTFILES=	${PORTNAME}.aa \
		${PORTNAME}.ab \
		${PORTNAME}.ac \
		${PORTNAME}.ad \
		${PORTNAME}.ae \
		${PORTNAME}.af
DIST_SUBDIR=	${ARCH}/${PORTVERSION}

MAINTAINER=	hetzels@westbend.net

ONLY_FOR_ARCHS=	i386

PREFIX?=	/usr

WRKSRC=		${WRKDIR}/usr/lib/compat
NO_MTREE=	yes
NO_BUILD=	yes

TARGET_DIR=	${PREFIX}/lib/compat

INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib/compat

do-extract:
	${MKDIR} ${WRKDIR}
	cd ${_DISTDIR} && ${CAT} ${DISTFILES} | ${TAR} -xzf - -C ${WRKDIR}
	${MV} ${WRKSRC}/libc_r.so.4 ${WRKSRC}/libc_r.so.4.compat3x

do-install:
	${INSTALL_DATA} ${WRKSRC}/* ${TARGET_DIR}/
	if [ ! -e ${TARGET_DIR}/libc_r.so.4.compat4x ]; then \
		${LN} -sf ${TARGET_DIR}/libc_r.so.4.compat3x ${TARGET_DIR}/libc_r.so.4; \
	fi

.include <bsd.port.mk>
