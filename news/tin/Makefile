# ex:ts=8
# New ports collection makefile for:	tin
# Version required:     tinpre-1.4
# Date created:		25 July 1996
# Whom:			obrien@cs.ucdavis.edu
#
# $Id: Makefile,v 1.64 1998/10/15 00:07:04 jseger Exp $
#

DISTNAME=       tinpre-1.4-980818
CATEGORIES=	news
MASTER_SITES=   ftp://ftp.tin.org/pub/news/clients/tin/current/ \
		ftp://nuxi.ucdavis.edu/pub/tin/ \
		ftp://ftp.nuxi.com/pub/tin/
EXTRACT_SUFX=	.tgz

LIB_DEPENDS=    uu.1:${PORTSDIR}/converters/uulib

MAINTAINER=     ache@FreeBSD.org

WRKSRC=         ${WRKDIR}/${DISTNAME:S/pre-1.4//}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

# Curses support too buggy to activate
#                 --enable-curses \
#                 --with-ncurses \
#
CONFIGURE_ARGS=  --with-nntp-default-server=news  \
		 --with-spooldir=/var/news  \
		 --with-libdir=${PREFIX}/news/lib \
		 --with-defaults-dir=${PREFIX}/etc \
		 --with-editor=/usr/bin/ee \
		 --with-mime-default-charset=ISO-8859-1 \
		 --enable-forgery \
		 --enable-break-long-lines \
		 --with-pgp=${PREFIX}/bin/pgp \
		 --with-ispell=${PREFIX}/bin/ispell \
		 --with-metamail=${PREFIX}/bin/metamail
CONFIGURE_ENV=  CFLAGS='${CFLAGS} -I${PREFIX}/include -DNNTP_SERVER_FILE="\"${PREFIX}/etc/nntpserver\""' \
		CPPFLAGS='${CPPFLAGS} -I${PREFIX}/include' \
		LDFLAGS='${LDFLAGS} -L${PREFIX}/lib'
MAKEFILE=       makefile
ALL_TARGET=     build
MAN1=		tin.1

.if defined(NNTP_ONLY)
CONFIGURE_ARGS+=	--enable-nntp-only
.endif

post-patch:
	@${MV} ${WRKSRC}/doc/tin.1 ${WRKSRC}/doc/tin.1.dist
	@${SED} -e 's:/var/spool/news:/var/news:' \
		-e 's:/etc/nntpserver:${PREFIX}/etc/nntpserver:' \
		-e 's:/usr/lib/news:${PREFIX}/news/lib:' \
		<${WRKSRC}/doc/tin.1.dist >${WRKSRC}/doc/tin.1

post-install:
	cd ${WRKSRC}/doc; ${INSTALL_DATA} tin.defaults ${PREFIX}/etc/tin.defaults.dist
	if [ ! -f ${PREFIX}/etc/tin.defaults ] ; then \
		cp ${PREFIX}/etc/tin.defaults.dist ${PREFIX}/etc/tin.defaults; \
	fi

.include <bsd.port.mk>
