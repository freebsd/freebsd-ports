# New ports collection makefile for:	idled
# Version required:	1.16
# Date created:	12 March 1997
# Whom:	Andrew <andrew@ugh.net.au>, Iain Templeton <iain@ugh.net.au>

DISTNAME=	idled-1.16
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.cs.hope.edu/pub/idled/

NO_CDROM=	non-profit use and distribution only
NOMANCOMPRESS=	compressed already

MAINTAINER=     andrew@ugh.net.au, iain@ugh.net.au

MAN5=		idled.cf.5
MAN8=		idled.8

post-extract:
	(cd ${WRKSRC}; make clean)

post-install:
	strip ${PREFIX}/libexec/idled

.include <bsd.port.mk>
