# New ports collection makefile for:	p5-MIME-Tools
# Version required:			4.121
# Date created:				April 27th 1998
# Whom:	      				Eivind Eklund <eivind@FreeBSD.ORG>
#
# $Id: Makefile,v 1.2 1998/05/07 16:28:35 vanilla Exp $
#

DISTNAME=	MIME-tools-4.121
PKGNAME=	p5-MIME-Tools-4.121
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	MIME

MAINTAINER=	eivind@FreeBSD.ORG

RUN_DEPENDS=	${PREFIX}/lib/perl5/site_perl/Mail/Header.pm:${PORTSDIR}/mail/p5-Mail-Tools \
		${PREFIX}/lib/perl5/site_perl/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64	\
		${PREFIX}/lib/perl5/site_perl/IO/Wrap.pm:${PORTSDIR}/devel/p5-IO-stringy

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
MANPREFIX=	${PREFIX}/lib/perl5

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
