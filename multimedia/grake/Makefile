# New ports collection makefile for:	grake
# Date created:		2010-12-12
# Whom:			Pierre Guinoiseau <geekounet@poildetroll.net>
#
# $FreeBSD$
#

PORTNAME=	grake
PORTVERSION=	0.0.7
CATEGORIES=	multimedia
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	geekounet@poildetroll.net
COMMENT=	Command line tool for scanning webpages for Youtube links

LICENSE=	GPLv3

RUN_DEPENDS=	p5-Getopt-ArgvFile>=1.11:${PORTSDIR}/devel/p5-Getopt-ArgvFile \
		p5-libwww>=5.835:${PORTSDIR}/www/p5-libwww

PERL_CONFIGURE=	yes

MAN1=		grake.1
PLIST_DIRS=	${SITE_PERL_REL}/${PERL_ARCH}/auto/grake
PLIST_FILES=	bin/grake ${SITE_PERL_REL}/${PERL_ARCH}/auto/grake/.packlist

.include <bsd.port.mk>
