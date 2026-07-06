PORTNAME=	rsync
DISTVERSION=	3.4.4
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://www.mirrorservice.org/sites/rsync.samba.org/src/ \
		http://rsync.mirror.garr.it/src/ \
		http://www.mirrorservice.org/sites/rsync.samba.org/src/ \
		https://download.samba.org/pub/rsync/src/

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Network file distribution/synchronization utility
WWW=		https://rsync.samba.org/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	liblz4.so:archivers/liblz4 \
		libxxhash.so:devel/xxhash \
		libzstd.so:archivers/zstd

USES=		autoreconf:build cpe python shebangfix ssl
CPE_VENDOR=	samba
CPE_PRODUCT=	rsync
PYTHON_NO_DEPENDS=	yes
USE_RC_SUBR=	rsyncd

SHEBANG_FILES=	runtests.py support/rrsync

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--disable-debug \
		--disable-md2man \
		--enable-ipv6 \
		--with-rsyncd-conf=${ETCDIR}/rsyncd.conf

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

SUB_LIST=	NAME=rsyncd

PORTDOCS=	NEWS.md README.md csprotocol.txt tech_report.tex

# define options
OPTIONS_DEFINE=		DOCS FLAGS ICONV POPT_PORT SSH ZLIB_BASE
OPTIONS_DEFAULT=	FLAGS ICONV SSH ZLIB_BASE

# options provided upstream
POPT_PORT_DESC=	Use popt from devel/popt instead of bundled one
SSH_DESC=	Use SSH instead of RSH

FLAGS_DESC=	File system flags support patch, adds --file-flags
FLAGS_EXTRA_PATCHES=	${FILESDIR}/extra-patch-file-flags.diff
ZLIB_BASE_DESC=	Use zlib from base instead of bundled one

ICONV_USES=		iconv:translit
ICONV_CONFIGURE_ENABLE=	iconv iconv-open

POPT_PORT_LIB_DEPENDS=		libpopt.so:devel/popt
POPT_PORT_CONFIGURE_OFF=	--with-included-popt

SSH_CONFIGURE_ON=	--with-rsh=ssh
SSH_CONFIGURE_OFF=	--with-rsh=rsh

ZLIB_BASE_CONFIGURE_ON=	--with-included-zlib=no

.include <bsd.port.pre.mk>

.if empty(ICONV_LIB) || !${PORT_OPTIONS:MICONV}
CONFIGURE_ARGS+=	ac_cv_search_libiconv_open=no
.endif

post-patch:
	@${REINPLACE_CMD} -e 's:/etc/rsync/:${ETCDIR}/:g' \
					  -e 's:/etc/rsyncd:${ETCDIR}/rsyncd:g' \
					  -e 's:/etc/letsencrypt:${PREFIX}/etc/letsencrypt:g' \
					  ${WRKSRC}/rsync.1 ${WRKSRC}/rsyncd.conf.5
	@${REINPLACE_CMD} -e 's|/usr/bin/rsync|${PREFIX}/bin/rsync|g' ${WRKSRC}/support/rrsync

pre-configure:
	@(cd ${WRKSRC} && ${SETENVI} ${WRK_ENV} ${MAKE_CMD} -f prepare-source.mak)

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${FILESDIR}/rsyncd.conf.sample ${STAGEDIR}${ETCDIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/support/rrsync ${STAGEDIR}${PREFIX}/sbin

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/support/rrsync.1.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
