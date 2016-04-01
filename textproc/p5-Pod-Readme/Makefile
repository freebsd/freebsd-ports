# $FreeBSD$

PORTNAME=	Pod-Readme
PORTVERSION=	0.11
PORTREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Convert POD to README file

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Regexp-Common>=0:textproc/p5-Regexp-Common
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5 shebangfix dos2unix
USE_PERL5=	configure
SHEBANG_FILES=	bin/pod2readme t/*

.include <bsd.port.mk>
