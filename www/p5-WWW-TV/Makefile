# New ports collection makefile for:    WWW-TV
# Date created:                         9 March 2007
# Whom:                                 Anatoliy Dmytriyev <tolid@plab.ku.dk>
#
# $FreeBSD$
#

PORTNAME=	WWW-TV
PORTVERSION=	0.14
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tolid@tolid.eu.org
COMMENT=	Perl interface to the database of series/episodes at TV.com

RUN_DEPENDS=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww

PERL_CONFIGURE=	yes

MAN3=		WWW::TV.3 WWW::TV::Episode.3 WWW::TV::Series.3

.include <bsd.port.mk>
