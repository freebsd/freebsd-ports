# New ports collection makefile for:	p5-Net-Whois
# Date created:				June 7th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	p5-Net-Whois
PORTVERSION=	0.22
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
DISTNAME=	Net-Whois-${PORTVERSION}

MAINTAINER=	jfitz@FreeBSD.org

RUN_DEPENDS=	${PREFIX}/lib/perl5/site_perl/Locale/Country.pm:${PORTSDIR}/misc/p5-Locale-Codes

USE_PERL5=	YES

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Net::Whois.3

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
