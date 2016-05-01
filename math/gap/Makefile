# Created by: keith@FreeBSD.org
# $FreeBSD$

PORTNAME=	gap
PORTVERSION=	4.8.3.${GAP_DISTDATE}
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.gap-system.org/pub/gap/gap48/tar.bz2/ \
		ftp://ftp.stack.nl/pub/users/johans/gap/ \
		ftp://ftp.gap-system.org/pub/gap/gap48/old/
DISTNAME=	${GAP_VERSION}p${PORTVERSION:R:E}_${GAP_DISTTIME}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	GAP is a system for computational discrete algebra

LIB_DEPENDS=	libgmp.so:math/gmp

BROKEN_powerpc64=	Does not build

USES=		gmake shebangfix tar:bzip2
SHEBANG_FILES=	configure \
		pkg/GAPDoc-*/*/clean \
		pkg/*/doc/clean \
		pkg/PolymakeInterface/configure \
		pkg/*/doc/convert.pl \
		pkg/anupq-*/tst/make_anupqeg \
		pkg/crime/gap/print.pl \
		pkg/fr-*/cnf/config.status \
		pkg/pargap/mpinu/thwap

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-gmp=${LOCALBASE}
ALL_TARGET=	default

MAKE_JOBS_UNSAFE=yes

GAP_VERSION=	${PORTNAME}${PORTVERSION:R:R:S/./r/}	# gap4r5
GAP_DISTTIME=	2016_03_19-22_17
GAP_DISTDATE=	${GAP_DISTTIME:C/-.*//:S/_//g}
GAP_LIBDIR=	${PREFIX}/lib/${GAP_VERSION}
WRKSRC=		${WRKDIR}/${GAP_VERSION}
PLIST_FILES=	bin/gap

post-patch:
	@${REINPLACE_CMD} -i '' -e '1s|/usr/bin/sh|/bin/sh|' ${WRKSRC}/pkg/happrime/make_tarball

do-install:
	${SED} -e "s:GAP_DIR=.*:GAP_DIR=${GAP_LIBDIR}:g" \
		-e "s:GAP_PRG=.*:GAP_PRG=gap:g" ${WRKSRC}/bin/gap.sh \
		> ${STAGEDIR}${PREFIX}/bin/gap
	@${CHMOD} 755 ${STAGEDIR}${PREFIX}/bin/gap
	@${MKDIR} ${STAGEDIR}${GAP_LIBDIR}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/*/gap ${STAGEDIR}${GAP_LIBDIR}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/*/gac ${STAGEDIR}${GAP_LIBDIR}/bin
	${INSTALL_DATA} ${WRKSRC}/sysinfo.gap ${STAGEDIR}${GAP_LIBDIR}
.for subdir in doc etc grp lib pkg prim small trans tst
	${CP} -R ${WRKSRC}/${subdir} ${STAGEDIR}${GAP_LIBDIR}/
.endfor

post-install:
	@${FIND} ${STAGEDIR}${GAP_LIBDIR} -type d -empty -delete
	@${FIND} ${STAGEDIR}${GAP_LIBDIR} ! -type d | \
		${SED} 's,${STAGEDIR}${PREFIX}/,,' >> ${TMPPLIST}

.include <bsd.port.mk>
