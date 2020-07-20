# Created by: Meno Abels <meno.abels@adviser.com>
# $FreeBSD$

PORTNAME=	po4a
PORTVERSION=	0.51
CATEGORIES=	textproc perl5
MASTER_SITES=	https://alioth.debian.org/frs/download.php/file/4214/

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Brings gettext translation tools to all kinds of docs

LICENSE=	GPLv2

BUILD_DEPENDS=	${RUN_DEPENDS} \
		${P5_POD_PARSER}
RUN_DEPENDS=	p5-Term-ReadKey>=2.30:devel/p5-Term-ReadKey \
		p5-Text-WrapI18N>=0.06:textproc/p5-Text-WrapI18N \
		p5-SGMLSpm>=1.03:textproc/p5-SGMLSpm \
		p5-Locale-gettext>=1.05:devel/p5-Locale-gettext \
		p5-Unicode-LineBreak>=0:textproc/p5-Unicode-LineBreak \
		jade>=0:textproc/jade \
		xsltproc:textproc/libxslt \
		docbook-xsl>0:textproc/docbook-xsl

USES=		gettext perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
