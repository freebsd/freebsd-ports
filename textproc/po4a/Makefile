# New ports collection makefile for:	po4a
# Date created:				08 January 2006
# Whom:					Meno Abels <meno.abels@adviser.com>
#
# $FreeBSD$
#

PORTNAME=	po4a
PORTVERSION=	0.32
PORTREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	http://alioth.debian.org/frs/download.php/2108/ GENTOO/distfiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Brings gettext translation tools to all kinds of docs

BUILD_DEPENDS=	p5-Term-ReadKey>=2.30:${PORTSDIR}/devel/p5-Term-ReadKey \
		libtext-wrapi18n-perl>=0.06:${PORTSDIR}/textproc/libtext-wrapi18n-perl \
		p5-SGMLSpm>=1.03:${PORTSDIR}/textproc/p5-SGMLSpm \
		p5-gettext>=1.05:${PORTSDIR}/devel/p5-Locale-gettext

USE_GETTEXT=	yes
USE_PERL5=	yes
PERL_MODBUILD=	yes

MANPREFIX=	${PREFIX}
MAN3PREFIX=	${MANPREFIX}
MANLANG=	"" ca es fr it pl
MAN3=		\
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
 		Locale::Po4a::Pod.3 \
 		Locale::Po4a::Po.3 \
 		Locale::Po4a::Sgml.3 \
 		Locale::Po4a::TeX.3 \
 		Locale::Po4a::Texinfo.3 \
 		Locale::Po4a::Text.3 \
		Locale::Po4a::TransTractor.3 \
 		Locale::Po4a::Xhtml.3 \
 		Locale::Po4a::Xml.3
MAN1=		msguntypot.1 \
		po4a.1 \
		po4a-gettextize.1 \
		po4a-normalize.1 \
		po4a-translate.1 \
		po4a-updatepo.1
MAN7=		po4a.7

PORT_VERBS=	${PORTNAME} Po4a msguntypot

post-patch:
	@${REINPLACE_CMD} -e '/install_path/s|/locale|/share&|;/my .options/s|-v|-k 0 &|;\
		s|gzip|${TRUE}|g;s|3pm|3|g;s|1p|1|g' ${WRKSRC}/Build.PL

post-install:
	@${GZIP_CMD} ${MAN1PREFIX}/man/man1/po4aman-display-po.1

enrich-plist:
	@${ECHO_CMD} 'man/man1/po4aman-display-po.1${MANEXT}' >> ${PLIST}
	@for i in ${MANLANG:M[a-z]*};do for n in 1 3 7;do\
		${ECHO_CMD} "@dirrmtry man/$$i/man$$n" >> ${PLIST};\
		${ECHO_CMD} "@dirrmtry man/$$i" >> ${PLIST};done;done

.include <bsd.port.mk>
