# ex:ts=8
# New ports collection makefile for:	tin
# Version required:	tin1.3-unoff-BETA
# Date created:		25 July 1996
# Whom:			obrien@cs.ucdavis.edu
#
# $Id: Makefile,v 1.4 1996/10/19 22:44:06 ache Exp $
#

DISTNAME=       tin1.3-unoff-BETA-961020
PKGNAME=        tin-1.3.961020
CATEGORIES+=	news
MASTER_SITES=	ftp://ftp.akk.uni-karlsruhe.de/pub/tin/  \
		ftp://nuxi.cs.ucdavis.edu/pub/tin/

MAINTAINER=     ache@FreeBSD.org

EXTRACT_SUFX=	.tgz
WRKSRC=		${WRKDIR}/${DISTNAME:S/tin1.3-unoff-BETA-//}
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=  cf_cv_corefile=yes
CONFIGURE_ARGS+= --with-nntp-default-server=news  \
		 --with-spooldir=/var/news  \
		 --with-libdir=${PREFIX}/lib/news \
		 --enable-forgery \
		 --with-pgp=${PREFIX}/bin/pgp \
		 --with-ispell=${PREFIX}/bin/ispell \
		 --with-metamail=${PREFIX}/bin/metamail
MAKEFILE=	makefile
ALL_TARGET=     build

.if defined(NNTP_ONLY)
CONFIGURE_ARGS+=	--enable-nntp-only
.endif


post-configure:
	echo '#define NNTP_SERVER_FILE "${PREFIX}/etc/nntpserver"' >>${WRKSRC}/include/autoconf.h
	echo '#define SMTP_SERVER_FILE "${PREFIX}/etc/smtpserver"' >>${WRKSRC}/include/autoconf.h

post-install:
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man1/tin.1
.endif

.include <bsd.port.mk>
