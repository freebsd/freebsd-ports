# New ports collection makefile for:	reed
# Date created:				7 August 2001
# Whom:					Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	reed
PORTVERSION=	4.6
CATEGORIES=	misc
MASTER_SITES=	http://www.sacredchao.net/software/reed/

MAINTAINER=	petef@databits.net

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAKE_ARGS=	CFLAGS="-I${LOCALBASE}/include ${CFLAGS}"

post-patch:
	@${PERL} -pi -e 's!sys/dir.h!dirent.h!g' ${WRKSRC}/configure \
		${WRKSRC}/src/reed.h
	@${PERL} -pi -e 's!-O3!!' ${WRKSRC}/configure
	@${PERL} -pi -e 's!CFLAGS =!CFLAGS +=!' ${WRKSRC}/src/Makefile.in

MAN1=	breed.1 reed.1 wrap.1

.include <bsd.port.mk>
