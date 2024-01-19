PORTNAME=	turbostat
PORTVERSION=	4.17 # Turbostat itself has a version, but we don't bother
PORTREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	https://raw.githubusercontent.com/torvalds/linux/v${PORTVERSION}/tools/power/x86/turbostat/ \
		https://raw.githubusercontent.com/torvalds/linux/v${PORTVERSION}/arch/x86/include/asm/
DISTFILES=	${PORTNAME}.c ${PORTNAME}.8 msr-index.h intel-family.h
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Report power statistics for Intel CPUs
WWW=		https://github.com/torvalds/linux/tree/master/tools/power/x86/turbostat

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	amd64

NO_WRKSUBDIR=yes
PLIST_FILES=	sbin/turbostat share/man/man8/turbostat.8.gz

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
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>
