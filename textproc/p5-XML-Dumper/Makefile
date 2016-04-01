# Created by: Anton Berezin <tobez@tobez.org>
# $FreeBSD$

PORTNAME=	XML-Dumper
PORTVERSION=	0.81
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module for dumping Perl objects from/to XML

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-XML-Parser>=0:textproc/p5-XML-Parser
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
