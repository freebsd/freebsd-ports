# Created by: Gabor Kovesdan
# $FreeBSD$

PORTNAME=	Digest-EMAC
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Perl5 interface to EMAC Double Message-Digest Algorithms

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Crypt-CBC>=0:security/p5-Crypt-CBC

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
