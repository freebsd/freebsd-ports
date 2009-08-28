# New ports collection makefile for:	p5-WWW-VenusEnvy
# Date created:				2006/06/28
# Whom:		chinsan <chinsan.tw@gmail.com>, Gea-Suan Lin <gslin@gslin.org>
# Thanks to Gea-Suan Lin for his great patch for this port.
#
# $FreeBSD$
#

PORTNAME=	WWW-VenusEnvy
PORTVERSION=	1.10
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	VenusEnvy comic strip archive and retrieval module

RUN_DEPENDS=	p5-Test-Pod>=1.24:${PORTSDIR}/devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=1.08:${PORTSDIR}/devel/p5-Test-Pod-Coverage \
		p5-libwww>=5.805:${PORTSDIR}/www/p5-libwww
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		WWW::VenusEnvy.3

.include <bsd.port.mk>
