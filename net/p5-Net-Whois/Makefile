# New ports collection makefile for:	p5-Net-Whois
# Version required:			0.22
# Date created:				June 7th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.2 1997/06/24 18:43:27 jfitz Exp $
#

DISTNAME=	Net-Whois-0.22
PKGNAME=	p5-Net-Whois-0.22
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net

MAINTAINER=	jfitz@FreeBSD.ORG

RUN_DEPENDS=	${PREFIX}/lib/perl5/site_perl/Locale/Country.pm:${PORTSDIR}/misc/p5-Locale-Codes

USE_PERL5=	YES

MANPREFIX=	/usr/local/lib/perl5
MAN3=		Net::Whois.3

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
