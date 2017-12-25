# Created by: obrien@cs.ucdavis.edu
# $FreeBSD$

PORTNAME=	tin
PORTVERSION=	2.4.2
PORTREVISION?=	0 # keep for chinese/tin
CATEGORIES+=	news ipv6
MASTER_SITES=	ftp://ftp.tin.org/pub/news/clients/tin/v${PORTVERSION:R}/ \
		ftp://ftp.sunet.se/pub/news/readers/tin/v${PORTVERSION:R}/ \
		ftp://sunsite.icm.edu.pl/pub/unix/news/tin/v${PORTVERSION:R}/ \
		ftp://ftp.ka.nu/pub/news/clients/tin/v${PORTVERSION:R}/ \
		ftp://ftp.tau.ac.il/pub/unix/news/tin/v${PORTVERSION:R}/ \
		ftp://ftp.cuhk.edu.hk/pub/packages/news/tin/v${PORTVERSION:R}/ \
		ftp://ftp.funet.fi/pub/unix/news/tin-unoff/ \
		ftp://ftp.lip6.fr/pub/unix/news/readers/tin-unoff/ \
		ftp://ftp.karlsruhe.org/pub/news/clients/tin/v${PORTVERSION:R}/ \
		ftp://ftp.akk.uni-karlsruhe.de/pub/news/clients/tin/v${PORTVERSION:R}/ \
		ftp://ftp.cs.tu-berlin.de/pub/net/news/tin/v${PORTVERSION:R}/ \
		ftp://ftp.informatik.uni-hamburg.de/pub/soft/news/tin/v${PORTVERSION:R}/

MAINTAINER?=	johans@FreeBSD.org
COMMENT=	Easy-to-use threaded newsreader with NOV/NNTP support

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libuu.so:converters/uulib \
		libicuuc.so:devel/icu \
		libpcre.so:devel/pcre
RUN_DEPENDS=	${LOCALBASE}/etc/mime.types:misc/mime-support

USES=		gmake iconv ncurses shebangfix tar:bzip2
GNU_CONFIGURE=	yes
SHEBANG_FILES=	tools/opt-case.pl tools/tinews.pl tools/url_handler.pl \
		tools/w2r.pl
TIN_EDITOR?=	/usr/bin/ee
TIN_SCREEN?=	ncursesw

OPTIONS_DEFINE=		GNUPG ISPELL METAMAIL CANLOCK NNTP_ONLY SLRNFACE NLS
OPTIONS_DEFAULT=	GNUPG ISPELL METAMAIL
OPTIONS_SUB=		yes
NNTP_ONLY_DESC=		Only read news via NNTP (no spool dir support)
NNTP_ONLY_CONFIGURE_ENABLE=nntp-only
GNUPG_RUN_DEPENDS=	gpg:security/gnupg
GNUPG_CONFIGURE_ON=	--with-gpg=${PREFIX}/bin/gpg \
			--without-pgp --without-pgpk
GNUPG_CONFIGURE_OFF=	--disable-pgp-gpg
ISPELL_RUN_DEPENDS=	ispell:textproc/aspell-ispell
ISPELL_CONFIGURE_ARGS=	--with-ispell=${PREFIX}/bin/ispell
METAMAIL_DESC?=		Use metamail to handle MIME attachments
METAMAIL_RUN_DEPENDS=	metamail:mail/metamail
METAMAIL_CONFIGURE_ARGS=--with-metamail=${PREFIX}/bin/metamail
CANLOCK_DESC=		Enable Cancel-Lock key support via libcanlock
CANLOCK_CONFIGURE_ENABLE=cancel-locks
NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext
SLRNFACE_DESC?=		Use slrnface to displace sender images
SLRNFACE_CONFIGURE_WITH=	slrnface=slrnface
SLRNFACE_BUILD_DEPENDS=	slrnface:news/slrnface
SLRNFACE_RUN_DEPENDS=	slrnface:news/slrnface

# --with-mime-default-charset=US-ASCII needed to build tin in the non-ascii
# national environment.
CONFIGURE_ARGS+=--with-nntp-default-server=news \
		--with-spooldir=/var/news \
		--with-libdir=${PREFIX}/news/lib \
		--with-defaults-dir=${PREFIX}/etc \
		--with-editor=${TIN_EDITOR} \
		--with-pcre=yes \
		--with-screen=${TIN_SCREEN} \
		--enable-break-long-lines \
		${ICONV_CONFIGURE_ARG} \
		--with-mime-default-charset=US-ASCII \
		--enable-ipv6
MAKE_ARGS+=	MAKE=${MAKE_CMD}
CFLAGS+=	-DNNTP_SERVER_FILE=\\\"${PREFIX}/etc/nntpserver\\\"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
ALL_TARGET=	build

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
	${MV}   ${WRKSRC}/tools/url_handler.pl \
		${WRKSRC}/tools/tinurl_handler.pl

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/tin.defaults \
		${STAGEDIR}${PREFIX}/etc/tin.defaults.sample
	ln -sf tin ${STAGEDIR}${PREFIX}/bin/rtin

.include <bsd.port.mk>
