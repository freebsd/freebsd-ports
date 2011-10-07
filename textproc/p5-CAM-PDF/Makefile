# New ports collection makefile for:	p5-CAM-PDF
# Date created:		2006-07-13
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	CAM-PDF
PORTVERSION=	1.55
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:CDOLAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	PDF manipulation library

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Crypt-RC4>=2.02:${PORTSDIR}/security/p5-Crypt-RC4 \
		p5-Text-PDF>=0.29:${PORTSDIR}/print/p5-Text-PDF

RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		appendpdf.pl.1 changepagestring.pl.1 changepdfstring.pl.1 \
		changerefkeys.pl.1 crunchjpgs.pl.1 deillustrate.pl.1 \
		deletepdfpage.pl.1 extractallimages.pl.1 extractjpgs.pl.1 \
		fillpdffields.pl.1 getpdffontobject.pl.1 getpdfpage.pl.1 \
		getpdfpageobject.pl.1 getpdftext.pl.1 listfonts.pl.1 \
		listimages.pl.1 listpdffields.pl.1 pdfinfo.pl.1 readpdf.pl.1 \
		renderpdf.pl.1 replacepdfobj.pl.1 revertpdf.pl.1 \
		rewritepdf.pl.1 setpdfbackground.pl.1 setpdfpage.pl.1 \
		stamppdf.pl.1 uninlinepdfimages.pl.1

MAN3=		CAM::PDF.3 CAM::PDF::Content.3 CAM::PDF::Decrypt.3 \
		CAM::PDF::GS.3 CAM::PDF::GS::NoText.3 CAM::PDF::Node.3 \
	       	CAM::PDF::PageText.3 CAM::PDF::Renderer::Dump.3 \
		CAM::PDF::Renderer::Images.3 CAM::PDF::Renderer::Text.3 \
		CAM::PDF::Renderer::TextFB.3

.if !defined(NOPORTDOCS)
PORTDOCS=	CHANGES README

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500703
RUN_DEPENDS+=	p5-Digest-MD5>=2.16:${PORTSDIR}/security/p5-Digest-MD5
.endif

.include <bsd.port.post.mk>
