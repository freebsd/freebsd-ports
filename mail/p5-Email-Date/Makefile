# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Email-Date
PORTVERSION=	1.10.4
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/.([0-9]+)$/\1/}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Find and Format Date Headers

BUILD_DEPENDS=	p5-Email-Abstract>=2.10:${PORTSDIR}/mail/p5-Email-Abstract \
		p5-Email-Date-Format>=1:${PORTSDIR}/mail/p5-Email-Date-Format \
		p5-Email-Simple>=1.9:${PORTSDIR}/mail/p5-Email-Simple \
		p5-Time-Piece>=1.08:${PORTSDIR}/devel/p5-Time-Piece \
		p5-TimeDate>=1.16:${PORTSDIR}/devel/p5-TimeDate
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
