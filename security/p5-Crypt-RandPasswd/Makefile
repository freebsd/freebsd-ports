# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Crypt-RandPasswd
PORTVERSION=	0.04
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	An implementation of the Automated Password Generator standard

USES=		perl5
USE_PERL5=	configure

post-patch:
	@${RM} ${WRKSRC}/lib/Crypt/RandPasswd.pm.orig

.include <bsd.port.mk>
