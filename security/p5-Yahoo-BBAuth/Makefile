# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

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

USES=		perl5
USE_PERL5=	configure

MAN3=		Yahoo::BBAuth.3

post-install:
	${MKDIR} ${WWWDIR}/cgi-bin
	${INSTALL_SCRIPT} ${WRKSRC}/eg/* ${WWWDIR}/cgi-bin

.include <bsd.port.mk>
