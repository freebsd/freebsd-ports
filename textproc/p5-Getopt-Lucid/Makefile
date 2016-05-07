# Created by: Felippe de Meirelles Motta <lippemail@gmail.com>
# $FreeBSD$

PORTNAME=	Getopt-Lucid
PORTVERSION=	1.06
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Clear, readable syntax for command line processing

LICENSE=	APACHE20

BUILD_DEPENDS=	p5-Exception-Class>=1.23:devel/p5-Exception-Class
RUN_DEPENDS+=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Exception-Class-TryCatch>=1.10:devel/p5-Exception-Class-TryCatch

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
