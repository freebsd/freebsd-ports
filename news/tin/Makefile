PORTNAME=	tin
DISTVERSION=	2.6.3
PORTREVISION=	1
CATEGORIES=	news
MASTER_SITES=	https://ftp.icm.edu.pl/pub/unix/news/tin/v${DISTVERSION:R}/ \
		ftp://ftp.tin.org/pub/news/clients/tin/v${DISTVERSION:R}/

MAINTAINER=	kbowling@FreeBSD.org
COMMENT=	Easy-to-use threaded newsreader with NOV/NNTP support
WWW=		http://www.tin.org/

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libicuuc.so:devel/icu \
		libpcre2-8.so:devel/pcre2 \
		libuu.so:converters/uulib
RUN_DEPENDS=	${LOCALBASE}/etc/mime.types:misc/mime-support

USES=		gmake iconv localbase:ldflags ncurses pkgconfig shebangfix \
		tar:xz
SHEBANG_FILES=	tools/*.pl

GNU_CONFIGURE=	yes

TIN_EDITOR?=	/usr/bin/ee
TIN_SCREEN?=	ncursesw

ALL_TARGET=	build

CFLAGS+=	-DNNTP_SERVER_FILE=\\\"${PREFIX}/etc/nntpserver\\\"
MAKE_ARGS+=	MAKE=${MAKE_CMD}

CONFIGURE_ARGS=		--with-editor=${TIN_EDITOR} \
			--with-libdir=${PREFIX}/news/lib \
			--with-spooldir=/var/news \
			--with-screen=${TIN_SCREEN} \
			--with-pcre2-config=${PREFIX}/bin/pcre2-config \
			--with-nntp-default-server=news \
			--enable-break-long-lines \
			--with-mime-default-charset=US-ASCII \
			--with-defaults-dir=${PREFIX}/etc \
			--enable-ipv6 \
			${ICONV_CONFIGURE_ARG}

OPTIONS_DEFINE=		CANLOCK GNUPG ISPELL METAMAIL NLS NNTP_ONLY \
			NNTPS SLRNFACE
OPTIONS_DEFAULT=	GNUPG ISPELL METAMAIL NNTPS
OPTIONS_SUB=		yes

CANLOCK_DESC=		Enable Cancel-Lock key support via libcanlock
METAMAIL_DESC=		Use metamail to handle MIME attachments
NNTP_ONLY_DESC=		Only read news via NNTP (no spool dir support)
NNTPS_DESC=		Enable NNTPS
SLRNFACE_DESC=		Use slrnface to displace sender images

CANLOCK_CONFIGURE_ENABLE=	cancel-locks

ISPELL_RUN_DEPENDS=		ispell:textproc/aspell-ispell
ISPELL_CONFIGURE_ON=		--with-ispell=${LOCALBASE}/bin/ispell

GNUPG_RUN_DEPENDS=		gpg:security/gnupg
GNUPG_CONFIGURE_ON=		--with-gpg=${LOCALBASE}/bin/gpg \
				--without-pgp \
				--without-pgpk
GNUPG_CONFIGURE_OFF=		--disable-pgp-gpg

METAMAIL_RUN_DEPENDS=		metamail:mail/metamail
METAMAIL_CONFIGURE_ON=		--with-metamail=${LOCALBASE}/bin/metamail

NLS_USES=			gettext
NLS_CONFIGURE_ENABLE=		nls

NNTP_ONLY_CONFIGURE_ENABLE=	nntp-only

NNTPS_USES=			ssl
NNTPS_CONFIGURE_ON=		--with-nntps

SLRNFACE_BUILD_DEPENDS=		slrnface:news/slrnface
SLRNFACE_RUN_DEPENDS=		slrnface:news/slrnface
SLRNFACE_CONFIGURE_WITH=	slrnface=slrnface

post-patch:
	${REINPLACE_CMD} -Ee 's:5/(mmdf|mbox):5/tin_\1:g' \
	    ${WRKSRC}/src/Makefile.in
	${REINPLACE_CMD} -e 's:/var/spool/news:/var/news:g' \
	    -e 's:/etc/nntpserver:${PREFIX}/etc/nntpserver:g' \
	    -e 's:/usr/lib/news:${PREFIX}/news/lib:g' \
	    -e 's:/etc/mime\.types:${PREFIX}/etc/mime.types:g' \
	    -e 's:url_handler\.pl:tinurl_handler.pl:g' \
	    ${WRKSRC}/doc/tin.1 ${WRKSRC}/doc/tin.5
	${REINPLACE_CMD} \
	    -e 's:/etc/mime\.types:${PREFIX}/etc/mime.types:g' \
	    ${WRKSRC}/src/mimetypes.c
	${REINPLACE_CMD} \
	    -e 's:url_handler\.pl:tinurl_handler.pl:g' \
	    ${WRKSRC}/src/Makefile.in ${WRKSRC}/include/tin.h
	${MV} ${WRKSRC}/tools/url_handler.pl \
	    ${WRKSRC}/tools/tinurl_handler.pl

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/tin.defaults \
	    ${STAGEDIR}${PREFIX}/etc/tin.defaults.sample
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/tin
	${RLN} tin ${STAGEDIR}${PREFIX}/bin/rtin

.include <bsd.port.mk>
