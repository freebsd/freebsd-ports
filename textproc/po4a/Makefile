# Created by: Meno Abels <meno.abels@adviser.com>

PORTNAME=	po4a
DISTVERSIONPREFIX=	v
DISTVERSION=	0.66
PORTREVISION=	1
CATEGORIES=	textproc perl5

PATCH_SITES=	https://github.com/mquinson/po4a/commit/
PATCHFILES=	fa2546f7a0f327603f7e1cffa8415101acce8a90.diff:-p1 \
		49902aebbab06e3a376d231eb299fcd3c30d1722.diff:-p1

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Brings gettext translation tools to all kinds of docs

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${RUN_DEPENDS} \
		${P5_POD_PARSER}
RUN_DEPENDS=	p5-Term-ReadKey>=2.30:devel/p5-Term-ReadKey \
		p5-Text-WrapI18N>=0.06:textproc/p5-Text-WrapI18N \
		p5-SGMLSpm>=1.03:textproc/p5-SGMLSpm \
		p5-Locale-gettext>=1.05:devel/p5-Locale-gettext \
		p5-Unicode-LineBreak>=0:textproc/p5-Unicode-LineBreak \
		p5-YAML-Tiny>=0:textproc/p5-YAML-Tiny \
		jade>=0:textproc/jade \
		xsltproc:textproc/libxslt \
		docbook-xsl>0:textproc/docbook-xsl \
		OpenSP>0:textproc/opensp \
		msgmerge:devel/gettext-tools

USES=		cpe gettext perl5
USE_PERL5=	modbuild

USE_GITHUB=	yes
GH_ACCOUNT=	mquinson

NO_ARCH=	yes

.include <bsd.port.mk>
