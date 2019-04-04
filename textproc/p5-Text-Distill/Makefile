# $FreeBSD$

PORTNAME=	Text-Distill
PORTVERSION=	0.2
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:GRIBUSER
PKGNAMEPREFIX=	p5-

MAINTAINER=	oleg@mamontov.net
COMMENT=	Quick texts compare, plagiarism and common parts detection

LICENSE=	LGPL3
LICENSE_COMB=	single

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Archive-Zip>=0:archivers/p5-Archive-Zip \
		p5-Digest-JHash>=0:security/p5-Digest-JHash \
		p5-Encode-Detect>=0:converters/p5-Encode-Detect \
		p5-HTML-Tree>=0:www/p5-HTML-Tree \
		p5-JSON-XS>=0:converters/p5-JSON-XS \
		p5-libwww>=0:www/p5-libwww \
		p5-OLE-Storage_Lite>=0:devel/p5-OLE-Storage_Lite \
		p5-Text-Extract-Word>=0:textproc/p5-Text-Extract-Word \
		p5-Text-Unidecode>=1.27:converters/p5-Text-Unidecode \
		p5-Unicode-Normalize>=1.25:textproc/p5-Unicode-Normalize \
		p5-XML-LibXML>=0:textproc/p5-XML-LibXML \
		p5-XML-LibXSLT>=0:textproc/p5-XML-LibXSLT

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
