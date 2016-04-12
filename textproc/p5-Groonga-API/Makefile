# $FreeBSD$

PORTNAME=	Groonga-API
PORTVERSION=	0.03.20150303
CATEGORIES=	textproc perl5
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for raw interface to Groonga

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BROKEN=		fails to build

USE_GITHUB=	yes
GH_ACCOUNT=	charsbar
GH_PROJECT=	${PORTNAME:tl}
GH_TAGNAME=	314060b

RUN_DEPENDS=	\
	p5-JSON-XS>0:converters/p5-JSON-XS \
	p5-Path-Extended>0:devel/p5-Path-Extended \
	p5-Test-Differences>0:devel/p5-Test-Differences \
	p5-Test-UseAllModules>=0.10:devel/p5-Test-UseAllModules
BUILD_DEPENDS=	${RUN_DEPENDS}
LIB_DEPENDS=	libgroonga.so:textproc/groonga

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
