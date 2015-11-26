# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Pod-Markdown
PORTVERSION=	3.003
CATEGORIES=	textproc devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Module to convert POD to Markdown

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	p5-Test-Difference>=0:${PORTSDIR}/devel/p5-Test-Differences

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501800
BUILD_DEPENDS+=	p5-Pod-Simple>=3.27:${PORTSDIR}/textproc/p5-Pod-Simple
RUN_DEPENDS+=	p5-Pod-Simple>=3.27:${PORTSDIR}/textproc/p5-Pod-Simple
.endif

.include <bsd.port.post.mk>
