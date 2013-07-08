# Created by: Seamus Venasse <svenasse@polaris.ca>
# $FreeBSD$

PORTNAME=		HTML-FromText
PORTVERSION=		2.06
CATEGORIES=		www perl5
MASTER_SITES=		CPAN
PKGNAMEPREFIX=		p5-

MAINTAINER=		danilogondolfo@gmail.com
COMMENT=	Mark up text as HTML

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Email-Find>=0.09:${PORTSDIR}/mail/p5-Email-Find \
		p5-HTML-Parser>=1.26:${PORTSDIR}/www/p5-HTML-Parser
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=		yes

MAN1=			text2html.1
MAN3=			HTML::FromText.3

.include <bsd.port.mk>
