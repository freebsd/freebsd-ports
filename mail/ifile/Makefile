# New ports collection makefile for:	ifile
# Date created:         29 Jan 2002
# Whom:                 David Bushong <david+ports@bushong.net>
#
# $FreeBSD$
#

PORTNAME=	ifile
PORTVERSION=	1.3.2
CATEGORIES=	mail textproc
MASTER_SITES=	http://savannah.nongnu.org/download/ifile/default.pkg/${PORTVERSION}/

MAINTAINER=	david+ports@bushong.net
COMMENT=	An application of machine learning to e-mail filtering

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAN1=		ifile.1

post-patch:
	@${REINPLACE_CMD} -e 's,-lm,-lm -L${LOCALBASE}/lib -lgnugetopt,' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
