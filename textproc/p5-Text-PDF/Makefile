# ex:ts=8
# Ports collection makefile for:	p5-Text-PDF
# Date created:			Apr 28, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Text-PDF
PORTVERSION=	0.19
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Text
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
BINFILE=	pdfbklt pdfrevert pdfstamp
EXAMPLESDIR=	${PREFIX}/share/examples/p5-${PORTNAME}

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=	Text::PDF::Array.3 Text::PDF::Bool.3 Text::PDF::Dict.3 \
	Text::PDF::File.3 Text::PDF::Filter.3 Text::PDF::Name.3 \
	Text::PDF::Number.3 Text::PDF::Objind.3 Text::PDF::Page.3 \
	Text::PDF::Pages.3 Text::PDF::SFont.3 Text::PDF::String.3 \
	Text::PDF::TTFont.3 Text::PDF::TTFont0.3 Text::PDF::Utils.3

post-patch:
.for file in ${BINFILE}
	${SED} -f ${FILESDIR}/trans.sed ${WRKSRC}/scripts/${file}.plx > ${WRKSRC}/scripts/${file}.pl
.endfor

post-install:
.for file in ${BINFILE}
	@${MV} -f ${PREFIX}/bin/${file}.pl ${PREFIX}/bin/${file}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
