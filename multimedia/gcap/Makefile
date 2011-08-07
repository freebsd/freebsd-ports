# New ports collection makefile for:	gcap
# Date created:		2011-08-07
# Whom:			Pierre Guinoiseau <geekounet@poildetroll.net>
#
# $FreeBSD$
#

PORTNAME=	gcap
PORTVERSION=	0.0.8
CATEGORIES=	multimedia
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	geekounet@poildetroll.net
COMMENT=	Command line tool for downloading Youtube closed captions

LICENSE=	GPLv3

RUN_DEPENDS=	p5-Getopt-ArgvFile>=1.11:${PORTSDIR}/devel/p5-Getopt-ArgvFile \
		p5-HTML-Parser>=3.60:${PORTSDIR}/www/p5-HTML-Parser \
		p5-XML-DOM>=1.44:${PORTSDIR}/textproc/p5-XML-DOM

PERL_CONFIGURE=	yes

MAN1=		gcap.1
PLIST_DIRS=	${SITE_PERL_REL}/${PERL_ARCH}/auto/gcap
PLIST_FILES=	bin/gcap ${SITE_PERL_REL}/${PERL_ARCH}/auto/gcap/.packlist

.include <bsd.port.mk>
