# New ports collection makefile for:	grake
# Date created:		2010-12-12
# Whom:			Pierre Guinoiseau <geekounet@poildetroll.net>
#
# $FreeBSD$
#

PORTNAME=	grake
PORTVERSION=	0.1.0
CATEGORIES=	multimedia
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	geekounet@poildetroll.net
COMMENT=	Command line tool for scanning webpages for Youtube links

LICENSE=	GPLv3

BUILD_DEPENDS=	p5-Getopt-ArgvFile>=1.11:${PORTSDIR}/devel/p5-Getopt-ArgvFile \
		p5-Umph-Prompt>=0:${PORTSDIR}/multimedia/p5-Umph-Prompt \
		p5-libwww>=5.835:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	p5-Getopt-ArgvFile>=1.11:${PORTSDIR}/devel/p5-Getopt-ArgvFile \
		p5-Umph-Prompt>=0:${PORTSDIR}/multimedia/p5-Umph-Prompt \
		p5-libwww>=5.835:${PORTSDIR}/www/p5-libwww

TEST_DEPENDS=	p5-Test-Pod>=1:${PORTSDIR}/devel/p5-Test-Pod

USES=		perl5
USE_PERL5=	configure

MAN1=		grake.1
PLIST_DIRS=	${SITE_PERL_REL}/${PERL_ARCH}/auto/grake
PLIST_FILES=	bin/grake ${SITE_PERL_REL}/${PERL_ARCH}/auto/grake/.packlist

.include <bsd.port.mk>
