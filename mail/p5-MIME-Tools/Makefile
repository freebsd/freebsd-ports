# New ports collection makefile for:	p5-MIME-Tools
# Version required:			4.122
# Date created:				April 27th 1998
# Whom:	      				Eivind Eklund <eivind@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	MIME-tools-4.122
PKGNAME=	p5-MIME-Tools-4.122
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	MIME

MAINTAINER=	eivind@FreeBSD.org

RUN_DEPENDS=	${PREFIX}/lib/perl5/site_perl/${PERL_VER}/Mail/Header.pm:${PORTSDIR}/mail/p5-Mail-Tools \
		${PREFIX}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64	\
		${PREFIX}/lib/perl5/site_perl/${PERL_VER}/IO/Wrap.pm:${PORTSDIR}/devel/p5-IO-stringy

USE_PERL5=	YES

MAN3=	MIME::IO.3			MIME::Entity.3 \
	MIME::Decoder::QuotedPrint.3 \
	MIME::Field::ParamVal.3		MIME::ParserBase.3 \
	MIME::Latin1.3			MIME::Field::ContType.3 \
	MIME::Decoder::Gzip64.3		MIME::Decoder::Base64.3 \
	MIME::Decoder::Binary.3		MIME::Parser.3 \
	MIME::Body.3			MIME::Decoder::UU.3 \
	MIME::Words.3			MIME::ToolUtils.3 \
	MIME::Field::ConTraEnc.3	MIME::Tools.3 \
	MIME::Decoder::NBit.3		MIME::Head.3 \
	MIME::Decoder.3			MIME::Field::ContDisp.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
