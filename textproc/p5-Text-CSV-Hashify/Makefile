# Created by: tj@FreeBSD.org
# $FreeBSD$

PORTNAME=	Text-CSV-Hashify
PORTVERSION=	0.05
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JKEENAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Composition and decomposition of comma-separated values into hashes

BUILD_DEPENDS=	p5-Text-CSV>=0:${PORTSDIR}/textproc/p5-Text-CSV
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Text::CSV::Hashify.3

.include <bsd.port.mk>
