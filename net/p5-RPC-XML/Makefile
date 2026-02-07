PORTNAME=	RPC-XML
PORTVERSION=	0.82
PORTREVISION=	1
CATEGORIES=	net www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	XML-RPC client and server library for Perl
WWW=		https://metacpan.org/release/RPC-XML

LICENSE=	ART20 LGPL21
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-HTTP-Daemon>=6.12:www/p5-HTTP-Daemon \
		p5-HTTP-Message>=6.26:www/p5-HTTP-Message \
		p5-Scalar-List-Utils>=1.55,1:lang/p5-Scalar-List-Utils \
		p5-XML-Parser>=2.46:textproc/p5-XML-Parser \
		p5-libwww>=6.51:www/p5-libwww
TEST_DEPENDS=	p5-Test-Simple>=1.302183:devel/p5-Test-Simple

USES=		gmake perl5
USE_PERL5=	configure

NO_ARCH=	yes

OPTIONS_DEFINE=	RECOMMENDED XS
RECOMMENDED_DESC=	Recommended dependencies by upstream

RECOMMENDED_BUILD_DEPENDS=	p5-DateTime-Format-ISO8601>=0.15:devel/p5-DateTime-Format-ISO8601 \
			p5-DateTime>=1.54:devel/p5-DateTime
RECOMMENDED_RUN_DEPENDS=p5-DateTime-Format-ISO8601>=0.15:devel/p5-DateTime-Format-ISO8601 \
			p5-DateTime>=1.54:devel/p5-DateTime
XS_BUILD_DEPENDS=	p5-XML-LibXML>=2.0206,1:textproc/p5-XML-LibXML
XS_RUN_DEPENDS=		${XS_BUILD_DEPENDS}

.include <bsd.port.mk>
