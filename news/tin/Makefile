# ex:ts=8
# New ports collection makefile for:	tin
# Version required:	tin1.3-unoff-BETA
# Date created:		25 July 1996
# Whom:			obrien@cs.ucdavis.edu
#
# $Id: Makefile,v 1.14 1996/11/18 11:38:18 asami Exp $
#

DISTNAME=       tin1.3-unoff-BETA-961126
PKGNAME=        tin-1.3.961126
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.akk.uni-karlsruhe.de/pub/tin/  \
		ftp://nuxi.cs.ucdavis.edu/pub/tin/
EXTRACT_SUFX=	.tgz

MAINTAINER=     ache@FreeBSD.org

WRKSRC=		${WRKDIR}/${DISTNAME:S/tin1.3-unoff-BETA-//}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --with-nntp-default-server=news  \
		 --with-spooldir=/var/news  \
		 --with-libdir=${PREFIX}/lib/news \
		 --with-mime-default-charset=US-ASCII \
		 --enable-forgery \
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
