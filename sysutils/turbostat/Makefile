# $FreeBSD$

PORTNAME=	turbostat
PORTVERSION=	4.17 # Turbostat itself has a version, but we don't bother
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://raw.githubusercontent.com/torvalds/linux/v${PORTVERSION}/tools/power/x86/turbostat/ \
		https://raw.githubusercontent.com/torvalds/linux/v${PORTVERSION}/arch/x86/include/asm/
DISTFILES=	${PORTNAME}.c ${PORTNAME}.8 msr-index.h intel-family.h
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	d.scott.phillips@intel.com
COMMENT=	Report power statistics for Intel CPUs

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	amd64

NO_WRKSUBDIR=yes
PLIST_FILES=	sbin/turbostat man/man8/turbostat.8.gz

post-extract:

do-extract:
	@${MKDIR} ${WRKSRC}
	${CP} ${_DISTDIR}/${PORTNAME}.c ${WRKSRC}
	${CP} ${_DISTDIR}/${PORTNAME}.8 ${WRKSRC}
	${CP} ${_DISTDIR}/msr-index.h ${WRKSRC}
	${CP} ${_DISTDIR}/intel-family.h ${WRKSRC}

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -DMSRHEADER='"msr-index.h"' -DINTEL_FAMILY_HEADER='"intel-family.h"' -o ${PORTNAME} ${PORTNAME}.c -lutil

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${MANPREFIX}/man/man8

.include <bsd.port.mk>
