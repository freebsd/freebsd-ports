# New ports collection makefile for:	compat3x libraries
# Date created:		01 Aug 2001
# Whom:			Scot W. Hetzel
#
# $FreeBSD$
#

PORTNAME=	compat3x
PORTVERSION=	${COMPAT3X_PORTVERSION}
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.mk.bsdclub.org/pub/FreeBSD/distfiles/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	motoyuki
PKGNAMESUFFIX=	-${ARCH}
DISTNAME=	${PORTNAME}-${COMPAT3X_OSRELDATE}
DIST_SUBDIR=	${ARCH}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A convenience package to install the compat3x libraries

FORBIDDEN=	"FreeBSD-SA-03:05.xdr, FreeBSD-SA-03:08.realpath  - not fixed / no lib available"

ONLY_FOR_ARCHS=	i386

NO_WRKSUBDIR=	yes
NO_MTREE=	yes

TARGET_DIR=	${PREFIX}/lib/compat

INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib/compat

.include <bsd.port.pre.mk>
.if ${OSVERSION} >= 500000
COMPAT3X_OSVERSION=	5.0
COMPAT3X_OSRELDATE=	20020925
PLIST_SUB=		CURRENT_ONLY:=""
.else
COMPAT3X_OSVERSION=	4.4
COMPAT3X_OSRELDATE=	20020925
PLIST_SUB=		CURRENT_ONLY:="@comment "
.endif

FREEBSD4_LIBS=	libc_r.so.4 libperl.so.3

.if defined(COMPAT3X_OSRELDATE) && !empty(COMPAT3X_OSRELDATE)
COMPAT3X_PORTVERSION=	${COMPAT3X_OSVERSION}.${COMPAT3X_OSRELDATE}
.else
COMPAT3X_PORTVERSION=	${COMPAT3X_OSVERSION}
.endif

post-extract:
.for lib in ${FREEBSD4_LIBS}
.if ${OSVERSION} >= 500000
	${MV} ${WRKSRC}/${lib} ${WRKSRC}/${lib}.compat3x
.else
	${RM} -f ${WRKSRC}/${lib}
.endif
.endfor

do-build:
	@( ${ECHO_CMD} '#!/bin/sh'; ${ECHO_CMD} '${LDCONFIG} -m ${LDCONFIG_RUNLIST}'; \
	) > ${WRKDIR}/000.${PORTNAME}.sh

do-install:
	${MKDIR} ${TARGET_DIR} ${PREFIX}/etc/rc.d
	${INSTALL_DATA} ${WRKSRC}/lib*.so.* ${TARGET_DIR}/
.for lib in ${FREEBSD4_LIBS}
	cd ${TARGET_DIR}; \
	if [ -e ${lib}.compat3x -a ! -e ${lib}.compat4x ]; then \
		${LN} -sf ${lib}.compat3x ${lib}; \
	fi
.endfor
	${INSTALL_SCRIPT} ${WRKDIR}/000.${PORTNAME}.sh ${PREFIX}/etc/rc.d/

.include <bsd.port.post.mk>
