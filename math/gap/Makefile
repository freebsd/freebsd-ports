# Created by: keith@FreeBSD.org
# $FreeBSD$

PORTNAME=	gap
PORTVERSION=	4.7.9.${GAP_DISTDATE}
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.gap-system.org/pub/gap/gap47/tar.bz2/ \
		ftp://ftp.stack.nl/pub/users/johans/gap/ \
		ftp://ftp.gap-system.org/pub/gap/gap47/old/
DISTNAME=	${GAP_VERSION}p${PORTVERSION:R:E}_${GAP_DISTTIME}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	GAP is a system for computational discrete algebra

LIB_DEPENDS=	libgmp.so:${PORTSDIR}/math/gmp

USES=		gmake shebangfix tar:bzip2
SHEBANG_FILES=	configure \
		pkg/GAPDoc-1.5.1/3k+1/clean \
		pkg/GAPDoc-1.5.1/doc/clean \
		pkg/GAPDoc-1.5.1/example/clean \
		pkg/PolymakeInterface/configure \
		pkg/SymbCompCC-1.2/doc/convert.pl \
		pkg/anupq-3.1.1/tst/make_anupqeg \
		pkg/crime/gap/print.pl \
		pkg/cubefree/doc/convert.pl \
		pkg/fr-2.2.1/cnf/config.status \
		pkg/hecke/doc/clean \
		pkg/io-4.4.4/doc/clean \
		pkg/liepring/doc/convert.pl \
		pkg/nilmat/doc/convert.pl \
		pkg/orb-4.7.3/doc/clean \
		pkg/pargap/mpinu/thwap \
		pkg/recog-1.2.3/doc/clean \
		pkg/recogbase-1.2.3/doc/clean \
		pkg/sglppow/doc/convert.pl \
		pkg/sonata/doc/convert.pl \
		pkg/unipot-1.2/doc/convert.pl

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-gmp=${LOCALBASE}
ALL_TARGET=	default

MAKE_JOBS_UNSAFE=yes

GAP_VERSION=	${PORTNAME}${PORTVERSION:R:R:S/./r/}	# gap4r5
GAP_DISTTIME=	2015_11_29-20_35
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
