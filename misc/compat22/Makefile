# New ports collection makefile for:	compat22 libraries
# Date created:		01 Aug 2001
# Whom:			Scot W. Hetzel
#
# $FreeBSD$
#

PORTNAME=	compat22
PORTVERSION=	4.6.2
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

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A convenience package to install the compat22 libraries

FORBIDDEN=	"FreeBSD-SA-03:05.xdr, FreeBSD-SA-03:08.realpath  - not fixed"
DEPRECATED=	"no longer needed by any FreeBSD port"

ONLY_FOR_ARCHS=	i386
PORTOBJFORMAT=	aout

WRKSRC=		${WRKDIR}/usr/lib/compat/aout
NO_MTREE=	yes

TARGET_DIR=	${PREFIX}/lib/compat/aout

INSTALLS_SHLIB=	yes
LDCONFIG=	/sbin/ldconfig -aout
LDCONFIG_DIRS=	%%PREFIX%%/lib/compat/aout

.include <bsd.port.pre.mk>

do-extract:
	${MKDIR} ${WRKDIR}
	cd ${_DISTDIR} && ${CAT} ${DISTFILES} | ${TAR} -xzf - -C ${WRKDIR}

do-build:
	@( ${ECHO_CMD} '#!/bin/sh'; ${ECHO_CMD} '${LDCONFIG} -m ${LDCONFIG_RUNLIST}'; \
	) > ${WRKDIR}/000.${PORTNAME}.sh

do-install:
	${MKDIR} ${TARGET_DIR} ${PREFIX}/libexec ${PREFIX}/etc/rc.d
	${INSTALL_DATA} ${WRKSRC}/* ${TARGET_DIR}/
	${INSTALL_DATA} ${WRKDIR}/usr/libexec/ld.so ${PREFIX}/libexec/
	${INSTALL_SCRIPT} ${WRKDIR}/000.${PORTNAME}.sh ${PREFIX}/etc/rc.d/

.include <bsd.port.post.mk>
