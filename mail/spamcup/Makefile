# New ports collection makefile for:	spamcup
# Date created:				07 February 2005
# Whom:	      				Yen-Ming Lee <leeym@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	spamcup
PORTVERSION=	1.09
PORTREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool for automatic spam reporting via Spamcop.net

LICENSE=	GPLv1

RUN_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-Getopt-ArgvFile>=0:${PORTSDIR}/devel/p5-Getopt-ArgvFile \
		p5-HTML-Form>=0:${PORTSDIR}/www/p5-HTML-Form

USES=		perl5
USE_PERL5=	configure

PLIST_FILES=	bin/spamcup.pl ${SITE_PERL_REL}/spamcup.pl \
		${SITE_PERL_REL}/${PERL_ARCH}/auto/Spamcup/.packlist

PLIST_DIRS=	${SITE_PERL_REL}/${PERL_ARCH}/auto/Spamcup

.include <bsd.port.mk>
