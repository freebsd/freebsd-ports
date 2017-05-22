# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	LaTeX-Encode
PORTVERSION=	0.092.0
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Encode characters for LaTeX formatting

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Readonly>=0:devel/p5-Readonly
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Carp-Always>=0:devel/p5-Carp-Always

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
