# New ports collection makefile for:	p5-MIME-Tools
# Date created:				April 27th 1998
# Whom:	      				Eivind Eklund <eivind@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	p5-MIME-Tools
PORTVERSION=	5.409
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	MIME
DISTNAME=	MIME-tools-${PORTVERSION}

MAINTAINER=	kuriyama@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Mail/Header.pm:${PORTSDIR}/mail/p5-Mail-Tools \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64	\
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/IO/Wrap.pm:${PORTSDIR}/devel/p5-IO-stringy

PERL_CONFIGURE=	YES

MAN3=	MIME::Entity.3 \
	MIME::Decoder::QuotedPrint.3 \
	MIME::Field::ParamVal.3 \
	MIME::Field::ContType.3 \
	MIME::Decoder::Gzip64.3		MIME::Decoder::Base64.3 \
	MIME::Decoder::Binary.3		MIME::Parser.3 \
	MIME::Parser::Filer.3		MIME::Parser::Reader.3 \
	MIME::Parser::Results.3 \
	MIME::Body.3			MIME::Decoder::UU.3 \
	MIME::WordDecoder.3		MIME::Words.3 \
	MIME::Field::ConTraEnc.3	MIME::Tools.3 \
	MIME::Decoder::NBit.3		MIME::Head.3 \
	MIME::Decoder.3			MIME::Field::ContDisp.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
