# New ports collection makefile for:	OpenCA-REQ
# Date created:	   02 June 2002
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	OpenCA-REQ
PORTVERSION=	0.9.52
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Perl extension to easily manage Cert REQUESTs

BUILD_DEPENDS=	${SITE_PERL}/X500/DN.pm:${PORTSDIR}/net/p5-X500-DN
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		OpenCA::REQ.3

post-patch:
	@${MV} ${WRKSRC}/prova.pl  ${WRKSRC}/prova.pl.sample

.include <bsd.port.mk>
