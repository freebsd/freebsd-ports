# New ports collection makefile for:	p5-WWW-Shorten-0rz
# Date created:				2006-07-16
# Whom:					Tsung-Han Yeh <snowfly@yuntech.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	WWW-Shorten-0rz
PORTVERSION=	0.07
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	snowfly@yuntech.edu.tw
COMMENT=	Shorten URL using 0rz.net

BUILD_DEPENDS=	${SITE_PERL}/WWW/Shorten.pm:${PORTSDIR}/www/p5-WWW-Shorten \
		${SITE_PERL}/WWW/Mechanize.pm:${PORTSDIR}/www/p5-WWW-Mechanize
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		WWW::Shorten::0rz.3

.include <bsd.port.mk>
