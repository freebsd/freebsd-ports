# New ports collection makefile for:	ifile
# Date created:         29 Jan 2002
# Whom:                 David Bushong <david+ports@bushong.net>
#
# $FreeBSD$
#

PORTNAME=	ifile
PORTVERSION=	1.2.1
CATEGORIES=	mail textproc
MASTER_SITES=	http://savannah.nongnu.org/download/ifile/default.pkg/${PORTVERSION}/

MAINTAINER=	david+ports@bushong.net

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAN1=		ifile.1

post-patch:
.for file in argp-help.c strndup.c
	@${REINPLACE_CMD} -e 's/malloc\.h/stdlib.h/g' ${WRKSRC}/argp/${file}
.endfor
	@${REINPLACE_CMD} -e 's,-lm,-lm -L${LOCALBASE}/lib -lgnugetopt,' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
