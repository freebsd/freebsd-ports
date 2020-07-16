# Created by: vanilla@
# $FreeBSD$

PORTNAME=	Test-Nginx
PORTVERSION=	0.28
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Testing modules for Nginx C module development

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Test-LongString>=0:devel/p5-Test-LongString \
		p5-Test-Base>=0:devel/p5-Test-Base \
		p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-Text-Diff>=0:textproc/p5-Text-Diff \
		p5-libwww>=6:www/p5-libwww

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
