# New ports collection makefile for:	tin
# Date created:		25 July 1996
# Whom:			obrien@cs.ucdavis.edu
#
# $FreeBSD$
#

PORTNAME=	tin
PORTVERSION=    1.5.12
PORTREVISION=	1
CATEGORIES+=	news ipv6
MASTER_SITES=	ftp://ftp.tin.org/pub/news/clients/tin/v1.5/ \
		ftp://nuxi.ucdavis.edu/pub/tin/v1.5/ \
		ftp://ftp.nuxi.com/pub/tin/v1.5/

MAINTAINER?=    ache@FreeBSD.org

LIB_DEPENDS=	uu.2:${PORTSDIR}/converters/uulib \
		intl.4:${PORTSDIR}/devel/gettext

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--with-nntp-default-server=news \
		--with-spooldir=/var/news \
		--with-libdir=${PREFIX}/news/lib \
		--with-defaults-dir=${PREFIX}/etc \
		--with-editor=/usr/bin/ee \
		--enable-nls \
		--enable-ipv6 \
		--enable-curses \
		--with-ncurses \
		--disable-mime-strict-charset \
		--enable-forgery \
		--enable-break-long-lines \
		--with-pgp=${PREFIX}/bin/pgp \
		--with-ispell=${PREFIX}/bin/ispell \
		--with-metamail=${PREFIX}/bin/metamail \
		--with-mime-default-charset=US-ASCII
CONFIGURE_ENV=  CFLAGS='${CFLAGS} -DNNTP_SERVER_FILE="\"${PREFIX}/etc/nntpserver\""' \
		CPPFLAGS='${CPPFLAGS} -I${LOCALBASE}/include' \
		LDFLAGS='${LDFLAGS} -L${LOCALBASE}/lib'
ALL_TARGET=	build
MAN1=		tin.1
MAN5=		tin.5

.if defined(WITH_TIN_NNTP_ONLY)
CONFIGURE_ARGS+=	--enable-nntp-only
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

.include <bsd.port.mk>
