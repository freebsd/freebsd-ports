# $FreeBSD$

PORTNAME=	Pod-Readme
PORTVERSION=	0.11
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Convert POD to README file

BUILD_DEPENDS=	p5-Regexp-Common>=0:${PORTSDIR}/textproc/p5-Regexp-Common
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5 shebangfix
USE_PERL5=	configure
SHEBANG_FILES=	bin/pod2readme t/*
USE_DOS2UNIX=	yes

MAN1=		pod2readme.1
MAN3=		Pod::Readme.3

NO_STAGE=	yes
.include <bsd.port.mk>
