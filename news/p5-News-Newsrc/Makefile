# New ports collection makefile for:	p5-News-Newsrc
# Date created:		February 7, 1998
# Whom:			Don Croyle <croyle@gelemna.org>
#
# $FreeBSD$
#

PORTNAME=	News-Newsrc
PORTVERSION=	1.07
CATEGORIES=	news perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	News
PKGNAMEPREFIX=	p5-

MAINTAINER=	croyle@gelemna.org

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Set/IntSpan.pm:${PORTSDIR}/math/p5-Set-IntSpan

PERL_CONFIGURE=	yes

MAN3=		News::Newsrc.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
