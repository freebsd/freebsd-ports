# Created by: David O'Brien (obrien@cs.ucdavis.edu)

PORTNAME=	rsync
DISTVERSION=	3.2.3
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://www.mirrorservice.org/sites/rsync.samba.org/src/ \
				http://rsync.mirror.garr.it/src/ \
				http://www.mirrorservice.org/sites/rsync.samba.org/src/ \
				https://download.samba.org/pub/rsync/src/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Network file distribution/synchronization utility

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libxxhash.so:devel/xxhash \
		libzstd.so:archivers/zstd \
		liblz4.so:archivers/liblz4

USES=		cpe shebangfix ssl
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
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	NEWS.md README.md csprotocol.txt tech_report.tex

# define options
OPTIONS_DEFINE=		DOCS POPT_PORT ZLIB_BASE SSH ICONV
OPTIONS_RADIO=		PTS
OPTIONS_RADIO_PTS=	RENAMED FLAGS

# options provided upstream
POPT_PORT_DESC=	Use popt from devel/popt instead of bundled one
ZLIB_BASE_DESC=	Use zlib from base instead of bundled one
SSH_DESC=	Use SSH instead of RSH

# options provided by patch (mutually exclusive)
PTS_DESC=	Functionality provided by third party patches
RENAMED_DESC=	Add support for renamed file detection
FLAGS_DESC=	File system flags support patch, adds --fileflags

# define default options
OPTIONS_DEFAULT=FLAGS ICONV SSH ZLIB_BASE

ZLIB_BASE_CONFIGURE_ON=	--with-included-zlib=no
FLAGS_EXTRA_PATCHES=		${WRKSRC}/patches/fileflags.diff \
				${FILESDIR}/extrapatch-main.c
RENAMED_EXTRA_PATCHES=		${WRKSRC}/patches/detect-renamed.diff

ICONV_USES=	iconv:translit
ICONV_CONFIGURE_ENABLE=	iconv iconv-open

POPT_PORT_LIB_DEPENDS=	libpopt.so:devel/popt

POPT_PORT_CONFIGURE_OFF=	--with-included-popt

SSH_CONFIGURE_ON=	--with-rsh=ssh
SSH_CONFIGURE_OFF=	--with-rsh=rsh

FLAGS_DISTFILES=	${PORTNAME}-patches-${DISTVERSION}${EXTRACT_SUFX}
ICONV_DISTFILES=	${PORTNAME}-patches-${DISTVERSION}${EXTRACT_SUFX}
RENAMED_DISTFILES=	${PORTNAME}-patches-${DISTVERSION}${EXTRACT_SUFX}

.if make(makesum)
DISTFILES+=	${PORTNAME}-patches-${DISTVERSION}${EXTRACT_SUFX}
.endif

.include <bsd.port.pre.mk>

.if empty(ICONV_LIB) || ! ${PORT_OPTIONS:MICONV}
CONFIGURE_ARGS+=ac_cv_search_libiconv_open=no
.endif

post-patch:
	@${REINPLACE_CMD} -e 's:/etc/:${ETCDIR}/:g' \
		${WRKSRC}/rsync.1 ${WRKSRC}/rsyncd.conf.5
	@${REINPLACE_CMD} -e 's|/usr/bin/rsync|${PREFIX}/bin/rsync|g' ${WRKSRC}/support/rrsync

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${FILESDIR}/rsyncd.conf.sample ${STAGEDIR}${ETCDIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/support/rrsync ${STAGEDIR}${PREFIX}/sbin

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
