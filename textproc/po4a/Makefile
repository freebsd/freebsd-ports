# Created by: Meno Abels <meno.abels@adviser.com>
# $FreeBSD$

PORTNAME=	po4a
PORTVERSION=	0.44
CATEGORIES=	textproc perl5
MASTER_SITES=	LOCAL/garga/po4a/orig \
		http://leaf.dragonflybsd.org/~marino/dports-src/

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Brings gettext translation tools to all kinds of docs

BUILD_DEPENDS=	p5-Term-ReadKey>=2.30:${PORTSDIR}/devel/p5-Term-ReadKey \
		libtext-wrapi18n-perl>=0.06:${PORTSDIR}/textproc/libtext-wrapi18n-perl \
		p5-SGMLSpm>=1.03:${PORTSDIR}/textproc/p5-SGMLSpm \
		p5-Locale-gettext>=1.05:${PORTSDIR}/devel/p5-Locale-gettext \
		jade>=0:${PORTSDIR}/textproc/jade
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		gettext
USE_PERL5=	yes
PERL_MODBUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-v0.40.1

MANPREFIX=	${PREFIX}
MAN3PREFIX=	${MANPREFIX}
MAN3=		\
		Locale::Po4a::Debconf.3 \
		Locale::Po4a::Halibut.3 \
		Locale::Po4a::Html.3 \
		Locale::Po4a::NewsDebian.3 \
		Locale::Po4a::TransTractor.3 \
		Locale::Po4a::Wml.3 \
 		Locale::Po4a::BibTeX.3 \
 		Locale::Po4a::Chooser.3 \
 		Locale::Po4a::Common.3 \
 		Locale::Po4a::Dia.3 \
 		Locale::Po4a::Docbook.3 \
 		Locale::Po4a::Guide.3 \
 		Locale::Po4a::Ini.3 \
 		Locale::Po4a::KernelHelp.3 \
 		Locale::Po4a::LaTeX.3 \
 		Locale::Po4a::Man.3 \
 		Locale::Po4a::Po.3 \
 		Locale::Po4a::Pod.3 \
 		Locale::Po4a::Sgml.3 \
 		Locale::Po4a::TeX.3 \
 		Locale::Po4a::Texinfo.3 \
 		Locale::Po4a::Text.3 \
 		Locale::Po4a::Xhtml.3 \
 		Locale::Po4a::Xml.3
MAN1=		msguntypot.1 \
		po4a.1 \
		po4a-gettextize.1 \
		po4a-normalize.1 \
		po4a-translate.1 \
		po4a-updatepo.1

PORT_VERBS=	${PORTNAME} Po4a msguntypot

.include <bsd.port.mk>
