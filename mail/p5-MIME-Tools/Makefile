# New ports collection makefile for:	p5-MIME-Tools
# Date created:				April 27th 1998
# Whom:	      				Eivind Eklund <eivind@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	p5-MIME-Tools
PORTVERSION=	6.200.02
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/E/ER/ERYQ
DISTNAME=	MIME-tools-${PORTVERSION:R}_${PORTVERSION:E}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	A set of perl5 modules for MIME

BUILD_DEPENDS=	${SITE_PERL}/Mail/Header.pm:${PORTSDIR}/mail/p5-Mail-Tools \
		${SITE_PERL}/IO/Wrap.pm:${PORTSDIR}/devel/p5-IO-stringy \
		${SITE_PERL}/${PERL_ARCH}/Unicode/Map.pm:${PORTSDIR}/converters/p5-Unicode-Map \
		${SITE_PERL}/${PERL_ARCH}/Unicode/String.pm:${PORTSDIR}/converters/p5-Unicode-String
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=	MIME::Body.3 \
	MIME::Decoder.3	\
	MIME::Decoder::Base64.3 \
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
	MIME::Parser::AbstractFiler.3 \
	MIME::Parser::Filer.3 \
	MIME::Parser::FlatFiler.3 \
	MIME::Parser::Reader.3 \
	MIME::Parser::Redoer.3 \
	MIME::Parser::Results.3 \
	MIME::Parser::TreeFiler.3 \
	MIME::Parser::UURedoer.3 \
	MIME::Tools.3 \
	MIME::Tools::IndentingLogger.3 \
	MIME::Tools::Logger.3 \
	MIME::Tools::MailFieldParserForRFC2045.3 \
	MIME::Tools::MailFieldTokenizerForRFC2045.3 \
	MIME::Tools::NullLogger.3 \
	MIME::Tools::PrefixingLogger.3 \
	MIME::Tools::ToolkitLogger.3 \
	MIME::Tools::Utils.3 \
	MIME::Tools::changes.3 \
	MIME::Tools::config.3 \
	MIME::Tools::diag.3 \
	MIME::Tools::faq.3 \
	MIME::Tools::overview.3 \
	MIME::Tools::primer.3 \
	MIME::Tools::tips.3 \
	MIME::Tools::traps.3 \
	MIME::Tools::tricks.3 \
	MIME::WordDecoder.3 \
	MIME::Words.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64
.endif
.if ${PERL_LEVEL} < 500600
IGNORE=		5.005 is not supported
.endif

.include <bsd.port.post.mk>
