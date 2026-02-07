PORTNAME=	Mojolicious-Plugin-RenderFile
PORTVERSION=	0.12
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	teru-sama@riseup.net
COMMENT=	RenderFile plugin for Mojolicious
WWW=		https://metacpan.org/dist/Mojolicious-Plugin-RenderFile

LICENSE=	ART20

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Mojolicious>=1:www/p5-Mojolicious

PLIST_FILES=	lib/perl5/site_perl/Mojolicious/Plugin/RenderFile.pm \
		lib/perl5/site_perl/man/man3/Mojolicious::Plugin::RenderFile.3.gz

.include <bsd.port.mk>
