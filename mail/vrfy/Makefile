# ports collection makefile for:	vrfy
# Date created:				2000/09/09
# Whom:					kaz
#
# $FreeBSD$
#

PORTNAME=	vrfy
PORTVERSION=	1.0
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.nikhef.nl/pub/network/ \
		http://www.kobe1995.net/~kaz/FreeBSD/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	kaz@kobe1995.net
COMMENT=	Verify mail address

WRKSRC=		${WRKDIR}
MAN1=		vrfy.1
MANCOMPRESSED=	yes
PLIST_FILES=	bin/vrfy

post-install:
	${INSTALL_MAN} ${WRKDIR}/${MAN1} ${PREFIX}/man/man1/
	${GZIP_CMD} ${PREFIX}/man/man1/${MAN1}

.include <bsd.port.mk>
