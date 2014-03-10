# Created by: keith@FreeBSD.org
# $FreeBSD$

PORTNAME=	gap
PORTVERSION=	4.7.4.${GAP_DISTDATE}
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.gap-system.org/pub/gap/gap47/tar.bz2/ \
		ftp://ftp.stack.nl/pub/users/johans/gap/ \
		ftp://ftp.gap-system.org/pub/gap/gap47/old/
DISTNAME=	${GAP_VERSION}p${PORTVERSION:R:E}_${GAP_DISTTIME}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	GAP is a system for computational discrete algebra

LIB_DEPENDS=	libgmp.so:${PORTSDIR}/math/gmp

USE_BZIP2=	yes
USES=		gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-gmp=${LOCALBASE}
ALL_TARGET=	default

MAKE_JOBS_UNSAFE=yes

GAP_VERSION=	${PORTNAME}${PORTVERSION:R:R:S/./r/}	# gap4r5
GAP_DISTTIME=	2014_02_20-01_21
GAP_DISTDATE=	${GAP_DISTTIME:C/-.*//:S/_//g}
GAP_LIBDIR=	${PREFIX}/lib/${GAP_VERSION}
WRKSRC=		${WRKDIR}/${GAP_VERSION}
PLIST_FILES=	bin/gap

do-install:
	(${SED} -e "s:GAP_DIR=.*:GAP_DIR=${GAP_LIBDIR}:g" -e "s:GAP_PRG=.*:GAP_PRG=gap:g" ${WRKSRC}/bin/gap.sh > ${STAGEDIR}${PREFIX}/bin/gap; \
	${CHMOD} 755 ${STAGEDIR}${PREFIX}/bin/gap; )
	@${MKDIR} ${STAGEDIR}${GAP_LIBDIR}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/*/gap ${STAGEDIR}${GAP_LIBDIR}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/*/gac ${STAGEDIR}${GAP_LIBDIR}/bin
	@${INSTALL_DATA} ${WRKSRC}/sysinfo.gap ${STAGEDIR}${GAP_LIBDIR}
.for subdir in doc etc grp lib pkg prim small trans tst
	@${CP} -R ${WRKSRC}/${subdir} ${STAGEDIR}${GAP_LIBDIR}/
.endfor

post-install:
	@${FIND} ${STAGEDIR}${GAP_LIBDIR} -type d -empty -delete
	@${FIND} ${STAGEDIR}${GAP_LIBDIR} ! -type d | \
		${SED} 's,${STAGEDIR}${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${STAGEDIR}${GAP_LIBDIR} -type d -depth | \
		${SED} 's,${STAGEDIR}${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.mk>
