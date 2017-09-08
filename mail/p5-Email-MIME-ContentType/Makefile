# $FreeBSD$

PORTNAME=	Email-MIME-ContentType
PORTVERSION=	1.022
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Parse a MIME Content-Type Header

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502508
BUILD_DEPENDS+=	p5-Encode>=2.87:converters/p5-Encode
RUN_DEPENDS+=	p5-Encode>=2.87:converters/p5-Encode
.endif

.include <bsd.port.post.mk>
