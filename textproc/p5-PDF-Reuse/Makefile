# $FreeBSD$

PORTNAME=	PDF-Reuse
DISTVERSION=	0.39
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	gehm@doom-labs.net
COMMENT=	Another perl module to reuse and mass produce PDF documents

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Font-TTF>=0:x11-fonts/p5-Font-TTF\
		p5-IO-Compress>=0:archivers/p5-IO-Compress \
		p5-Text-PDF>=0:print/p5-Text-PDF

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
