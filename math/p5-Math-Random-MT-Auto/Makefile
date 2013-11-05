# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Math-Random-MT-Auto
PORTVERSION=	6.22
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Auto-seeded Mersenne Twister PRNGs

BUILD_DEPENDS=	p5-Exception-Class>=1.32:${PORTSDIR}/devel/p5-Exception-Class \
		p5-Object-InsideOut>=3.88:${PORTSDIR}/devel/p5-Object-InsideOut
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
BUILD_DEPENDS+=	p5-Scalar-List-Utils>=1.23:${PORTSDIR}/lang/p5-Scalar-List-Utils
RUN_DEPENDS+=	p5-Scalar-List-Utils>=1.23:${PORTSDIR}/lang/p5-Scalar-List-Utils
.endif

.include <bsd.port.post.mk>
