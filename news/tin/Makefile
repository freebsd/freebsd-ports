# New ports collection makefile for:	tin
# Date created:		25 July 1996
# Whom:			obrien@cs.ucdavis.edu
#
# $FreeBSD$
#

PORTNAME=	tin
PORTVERSION=    1.5.16
PORTREVISION=   1
CATEGORIES+=	news ipv6
MASTER_SITES=   ftp://ftp.tin.org/pub/news/clients/tin/v1.5/snapshots/ \
		ftp://nuxi.ucdavis.edu/pub/tin/v1.5/snapshots/

MAINTAINER?=    ache@FreeBSD.org

LIB_DEPENDS=	uu.2:${PORTSDIR}/converters/uulib \
		iconv.3:${PORTSDIR}/converters/libiconv \
		intl.4:${PORTSDIR}/devel/gettext

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

# --with-mime-default-charset=US-ASCII needed to build tin in the non-ascii
# national environment.
CONFIGURE_ARGS=	--with-nntp-default-server=news \
		--with-spooldir=/var/news \
		--with-libdir=${PREFIX}/news/lib \
		--with-defaults-dir=${PREFIX}/etc \
		--with-editor=/usr/bin/ee \
		--enable-nls \
		--with-screen=ncurses \
		--enable-break-long-lines \
		--with-libiconv-prefix=${LOCALBASE} \
		--with-mime-default-charset=US-ASCII
CONFIGURE_ENV=  CFLAGS='${CFLAGS} -DNNTP_SERVER_FILE="\"${PREFIX}/etc/nntpserver\""' \
		CPPFLAGS='${CPPFLAGS} -I${LOCALBASE}/include' \
		LDFLAGS='${LDFLAGS} -L${LOCALBASE}/lib'
ALL_TARGET=	build
MAN1=           tin.1 w2r.pl.1 opt-case.pl.1
MAN5=           tin.5 mbox.5 mmdf.5
MLINKS=         tin.1 rtin.1

.if defined(WITH_TIN_NNTP_ONLY)
CONFIGURE_ARGS+= --enable-nntp-only
.endif

.include <bsd.port.pre.mk>

.if defined(WITHOUT_TIN_PGP_GPG)
CONFIGURE_ARGS+= --disable-pgp-gpg
.elif defined(WITH_TIN_GPG) || \
    (exists(${LOCALBASE}/bin/gpg) && !defined(WITH_TIN_PGP))
RUN_DEPENDS+= gpg:${PORTSDIR}/security/gnupg
CONFIGURE_ARGS+= --with-gpg=${PREFIX}/bin/gpg \
		 --without-pgp --without-pgpk
.elif defined(WITH_TIN_PGP) || exists(${LOCALBASE}/bin/pgp)
RUN_DEPENDS+= pgp:${PORTSDIR}/security/pgp6
CONFIGURE_ARGS+= --with-pgp=${PREFIX}/bin/pgp \
		 --without-pgpk --without-gpg
.else
CONFIGURE_ARGS+= --disable-pgp-gpg
.endif

.if defined(WITH_TIN_ISPELL) || \
    (exists(${LOCALBASE}/bin/ispell) && !defined(WITHOUT_TIN_ISPELL))
RUN_DEPENDS+= ispell:${PORTSDIR}/textproc/ispell
CONFIGURE_ARGS+= --with-ispell=${PREFIX}/bin/ispell
.endif

.if defined(WITH_TIN_METAMAIL) || \
    (exists(${LOCALBASE}/bin/metamail) && !defined(WITHOUT_TIN_METAMAIL))
RUN_DEPENDS+= metamail:${PORTSDIR}/mail/metamail
CONFIGURE_ARGS+= --with-metamail=${PREFIX}/bin/metamail
.endif

.if ${OSVERSION} >= 400014
CONFIGURE_ARGS+= --enable-ipv6
.else
CONFIGURE_ARGS+= --disable-ipv6
.endif

post-patch:
	@${MV} ${WRKSRC}/doc/tin.1 ${WRKSRC}/doc/tin.1.dist
	@${SED} -e 's:/var/spool/news:/var/news:' \
		-e 's:/etc/nntpserver:${PREFIX}/etc/nntpserver:' \
		-e 's:/usr/lib/news:${PREFIX}/news/lib:' \
		<${WRKSRC}/doc/tin.1.dist >${WRKSRC}/doc/tin.1

pre-configure:
	${CP} ${FILESDIR}/pcre.h ${WRKSRC}/pcre

post-build:
	cd ${WRKSRC}/po; ${GMAKE}

post-install:
	cd ${WRKSRC}/doc; ${INSTALL_DATA} tin.defaults ${PREFIX}/etc/tin.defaults.dist
	if [ ! -f ${PREFIX}/etc/tin.defaults ] ; then \
		${CP} ${PREFIX}/etc/tin.defaults.dist ${PREFIX}/etc/tin.defaults; \
	fi
	cd ${WRKSRC}/doc; ${INSTALL_DATA} mime.types ${PREFIX}/etc/tin.mime.types.dist
	if [ ! -f ${PREFIX}/etc/mime.types ] ; then \
		${CP} ${PREFIX}/etc/tin.mime.types.dist ${PREFIX}/etc/mime.types; \
	fi

.include <bsd.port.post.mk>
