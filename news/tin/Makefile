# ex:ts=8
# New ports collection makefile for:	tin
# Version required:	tin1.3-unoff-BETA
# Date created:		25 July 1996
# Whom:			obrien@cs.ucdavis.edu
#
# $Id$
#

DISTNAME=       tin1.3-unoff-BETA-961018
PKGNAME=        tin-1.3.961018
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
		 --with-pgp=/usr/local/bin/pgp \
		 --with-ispell=/usr/local/bin/ispell \
		 --with-metamail=/usr/local/bin/metamail
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
