# New ports collection makefile for:	p5-News-Newsrc
# Date created:		February 7, 1998
# Whom:			Don Croyle <croyle@gelemna.ft-wayne.in.us>
#
# $FreeBSD$
#

PORTNAME=	p5-News-Newsrc
PORTVERSION=	1.07
CATEGORIES=	news perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	News
DISTNAME=	News-Newsrc-1.07

MAINTAINER=	croyle@gelemna.ft-wayne.in.us

RUN_DEPENDS=	${PREFIX}/lib/perl5/site_perl/${PERL_VER}/Set/IntSpan.pm:${PORTSDIR}/math/p5-Set-IntSpan

USE_PERL5=	yes

MAN3=		News::Newsrc.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
	@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
