# New ports collection makefile for:	p5-Yahoo-BBAuth
# Date created:		2007-07-06
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Yahoo-BBAuth
PORTVERSION=	0.50
CATEGORIES=	security www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Yahoo
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Perl interface to the Yahoo! Browser-Based Authentication

RUN_DEPENDS=	p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww

PERL_CONFIGURE=	yes

MAN3=		Yahoo::BBAuth.3

post-install:
	${MKDIR} ${WWWDIR}/cgi-bin
	${INSTALL_SCRIPT} ${WRKSRC}/eg/* ${WWWDIR}/cgi-bin

.include <bsd.port.mk>
