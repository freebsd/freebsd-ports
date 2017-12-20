# Created by: David O'Brien (obrien@cs.ucdavis.edu)
# $FreeBSD$

PORTNAME=	rsync
PORTVERSION=	3.1.2
PORTREVISION=	8
CATEGORIES=	net ipv6
MASTER_SITES=	http://rsync.samba.org/ftp/rsync/ \
		https://rsync.samba.org/ftp/rsync/ \
		ftp://ftp.fu-berlin.de/pub/unix/network/rsync/ \
		http://www.mirrorservice.org/sites/rsync.samba.org/ \
		https://www.mirrorservice.org/sites/rsync.samba.org/ \
		LOCAL/ehaupt/rsync
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Network file distribution/synchronization utility

LICENSE=	GPLv3

USES=		cpe shebangfix
SHEBANG_FILES=	support/rrsync

CPE_VENDOR=	samba
CPE_PRODUCT=	rsync

PATCH_STRIP=	-p1
GNU_CONFIGURE=	yes
USE_RC_SUBR=	rsyncd
SUB_LIST=	NAME=rsyncd

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

CONFIGURE_ARGS=	--disable-debug --enable-ipv6 \
		--with-rsyncd-conf=${ETCDIR}/rsyncd.conf

PORTDOCS=	NEWS README csprotocol.txt tech_report.tex

# define options
OPTIONS_DEFINE=		DOCS POPT_PORT ZLIB_BASE SSH ICONV
OPTIONS_RADIO=		PTS
OPTIONS_RADIO_PTS=	TIMELIMIT RENAMED FLAGS ATIMES ACL

# options provided upstream
POPT_PORT_DESC=	Use popt from devel/popt instead of bundled one
ZLIB_BASE_DESC=	Use zlib from base instead of bundled one
SSH_DESC=	Use SSH instead of RSH

# options provided by patch (mutually exclusive)
PTS_DESC=	Functionality provided by third party patches
TIMELIMIT_DESC=	Time limit patch
RENAMED_DESC=	Add support for renamed file detection
FLAGS_DESC=	File system flags support patch, adds --fileflags
ATIMES_DESC=	Preserve access times, adds --atimes (BROKEN)
ACL_DESC=	Add backward-compatibility for the --acls option

# define default options
OPTIONS_DEFAULT=FLAGS ICONV SSH

ZLIB_BASE_CONFIGURE_ON=	--with-included-zlib=no
TIMELIMIT_EXTRA_PATCHES=	${WRKSRC}/patches/time-limit.diff
ATIMES_EXTRA_PATCHES=		${WRKSRC}/patches/atimes.diff
FLAGS_EXTRA_PATCHES=		${WRKSRC}/patches/fileflags.diff \
				${FILESDIR}/extrapatch-main.c
RENAMED_EXTRA_PATCHES=		${WRKSRC}/patches/detect-renamed.diff
ACL_EXTRA_PATCHES=		${WRKSRC}/patches/acls.diff \
				${FILESDIR}/extrapatch-acl

ICONV_USES=	iconv:translit
ICONV_CPPFLAGS=	-I${LOCALBASE}/include
ICONV_LDFLAGS=	-L${LOCALBASE}/lib
ICONV_CONFIGURE_ENABLE=	iconv iconv-open

POPT_PORT_LIB_DEPENDS=	libpopt.so:devel/popt
POPT_PORT_CPPFLAGS=	-I${LOCALBASE}/include
POPT_PORT_LDFLAGS=	-L${LOCALBASE}/lib

POPT_PORT_CONFIGURE_OFF=	--with-included-popt

SSH_CONFIGURE_ON=	--with-rsh=ssh
SSH_CONFIGURE_OFF=	--with-rsh=rsh

ACL_DISTFILES=		${PORTNAME}-patches-${PORTVERSION}${EXTRACT_SUFX}
ATIMES_DISTFILES=	${PORTNAME}-patches-${PORTVERSION}${EXTRACT_SUFX}
FLAGS_DISTFILES=	${PORTNAME}-patches-${PORTVERSION}${EXTRACT_SUFX}
ICONV_DISTFILES=	${PORTNAME}-patches-${PORTVERSION}${EXTRACT_SUFX}
RENAMED_DISTFILES=	${PORTNAME}-patches-${PORTVERSION}${EXTRACT_SUFX}
TIMELIMIT_DISTFILES=	${PORTNAME}-patches-${PORTVERSION}${EXTRACT_SUFX}

.if make(makesum)
DISTFILES+=	${PORTNAME}-patches-${PORTVERSION}${EXTRACT_SUFX}
.endif

.include <bsd.port.pre.mk>

.if empty(ICONV_LIB) || ! ${PORT_OPTIONS:MICONV}
CONFIGURE_ARGS+=ac_cv_search_libiconv_open=no
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|perl.*|${DO_NADA}|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's:/etc/:${ETCDIR}/:g'  \
		${WRKSRC}/rsync.h ${WRKSRC}/rsync.1 ${WRKSRC}/rsyncd.conf.5
	@${REINPLACE_CMD} -e 's|/usr/bin/rsync|${PREFIX}/bin/rsync|g' ${WRKSRC}/support/rrsync

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${FILESDIR}/rsyncd.conf.sample ${STAGEDIR}${ETCDIR}/
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/support/rrsync ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.post.mk>
