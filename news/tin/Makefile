# New ports collection makefile for:	tin
# Date created:		25 July 1996
# Whom:			obrien@cs.ucdavis.edu
#
# $FreeBSD$
#

PORTNAME=	tin
PORTVERSION=	2.0.1
PORTREVISION=	1
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

LIB_DEPENDS=	uu.3:${PORTSDIR}/converters/uulib \
		pcre.1:${PORTSDIR}/devel/pcre
RUN_DEPENDS=	${LOCALBASE}/etc/mime.types:${PORTSDIR}/misc/mime-support

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
GNU_CONFIGURE=	yes
TIN_EDITOR?=	/usr/bin/ee

OPTIONS=	GNUPG	"Enable message signing via GnuPG" On \
		ISPELL	"Enable spell checking via ispell" On \
		METAMAIL  "Enable MIME support via metamail" On \
		CANLOCK	  "Enable Cancel-Lock key support via libcanlock" Off \
		NNTP_ONLY "Only read news via NNTP (no spool dir support)" Off

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 602107 || (${OSVERSION} >= 700000 && ${OSVERSION} < 700033)
TIN_SCREEN?=	ncurses
.else
TIN_SCREEN?=	ncursesw
.endif

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
		--with-libiconv-prefix=${LOCALBASE} \
		--with-mime-default-charset=US-ASCII \
		--enable-ipv6
MAKE_ARGS+=	MAKE=${GMAKE}
CFLAGS+=	-DNNTP_SERVER_FILE=\\\"${PREFIX}/etc/nntpserver\\\"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
ALL_TARGET=	build
MAN1=		tin.1 w2r.pl.1 opt-case.pl.1 tinews.pl.1 tinurl_handler.pl.1
MAN5=		tin.5 tin_mbox.5 tin_mmdf.5
MLINKS=		tin.1 rtin.1

.ifdef	WITH_NNTP_ONLY
CONFIGURE_ARGS+=	--enable-nntp-only
.endif

.ifdef	WITH_GNUPG
RUN_DEPENDS+=		gpg:${PORTSDIR}/security/gnupg
CONFIGURE_ARGS+=	--with-gpg=${PREFIX}/bin/gpg \
		 	--without-pgp --without-pgpk
.else
CONFIGURE_ARGS+=	--disable-pgp-gpg
.endif

.ifdef	WITH_ISPELL
RUN_DEPENDS+=		ispell:${PORTSDIR}/textproc/ispell
CONFIGURE_ARGS+=	--with-ispell=${PREFIX}/bin/ispell
.endif

.ifdef	WITH_METAMAIL
RUN_DEPENDS+=		metamail:${PORTSDIR}/mail/metamail
CONFIGURE_ARGS+=	--with-metamail=${PREFIX}/bin/metamail
.endif

.ifdef	WITH_CANLOCK
CONFIGURE_ARGS+=	--enable-cancel-locks
.endif

.ifdef	WITHOUT_NLS
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.else
CONFIGURE_ARGS+=	--enable-nls
USE_GETTEXT=		yes
PLIST_SUB+=		NLS=""
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
.ifndef	WITHOUT_NLS
	cd ${WRKSRC}/po; ${GMAKE}
.endif

post-install:
	cd ${WRKSRC}/doc; ${INSTALL_DATA} tin.defaults ${PREFIX}/etc/tin.defaults.dist
	if [ ! -f ${PREFIX}/etc/tin.defaults ] ; then \
		${CP} ${PREFIX}/etc/tin.defaults.dist ${PREFIX}/etc/tin.defaults; \
	fi

.include <bsd.port.post.mk>
