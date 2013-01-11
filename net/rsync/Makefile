# Created by: David O'Brien (obrien@cs.ucdavis.edu)
# $FreeBSD$

PORTNAME=	rsync
PORTVERSION=	3.0.9
PORTREVISION=	3
CATEGORIES=	net ipv6
MASTER_SITES=	http://rsync.samba.org/ftp/%SUBDIR%/ \
		ftp://ftp.samba.org/pub/%SUBDIR%/ \
		ftp://ftp.sunet.se/pub/unix/admin/%SUBDIR%/  \
		ftp://ftp.fu-berlin.de/pub/unix/network/%SUBDIR%/ \
		http://www.mirrorservice.org/sites/rsync.samba.org/ \
		CRITICAL
MASTER_SITE_SUBDIR=	rsync
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A network file distribution/synchronization utility

LICENSE=	GPLv3

GNU_CONFIGURE=	yes
USE_RC_SUBR=	rsyncd
SUB_LIST=	NAME=rsyncd
MAKE_JOBS_SAFE=	yes

CONFIGURE_ARGS=	--disable-debug --enable-ipv6 \
		--with-rsyncd-conf=${PREFIX}/etc/rsyncd.conf

.if !defined(NOPORTDOCS)
PORTDOCS=	NEWS README csprotocol.txt tech_report.tex
.endif

MAN1=		rsync.1
MAN5=		rsyncd.conf.5

OPTIONS_DEFINE=	POPT_PORT SSH FLAGS ATIMES ACL ICONV TIMELIMIT RENAMED
POPT_PORT_DESC=	Use popt from devel/popt instead of bundled one
SSH_DESC=	Use SSH instead of RSH
FLAGS_DESC=	File system flags support patch, adds --fileflags
ATIMES_DESC=	Preserve access times, adds --atimes
ACL_DESC=	Add backward-compatibility for the --acls option
TIMELIMIT_DESC=	Time limit patch
RENAMED_DESC=	Add support for renamed file detection

OPTIONS_DEFAULT=SSH

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTIMELIMIT}
PATCH_STRIP=	-p1
EXTRA_PATCHES+=	${WRKSRC}/patches/time-limit.diff
.if ${PORT_OPTIONS:MFLAGS}
IGNORE=		flags and timelimit can't be enabled simultaneously. Please rerun 'make config' and disable one of them
.endif
.if ${PORT_OPTIONS:MATIMES}
IGNORE=		atimes and timelimit can't be enabled simultaneously. Please rerun 'make config' and disable one of them
.endif
.endif

.if ${PORT_OPTIONS:MATIMES}
PATCH_STRIP=	-p1
EXTRA_PATCHES+=	${WRKSRC}/patches/atimes.diff
.if ${PORT_OPTIONS:MFLAGS}
IGNORE=		flags and atimes can't be enabled simultaneously. Please rerun 'make config' and disable one of them
.endif
.endif

.if ${PORT_OPTIONS:MICONV} || ${PORT_OPTIONS:MFLAGS} || ${PORT_OPTIONS:MACL} || make(makesum) || ${PORT_OPTIONS:MTIMELIMIT} || ${PORT_OPTIONS:MATIMES} || ${PORT_OPTIONS:MRENAMED}
DISTFILES+=	${PORTNAME}-patches-${PORTVERSION}${EXTRACT_SUFX}
CFLAGS+=	-I${LOCALBASE}/include
.endif

.if ${PORT_OPTIONS:MICONV}
USE_ICONV=	yes
CONFIGUREDCFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CONFIGUREDCFLAGS="${CONFIGUREDCFLAGS}"
.else
CONFIGURE_ARGS+=	--disable-iconv
CONFIGURE_ENV+=		ac_cv_search_libiconv_open=no
CONFIGURE_ENV+=		ac_cv_header_iconv_h=no
.endif

.if ${PORT_OPTIONS:MFLAGS}
PATCH_STRIP=	-p1
EXTRA_PATCHES+=	${WRKSRC}/patches/fileflags.diff
# https://bugzilla.samba.org/show_bug.cgi?id=8941
EXTRA_PATCHES+=	${FILESDIR}/extrapatch-syscall.c
.endif

.if ${PORT_OPTIONS:MRENAMED}
PATCH_STRIP=	-p1
#EXTRA_PATCHES+=	${WRKSRC}/patches/detect-renamed.diff
EXTRA_PATCHES+=	${FILESDIR}/extrapatch-detect-renamed.diff
.endif

.if ${PORT_OPTIONS:MACL}
PATCH_STRIP=	-p1
EXTRA_PATCHES+=	${WRKSRC}/patches/acls.diff
.endif

.if ${PORT_OPTIONS:MPOPT_PORT}
LIB_DEPENDS+=	popt:${PORTSDIR}/devel/popt
CONFIGURE_ENV+=	LIBS="-L${LOCALBASE}/lib"
CFLAGS+=	-I${LOCALBASE}/include
.else
CONFIGURE_ARGS+=	--with-included-popt
.endif

.if ${PORT_OPTIONS:MSSH}
CONFIGURE_ARGS+=	--with-rsh=ssh
.else
CONFIGURE_ARGS+=	--with-rsh=rsh
.endif

# guard against CFLAGS damage by MAKE_ENV
post-patch:
	@${REINPLACE_CMD} -e 's|CFLAGS|CONFIGUREDCFLAGS|' \
		-e 's|perl.*|${DO_NADA}|' \
			${WRKSRC}/Makefile.in

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

.include <bsd.port.mk>
