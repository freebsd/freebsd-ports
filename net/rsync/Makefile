# Created by: David O'Brien (obrien@cs.ucdavis.edu)
# $FreeBSD$

PORTNAME=	rsync
PORTVERSION=	3.1.0
PORTREVISION=	1
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
COMMENT=	Network file distribution/synchronization utility

LICENSE=	GPLv3

GNU_CONFIGURE=	yes
USE_RC_SUBR=	rsyncd
SUB_LIST=	NAME=rsyncd

CONFIGURE_ARGS=	--disable-debug --enable-ipv6 \
		--with-rsyncd-conf=${PREFIX}/etc/rsyncd.conf

PORTDOCS=	NEWS README csprotocol.txt tech_report.tex

# define options
OPTIONS_DEFINE=		DOCS POPT_PORT ZLIB_BASE SSH ICONV
OPTIONS_RADIO=		PTS
OPTIONS_RADIO_PTS=	TIMELIMIT RENAMED FLAGS RENFL ATIMES ACL

# options provided upstream
POPT_PORT_DESC=	Use popt from devel/popt instead of bundled one
ZLIB_BASE_DESC=	Use zlib from base instead of bundled one
SSH_DESC=	Use SSH instead of RSH

# options provided by patch (mutually exclusive)
PTS_DESC=	Functionality provided by third party patches
TIMELIMIT_DESC=	Time limit patch
RENAMED_DESC=	Add support for renamed file detection
FLAGS_DESC=	File system flags support patch, adds --fileflags
ATIMES_DESC=	Preserve access times, adds --atimes
ACL_DESC=	Add backward-compatibility for the --acls option

# The following unsupported patch has been provided by:
# Dmitry Morozovsky <marck@rinet.ru>
RENFL_DESC=	Renamed and flags options combined

# define default options
OPTIONS_DEFAULT=SSH ZLIB_BASE

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MZLIB_BASE}
CONFIGURE_ARGS+=	--with-included-zlib=no
.endif

.if ${PORT_OPTIONS:MTIMELIMIT}
PATCH_STRIP=	-p1
EXTRA_PATCHES+=	${WRKSRC}/patches/time-limit.diff
.endif

.if ${PORT_OPTIONS:MATIMES}
PATCH_STRIP=	-p1
EXTRA_PATCHES+=	${WRKSRC}/patches/atimes.diff
.endif

.if ${PORT_OPTIONS:MICONV} || ${PORT_OPTIONS:MFLAGS} || ${PORT_OPTIONS:MACL} || make(makesum) || ${PORT_OPTIONS:MTIMELIMIT} || ${PORT_OPTIONS:MATIMES} || ${PORT_OPTIONS:MRENAMED} || ${PORT_OPTIONS:MRENFL} 
DISTFILES+=	${PORTNAME}-patches-${PORTVERSION}${EXTRACT_SUFX}
CFLAGS+=	-I${LOCALBASE}/include
.endif

.if ${PORT_OPTIONS:MICONV}
USES+=		iconv
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
EXTRA_PATCHES+=	${WRKSRC}/patches/fileflags.diff \
		${FILESDIR}/extrapatch-main.c
.endif

.if ${PORT_OPTIONS:MRENAMED}
PATCH_STRIP=	-p1
EXTRA_PATCHES+=	${WRKSRC}/patches/detect-renamed.diff
.endif

.if ${PORT_OPTIONS:MRENFL}
PATCH_STRIP=	-p1
EXTRA_PATCHES+=	\
		${FILESDIR}/extrapatch-renamed-flags.diff \
		${WRKSRC}/patches/fileflags.diff \
		${FILESDIR}/extrapatch-main.c \
		${WRKSRC}/patches/detect-renamed.diff
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
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/rsync
	@${INSTALL_DATA} ${FILESDIR}/rsyncd.conf.sample ${STAGEDIR}${PREFIX}/etc/
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
.endif

test: build
	@cd ${WRKSRC} && ${MAKE} check

.include <bsd.port.mk>
