# ex:ts=8
# New ports collection makefile for:	tin
# Version required:	tin1.3-unoff-BETA
# Date created:		25 July 1996
# Whom:			obrien@cs.ucdavis.edu
#
# $Id: Makefile,v 1.47 1997/11/05 08:15:14 asami Exp $
#

DISTNAME=       tinpre-1.4-971123
PKGNAME=        tinpre-1.4-971123
CATEGORIES=	news
MASTER_SITES=   ftp://nuxi.ucdavis.edu/pub/tin/ \
		ftp://ftp.akk.uni-karlsruhe.de/pub/tin/ \
		ftp://ftp.nuxi.com/pub/tin/
EXTRACT_SUFX=	.tgz

MAINTAINER=     ache@FreeBSD.org

WRKSRC=         ${WRKDIR}/${DISTNAME:S/pre-1.4//}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --with-nntp-default-server=news  \
		 --with-spooldir=/var/news  \
		 --with-libdir=${PREFIX}/news/lib \
		 --with-mime-default-charset=US-ASCII \
		 --enable-forgery \
		 --enable-curses \
		 --with-ncurses \
		 --enable-break-long-lines \
		 --with-pgp=${PREFIX}/bin/pgp \
		 --with-ispell=${PREFIX}/bin/ispell \
		 --with-metamail=${PREFIX}/bin/metamail
MAKEFILE=	makefile
ALL_TARGET=     build
MAN1=		tin.1

.if defined(NNTP_ONLY)
CONFIGURE_ARGS+=	--enable-nntp-only
.endif

post-configure:
	echo '#define NNTP_SERVER_FILE "${PREFIX}/etc/nntpserver"' >>${WRKSRC}/include/autoconf.h
	echo '#define SMTP_SERVER_FILE "${PREFIX}/etc/smtpserver"' >>${WRKSRC}/include/autoconf.h

.include <bsd.port.mk>
