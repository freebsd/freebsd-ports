# New ports collection makefile for:	squid
# Version required:	1.0.0
# Date created:		Fri May 17 04:02:53 EET DST 1996
# Whom:			Andrew Stesin <stesin@elvisti.kiev.ua>
#
# $Id: Makefile,v 1.1.1.1 1996/06/03 02:21:13 asami Exp $
#

DISTNAME=	squid-1.0.0
PKGNAME=	squid-1.0
CATEGORIES+=	www
MASTER_SITES=  \
	ftp://www.nlanr.net/Software/Squid/ \
	ftp://www.unimelb.edu.au/pub/cwis/servers/unix/squid/ \
	ftp://sunsite.auc.dk/pub/infosystems/squid/ \
	ftp://ftp.net.lut.ac.uk/squid/
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	stesin@elvisti.kiev.ua

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc
CONFIGURE_ENV=	env "STD_CFLAGS=${CFLAGS}"
STRIP=		# won't install scripts correctly othervise.

post-install:
.for file in cachemgr.cgi client dnsserver ftpget squid
	strip ${PREFIX}/bin/${file}
.endfor

.include <bsd.port.mk>
