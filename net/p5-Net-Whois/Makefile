# New ports collection makefile for:	p5-Net-Whois
# Version required:			0.21
# Date created:				June 7th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.1.1.1 1997/06/07 04:07:27 jfitz Exp $
#

DISTNAME=	Net-Whois-0.21
PKGNAME=	p5-Net-Whois-0.21
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net

MAINTAINER=	jfitz@FreeBSD.ORG

USE_PERL5=	YES

MANPREFIX=	/usr/local/lib/perl5
MAN3=		Net::Whois.3

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
