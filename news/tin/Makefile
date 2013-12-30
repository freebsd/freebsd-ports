# Created by: obrien@cs.ucdavis.edu
# $FreeBSD$

PORTNAME=	tin
PORTVERSION=	2.2.0
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

LIB_DEPENDS=	libuu.so:${PORTSDIR}/converters/uulib \
		libpcre.so:${PORTSDIR}/devel/pcre
RUN_DEPENDS=	${LOCALBASE}/etc/mime.types:${PORTSDIR}/misc/mime-support

USE_BZIP2=	yes
USES=		gmake iconv shebangfix
GNU_CONFIGURE=	yes
SHEBANG_FILES=	tools/opt-case.pl tools/tinews.pl tools/url_handler.pl \
		tools/w2r.pl
TIN_EDITOR?=	/usr/bin/ee
TIN_SCREEN?=	ncursesw

OPTIONS_DEFINE=	GNUPG ISPELL METAMAIL CANLOCK NNTP_ONLY
OPTIONS_DEFAULT=GNUPG ISPELL METAMAIL
CANLOCK_DESC=	Enable Cancel-Lock key support via libcanlock
NNTP_ONLY=	Only read news via NNTP (no spool dir support)

.include <bsd.port.options.mk>

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
MAKE_ARGS+=	MAKE=${GMAKE}
CFLAGS+=	-DNNTP_SERVER_FILE=\\\"${PREFIX}/etc/nntpserver\\\"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
ALL_TARGET=	build

.if ${PORT_OPTIONS:MNNTP_ONLY}
CONFIGURE_ARGS+=	--enable-nntp-only
.endif

.if ${PORT_OPTIONS:MGNUPG}
RUN_DEPENDS+=		gpg:${PORTSDIR}/security/gnupg
CONFIGURE_ARGS+=	--with-gpg=${PREFIX}/bin/gpg \
		 	--without-pgp --without-pgpk
.else
CONFIGURE_ARGS+=	--disable-pgp-gpg
.endif

.if ${PORT_OPTIONS:MISPELL}
RUN_DEPENDS+=		ispell:${PORTSDIR}/textproc/ispell
CONFIGURE_ARGS+=	--with-ispell=${PREFIX}/bin/ispell
.endif

.if ${PORT_OPTIONS:MMETAMAIL}
RUN_DEPENDS+=		metamail:${PORTSDIR}/mail/metamail
CONFIGURE_ARGS+=	--with-metamail=${PREFIX}/bin/metamail
.endif

.if ${PORT_OPTIONS:MCANLOCK}
CONFIGURE_ARGS+=	--enable-cancel-locks
.endif

.if ${PORT_OPTIONS:MNLS}
CONFIGURE_ARGS+=	--enable-nls
USES+=		gettext
PLIST_SUB+=		NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.endif

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

post-build:
.if ${PORT_OPTIONS:MNLS}
	cd ${WRKSRC}/po; ${GMAKE}
.endif

post-install:
	cd ${STAGEDIR}${PREFIX}/etc;\
		 ${INSTALL_DATA} ${WRKSRC}/doc/tin.defaults tin.defaults.dist;\
		if [ ! -f tin.defaults ] ; then \
			${CP} tin.defaults.dist tin.defaults; \
		fi

.include <bsd.port.mk>
