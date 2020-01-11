# Created by: Zeus Panchenko <zeus@gnu.org.ua>
# $FreeBSD$

PORTNAME=	Crypt-HSXKPasswd
PORTVERSION=	3.6
DISTVERSIONPREFIX=	v
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Secure memorable password generator inspired by XKCD

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	p5-Clone>=0:devel/p5-Clone \
		p5-File-HomeDir>=0:devel/p5-File-HomeDir \
		p5-JSON>=0:converters/p5-JSON \
		p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-Math-Round>=0:math/p5-Math-Round \
		p5-Readonly>=0:devel/p5-Readonly \
		p5-Text-Unidecode>=0:converters/p5-Text-Unidecode \
		p5-Type-Tiny>=0:devel/p5-Type-Tiny
TEST_DEPENDS=	p5-File-Share>=0:devel/p5-File-Share

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
