# New ports collection makefile for:	idled
# Date created:			12 March 1997
# Whom:		Andrew <andrew@ugh.net.au>, Iain Templeton <iain@ugh.net.au>
#
# $FreeBSD$
#

PORTNAME=	idled
PORTVERSION=	1.16
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.darkwing.com/idled/download/	\
		ftp://ftp.cs.hope.edu/pub/idled/

MAINTAINER=	andrew@ugh.net.au

NO_CDROM=	non-profit use and distribution only
MANCOMPRESSED=	yes
MAN5=		idled.cf.5
MAN8=		idled.8

post-extract:
	(cd ${WRKSRC}; make clean)

post-install:
	strip ${PREFIX}/libexec/idled
.if !exists(${PREFIX}/etc/rc.d/idled.sh)
	@${ECHO} "Installing ${PREFIX}/etc/rc.d/idled.sh startup script."
	${INSTALL_SCRIPT} -m 751 ${FILESDIR}/idled.sh ${PREFIX}/etc/rc.d/idled.sh
.endif

.include <bsd.port.mk>
