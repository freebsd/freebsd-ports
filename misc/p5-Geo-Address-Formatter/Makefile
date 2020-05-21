# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Geo-Address-Formatter
PORTVERSION=	1.82
CATEGORIES=	misc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Take structured address data and format it according to the various global/country rules

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Clone>=0.45:devel/p5-Clone \
		p5-File-Find-Rule>=0:devel/p5-File-Find-Rule \
		p5-Ref-Util>=0.204:devel/p5-Ref-Util \
		p5-Text-Hogan>=2.03:textproc/p5-Text-Hogan \
		p5-Text-Trim>=1.02:textproc/p5-Text-Trim \
		p5-Try-Catch>=0:lang/p5-Try-Catch \
		p5-YAML-LibYAML>=0.82:textproc/p5-YAML-LibYAML
TEST_DEPENDS=	p5-File-Slurper>=0:devel/p5-File-Slurper \
		p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-Warn>=0:devel/p5-Test-Warn

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
