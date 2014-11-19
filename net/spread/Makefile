# Created by: Anders Nordby <anders@fix.no>
# $FreeBSD$

PORTNAME=	spread
PORTVERSION=	3.17.4
PORTREVISION=	4
CATEGORIES=	net perl5
MASTER_SITES=	http://bsdforge.com/projects/source/net/spread/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	portmaster@bsdforge.com
COMMENT=	The Spread Group Communication System, a network toolkit

MAKE_JOBS_UNSAFE=	yes

GNU_CONFIGURE=	yes
USES=		perl5 tar:xz
USE_PERL5=	build fixpacklist run
USE_RC_SUBR=	spread
USE_LDCONFIG=	yes

USERS=		spread
GROUPS=		spread
RUNDIR=		/var/run/spread

PLIST_SUB+=	USERS=${USERS} GROUPS=${GROUPS} RUNDIR=${RUNDIR}

MAKE_ARGS+=	PTHREAD_CFLAGS=${PTHREAD_CFLAGS} PTHREAD_LIBS=${PTHREAD_LIBS}
WRKSRC=		${WRKDIR}/${PORTNAME}-src-${PORTVERSION}

PKGMESSAGE=	${WRKSRC}/license.txt
PORTDOCS=	Readme.txt LICENSE
HEADERFILES=	sp_func.h sp_func.h sp_events.h

.include <bsd.port.pre.mk>

# bsd.port.mk doesn't allow us to use GNU_CONFIGURE and PERL_CONFIGURE together.
PERL_CONFIGURE_ARGS=	CC="${CC}" CCFLAGS="${CFLAGS}" PREFIX="${PREFIX}" \
			INSTALLPRIVLIB="${PREFIX}/lib" INSTALLARCHLIB="${PREFIX}/lib"

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
.if !exists(${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf)
	${INSTALL_DATA} ${WRKSRC}/sample.spread.conf \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf
.endif
	${INSTALL_DATA} ${WRKSRC}/sample.spread.access_ip \
		${STAGEDIR}${PREFIX}/etc/spread.access_ip.sample
.if !exists(${STAGEDIR}${PREFIX}/etc/spread.access_ip)
	${INSTALL_DATA} ${WRKSRC}/sample.spread.access_ip \
		${STAGEDIR}${PREFIX}/etc/spread.access_ip
.endif
	(cd ${WRKSRC}/perl/Spread && ${MAKE} PREFIX=${STAGEDIR}${PREFIX} install)
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/perl/Spread/test.pl ${STAGEDIR}${EXAMPLESDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Readme.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/license.txt ${STAGEDIR}${DOCSDIR}/LICENSE
	${INSTALL} -m 750 -d ${STAGEDIR}${RUNDIR}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libspread.so.1
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libtspread.so.1
	${STRIP_CMD} ${STAGEDIR}${SITE_PERL}/${PERL_ARCH}/auto/Spread/Spread.so

.include <bsd.port.post.mk>
