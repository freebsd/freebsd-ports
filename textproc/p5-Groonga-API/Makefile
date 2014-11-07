# $FreeBSD$

PORTNAME=	Groonga-API
PORTVERSION=	0.03
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ISHIGAKI
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for raw interface to Groonga

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-JSON-XS>0:${PORTSDIR}/converters/p5-JSON-XS \
	p5-Path-Extended>0:${PORTSDIR}/devel/p5-Path-Extended \
	p5-Test-Differences>0:${PORTSDIR}/devel/p5-Test-Differences \
	p5-Test-UseAllModules>=0.10:${PORTSDIR}/devel/p5-Test-UseAllModules
BUILD_DEPENDS=	${RUN_DEPENDS}
LIB_DEPENDS=	libgroonga.so:${PORTSDIR}/textproc/groonga

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
