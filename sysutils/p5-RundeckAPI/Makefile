PORTNAME=	RundeckAPI
DISTVERSION=	1.3.4.1
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:XAVIERH
PKGNAMEPREFIX=	p5-

MAINTAINER=	xavier@groumpf.org
COMMENT=	Easily queries Rundeck's REST API

LICENSE=	GPLv2

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-HTTP-Cookies>0:www/p5-HTTP-Cookies \
		p5-REST-Client>=0:www/p5-REST-Client

USES=		perl5
USE_PERL5=	configure

PLIST_FILES=	${SITE_MAN3_REL}/RundeckAPI.3.gz \
		${SITE_PERL_REL}/RundeckAPI.pm

.include <bsd.port.mk>
