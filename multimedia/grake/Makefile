# New ports collection makefile for:	grake
# Date created:		2010-12-12
# Whom:			Pierre Guinoiseau <geekounet@poildetroll.net>
#
# $FreeBSD$
#

PORTNAME=	grake
PORTVERSION=	0.0.5
CATEGORIES=	multimedia
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	geekounet@poildetroll.net
COMMENT=	Command line tool for scanning webpages for Youtube links

RUN_DEPENDS=	p5-Getopt-ArgvFile>=1.11:${PORTSDIR}/devel/p5-Getopt-ArgvFile \
		p5-libwww>=5.835:${PORTSDIR}/www/p5-libwww

LICENSE=	GPLv3

MAN1=		grake.1

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
