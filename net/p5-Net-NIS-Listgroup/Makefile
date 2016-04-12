# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Net-NIS-Listgroup
PORTVERSION=	1.0.0
PORTREVISION=	3
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Lists hosts/users in a netgroup group

LICENSE=	GPLv2

RUN_DEPENDS=	p5-Net-NIS>0:net/p5-Net-NIS

USES=		perl5
USE_PERL5=	configure

post-patch:
	@${MKDIR} ${WRKSRC}/lib
	${MV} ${WRKSRC}/Net ${WRKSRC}/lib

.include <bsd.port.mk>
