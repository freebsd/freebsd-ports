# New ports collection makefile for:	compat22 libraries
# Date created:		01 Aug 2001
# Whom:			Scot W. Hetzel
#
# $FreeBSD$
#

PORTNAME=	compat22
PORTVERSION=	4.3
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_FREEBSD_ORG}
MASTER_SITE_SUBDIR=	releases/${ARCH}/${PORTVERSION}-RELEASE/${PORTNAME}
PKGNAMESUFFIX=	-${ARCH}
DISTFILES=	${PORTNAME}.aa \
		${PORTNAME}.ab \
		${PORTNAME}.ac \
		${PORTNAME}.ad \
		${PORTNAME}.ae
DIST_SUBDIR=	${ARCH}/${PORTVERSION}

MAINTAINER=	hetzels@westbend.net

ONLY_FOR_ARCHS=	i386
PORTOBJFORMAT=	aout

PREFIX?=	/usr

WRKSRC=		${WRKDIR}/usr/lib/compat/aout
NO_MTREE=	yes
NO_BUILD=	yes

TARGET_DIR=	${PREFIX}/lib/compat/aout

INSTALLS_SHLIB=	yes
LDCONFIG=	/sbin/ldconfig -aout
LDCONFIG_DIRS=	%%PREFIX%%/lib/compat/aout

do-extract:
	${MKDIR} ${WRKDIR}
	cd ${_DISTDIR} && ${CAT} ${DISTFILES} | ${TAR} -xzf - -C ${WRKDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/* ${TARGET_DIR}/
	${INSTALL_DATA} ${WRKDIR}/usr/libexec/ld.so ${PREFIX}/libexec/

.include <bsd.port.mk>
