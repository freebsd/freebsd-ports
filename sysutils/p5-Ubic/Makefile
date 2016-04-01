# Created by: Dmitry Yashin <dmitry@yashin.su>
# $FreeBSD$

PORTNAME=	Ubic
PORTVERSION=	1.58
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MMCLERIC
PKGNAMEPREFIX=	p5-

MAINTAINER=	dmitry@yashin.su
COMMENT=	Flexible perl-based service manager

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Accessor>=0:devel/p5-Class-Accessor \
		p5-Config-Tiny>=0:devel/p5-Config-Tiny \
		p5-HTTP-Server-Simple>=0:www/p5-HTTP-Server-Simple \
		p5-JSON>=0:converters/p5-JSON \
		p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-Params-Validate>=0:devel/p5-Params-Validate \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Class>=0:devel/p5-Test-Class \
		p5-Test-Fatal>=0:devel/p5-Test-Fatal

USES=		perl5
USE_PERL5=	configure
REINPLACE_ARGS=	-i ''
NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' \
		${WRKSRC}/lib/Ubic/Admin/Setup.pm ${WRKSRC}/lib/Ubic/Settings.pm

.include <bsd.port.mk>
