# Created by: Alex Perel <veers@disturbed.net>
# $FreeBSD$

PORTNAME=	MIME-Lite
PORTVERSION=	3.03.0
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple interface for creating (not parsing!) MIME messages

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Email-Date-Format>=1.000:${PORTSDIR}/mail/p5-Email-Date-Format \
		p5-MIME-Types>=1.28:${PORTSDIR}/mail/p5-MIME-Types \
		p5-Mail-Tools>=1.62:${PORTSDIR}/mail/p5-Mail-Tools
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
