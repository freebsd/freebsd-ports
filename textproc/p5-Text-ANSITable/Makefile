# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Text-ANSITable
PORTVERSION=	0.501
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Create nice formatted tables using extended ASCII and ANSI colors

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Border-Style>=0:devel/p5-Border-Style \
		p5-Color-RGB-Util>=0.591:devel/p5-Color-RGB-Util \
		p5-Color-Theme-Role>=0:devel/p5-Color-Theme-Role \
		p5-Function-Fallback-CoreOrPP>=0:devel/p5-Function-Fallback-CoreOrPP \
		p5-JSON-MaybeXS>=0:converters/p5-JSON-MaybeXS \
		p5-Log-ger>=0.23:devel/p5-Log-ger \
		p5-Module-List>=0:devel/p5-Module-List \
		p5-Moo>=0:devel/p5-Moo \
		p5-Package-MoreUtil>=0.590:devel/p5-Package-MoreUtil \
		p5-Parse-VarName>=0:devel/p5-Parse-VarName \
		p5-Term-App-Roles>=0.02:devel/p5-Term-App-Roles \
		p5-Text-ANSI-Util>=0.22:textproc/p5-Text-ANSI-Util \
		p5-namespace-clean>=0:devel/p5-namespace-clean
TEST_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-Needs>=0:devel/p5-Test-Needs

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
