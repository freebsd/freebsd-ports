# New ports collection makefile for:	stegdetect
# Date created:			Jul 19, 2001
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	stegdetect
PORTVERSION=	0.3
CATEGORIES=	security
MASTER_SITES=	http://www.outguess.org/

MAINTAINER=	markp@FreeBSD.org

# Note: stegdetect includes a modified version of jpeg-6b linked statically
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
MAN1=		stegdetect.1

pre-patch:
	@${PERL} -pi -e 's@\$$\(JPEGLIB\)@\$$\(JPEGLIB\) \-lcrypto@' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
