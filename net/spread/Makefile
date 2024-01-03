PORTNAME=	spread
PORTVERSION=	3.17.4
PORTREVISION=	7
CATEGORIES=	net perl5
MASTER_SITES=	https://BSDforge.com/projects/source/net/spread/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	portmaster@bsdforge.com
COMMENT=	The Spread Group Communication System, a network toolkit
WWW=		http://www.spread.org/

LICENSE=	SPREAD_OPEN-SOURCE_LICENSE
LICENSE_NAME=	Spread Open-Source License
LICENSE_FILE=	files/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BROKEN=		Unfetchable

USES=		groff perl5 tar:xz
USE_LDCONFIG=	yes
USE_PERL5=	build run
USE_RC_SUBR=	spread

GNU_CONFIGURE=	yes
# The configure script fails to find nroff in LOCALBASE, but works fine if
# 'groff' is used directly
CONFIGURE_ENV+=	ac_cv_path_NROFF=groff

MAKE_ARGS+=	PTHREAD_LIBS="-lpthread"
MAKE_JOBS_UNSAFE=	yes

TARGET_ORDER_OVERRIDE=	710:fix-perl-things

WRKSRC=		${WRKDIR}/${PORTNAME}-src-${PORTVERSION}

USERS=		spread
GROUPS=		spread

PKGMESSAGE=	${WRKSRC}/license.txt
PLIST_SUB+=	USERS=${USERS} GROUPS=${GROUPS} RUNDIR=${RUNDIR}
PORTDOCS=	Readme.txt LICENSE

RUNDIR=		/var/run/spread

HEADERFILES=	sp_func.h sp_func.h sp_events.h

OPTIONS_DEFINE=	DOCS

# bsd.port.mk doesn't allow us to use GNU_CONFIGURE and PERL_CONFIGURE together.
PERL_CONFIGURE_ARGS=	CC="${CC}" CCFLAGS="${CFLAGS}" PREFIX="${PREFIX}" \
			INSTALLPRIVLIB="${PREFIX}/lib" INSTALLARCHLIB="${PREFIX}/lib"

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-configure:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/docs/${PORTNAME}.1 ${WRKSRC}/docs/spmonitor.1

post-build:
	@cd ${WRKSRC}/perl/Spread && \
		${SETENV} ${CONFIGURE_ENV} ${PERL5} ./Makefile.PL ${PERL_CONFIGURE_ARGS}
	@cd ${WRKSRC}/perl/Spread && \
		${PERL5} -pi -e 's/ doc_(perl|site|\$$\(INSTALLDIRS\))_install$$//' Makefile
	@cd ${WRKSRC}/perl/Spread && ${MAKE}

post-install:
.for f in ${HEADERFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/include
.endfor
	${INSTALL_DATA} ${WRKSRC}/sample.spread.conf \
		${STAGEDIR}${PREFIX}/etc/spread.conf.sample
	${INSTALL_DATA} ${WRKSRC}/sample.spread.access_ip \
		${STAGEDIR}${PREFIX}/etc/spread.access_ip.sample
	(cd ${WRKSRC}/perl/Spread && ${MAKE} PREFIX=${STAGEDIR}${PREFIX} install)
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/perl/Spread/test.pl ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL} -m 750 -d ${STAGEDIR}${RUNDIR}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libspread.so.1
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libtspread.so.1
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Spread/Spread.so

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Readme.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/license.txt ${STAGEDIR}${DOCSDIR}/LICENSE

.include <bsd.port.mk>
