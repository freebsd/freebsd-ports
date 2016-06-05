# $FreeBSD$

PORTNAME=	Dancer
PORTVERSION=	1.3202
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:YANICK
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for minimal-effort oriented web application framework

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-HTTP-Body>0:www/p5-HTTP-Body \
	p5-HTTP-Date>0:www/p5-HTTP-Date \
	p5-HTTP-Message>0:www/p5-HTTP-Message \
	p5-HTTP-Server-Simple-PSGI>0:www/p5-HTTP-Server-Simple-PSGI \
	p5-Hash-Merge-Simple>0:devel/p5-Hash-Merge-Simple \
	p5-libwww>0:www/p5-libwww \
	p5-MIME-Types>0:mail/p5-MIME-Types \
	p5-Module-Runtime>0:devel/p5-Module-Runtime \
	p5-Try-Tiny>0:lang/p5-Try-Tiny \
	p5-URI>0:net/p5-URI
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-Devel-Hide>=0:devel/p5-Devel-Hide \
	p5-Test-TCP>0:devel/p5-Test-TCP \
	p5-Test-Output>=0:devel/p5-Test-Output

OPTIONS_DEFINE=	YAML
OPTIONS_DEFAULT=	YAML

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MYAML}
RUN_DEPENDS+=	p5-YAML>0:textproc/p5-YAML
.endif

USES=	perl5
USE_PERL5=	configure
NO_ARCH=	YES

.include <bsd.port.mk>
