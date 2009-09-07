# Ports collection makefile for:  rsync
# Date created:			  Sat Aug 3, 1996
# Whom:				  David O'Brien (obrien@cs.ucdavis.edu)
#
# $FreeBSD$
#

PORTNAME=	rsync
PORTVERSION=	3.0.6
CATEGORIES=	net ipv6
MASTER_SITES=	http://rsync.samba.org/ftp/%SUBDIR%/ \
		ftp://ftp.samba.org/pub/%SUBDIR%/ \
		ftp://sunsite.auc.dk/pub/unix/%SUBDIR%/  \
		ftp://ftp.sunet.se/pub/unix/admin/%SUBDIR%/  \
		ftp://ftp.fu-berlin.de/pub/unix/network/%SUBDIR%/ \
		http://www.mirrorservice.org/sites/rsync.samba.org/ \
		CRITICAL
MASTER_SITE_SUBDIR=	rsync
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A network file distribution/synchronization utility

GNU_CONFIGURE=	yes
USE_RC_SUBR=	rsyncd.sh
SUB_LIST=	NAME=rsyncd
MAKE_JOBS_SAFE=	yes

CONFIGURE_ARGS=	--disable-debug --enable-ipv6 \
		--with-rsyncd-conf=${PREFIX}/etc/rsyncd.conf

.if !defined(NOPORTDOCS)
PORTDOCS=	NEWS README csprotocol.txt tech_report.tex
.endif

MAN1=		rsync.1
MAN5=		rsyncd.conf.5

OPTIONS=	POPT_PORT "Use popt from devel/popt instead of bundled one" off \
		SSH       "Use SSH instead of RSH" on \
		FLAGS     "File system flags support patch, adds --fileflags" off \
		ATIMES    "Preserve access times, adds --atimes" off \
		ACL       "Add backward-compatibility for the --acls option" off \
		ICONV     "Add iconv support" off \
		TIMELIMIT "Time limit patch" off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_TIMELIMIT)
PATCH_STRIP=	-p1
EXTRA_PATCHES+=	${WRKSRC}/patches/time-limit.diff
.if defined(WITH_FLAGS)
IGNORE=		flags and timelimit can't be both enabled at the same time. Please rerun 'make config' and disable one of them
.endif
.if defined(WITH_ATIMES)
IGNORE=		atimes and timelimit can't be enabled simultaneously. Please rerun 'make config' and disable one of them
.endif
.endif

.if !defined(WITHOUT_ATIMES)
PATCH_STRIP=	-p1
EXTRA_PATCHES+=	${WRKSRC}/patches/atimes.diff
.if defined(WITH_FLAGS)
IGNORE=		flags and atimes can't be enabled simultaneously. Please rerun 'make config' and disable one of them
.endif
.endif

.if defined(WITH_ICONV) || defined(WITH_FLAGS) || defined(WITH_ACL) || make(makesum) || defined(WITH_TIMELIMIT) || defined(WITH_ATIMES)
DISTFILES+=	${PORTNAME}-patches-${PORTVERSION}${EXTRACT_SUFX}
CFLAGS+=	-I${LOCALBASE}/include
.endif

.if defined(WITH_ICONV)
USE_ICONV=	yes
CONFIGUREDCFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS}" CONFIGUREDCFLAGS="${CONFIGUREDCFLAGS}"
.else
CONFIGURE_ARGS+=	--disable-iconv
CONFIGURE_ENV+=		ac_cv_search_libiconv_open=no
CONFIGURE_ENV+=		ac_cv_header_iconv_h=no
.endif

.if defined(WITH_FLAGS)
PATCH_STRIP=	-p1
EXTRA_PATCHES+=	${WRKSRC}/patches/fileflags.diff
.endif

.if defined(WITH_ACL)
PATCH_STRIP=	-p1
EXTRA_PATCHES+=	${WRKSRC}/patches/acls.diff
.endif

.if defined(WITH_POPT_PORT)
LIB_DEPENDS+=	popt.0:${PORTSDIR}/devel/popt
CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
.else
CONFIGURE_ARGS+=	--with-included-popt
.endif

.if defined(WITHOUT_SSH)
CONFIGURE_ARGS+=	--with-rsh=rsh
.endif

# guard against CFLAGS damage by MAKE_ENV
post-patch:
	@${REINPLACE_CMD} -e 's|CFLAGS|CONFIGUREDCFLAGS|' ${WRKSRC}/Makefile.in

pre-configure:
	@${REINPLACE_CMD} -e 's:/etc/:${PREFIX}/etc/:g'  \
		${WRKSRC}/rsync.h ${WRKSRC}/rsync.1 ${WRKSRC}/rsyncd.conf.5
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|g' \
		${WRKSRC}/rsync.h ${WRKSRC}/zlib/zutil.h

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/rsync
	@${INSTALL_DATA} ${FILESDIR}/rsyncd.conf.sample ${PREFIX}/etc/
	@[ -f ${PREFIX}/etc/rsyncd.conf ] || \
		${CP} ${PREFIX}/etc/rsyncd.conf.sample \
		${PREFIX}/etc/rsyncd.conf
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

test: build
	@cd ${WRKSRC} && ${MAKE} check

.include <bsd.port.post.mk>
