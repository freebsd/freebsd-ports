# New ports collection makefile for:	p5-MIME-Tools
# Date created:				April 27th 1998
# Whom:	      				Eivind Eklund <eivind@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MIME-Tools
PORTVERSION=	5.502
PORTEPOCH=	2
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DSKOLL
PKGNAMEPREFIX=	p5-
DISTNAME=	MIME-tools-${PORTVERSION}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A set of perl5 modules for MIME

RUN_DEPENDS=	p5-Convert-BinHex>=0:${PORTSDIR}/converters/p5-Convert-BinHex \
		p5-IO-stringy>=2.11:${PORTSDIR}/devel/p5-IO-stringy \
		p5-Mail-Tools>=1.0203:${PORTSDIR}/mail/p5-Mail-Tools
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=	MIME::Body.3 \
	MIME::Decoder.3	\
	MIME::Decoder::Base64.3 \
	MIME::Decoder::BinHex.3 \
	MIME::Decoder::Binary.3 \
	MIME::Decoder::Gzip64.3	\
	MIME::Decoder::NBit.3 \
	MIME::Decoder::QuotedPrint.3 \
	MIME::Decoder::UU.3 \
	MIME::Entity.3 \
	MIME::Field::ConTraEnc.3 \
	MIME::Field::ContDisp.3 \
	MIME::Field::ContType.3 \
	MIME::Field::ParamVal.3 \
	MIME::Head.3 \
	MIME::Parser.3 \
	MIME::Parser::Filer.3 \
	MIME::Parser::Reader.3 \
	MIME::Parser::Results.3 \
	MIME::Tools.3 \
	MIME::WordDecoder.3 \
	MIME::Words.3

.if !defined(NOPORTDOCS)
PORTDOCS=	ChangeLog README

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
