# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Rose-HTML-Objects
PORTVERSION=	0.619
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Object-oriented interfaces for HTML

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Clone-PP>=0:${PORTSDIR}/devel/p5-Clone-PP \
		p5-DateTime>=0.20:${PORTSDIR}/devel/p5-DateTime \
		p5-Email-Valid>=0:${PORTSDIR}/mail/p5-Email-Valid \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-IO-String>=1.08:${PORTSDIR}/devel/p5-IO-String \
		p5-Image-Size>=0:${PORTSDIR}/graphics/p5-Image-Size \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Rose-DateTime>=0.532:${PORTSDIR}/devel/p5-Rose-DateTime \
		p5-Rose-Object>=0.854:${PORTSDIR}/devel/p5-Rose-Object \
		p5-Rose-URI>=0.021:${PORTSDIR}/net/p5-Rose-URI \
		p5-URI>=0:${PORTSDIR}/net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Memory-Cycle>=0:${PORTSDIR}/devel/p5-Test-Memory-Cycle

PORTSCOUT=	skipv:0.6061

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501600
BUILD_DEPENDS+=	p5-base>=2.18:${PORTSDIR}/devel/p5-base
RUN_DEPENDS+=	p5-base>=2.18:${PORTSDIR}/devel/p5-base
.endif

.include <bsd.port.post.mk>
