# New ports collection makefile for:	p5-Mail-ListDetector
# Date created:				13 August 2001
# Whom:					petef
#
# $FreeBSD$
#

PORTNAME=	Mail-ListDetector
PORTVERSION=	0.31
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Mail
PKGNAMEPREFIX=	p5-

MAINTAINER=	petef@FreeBSD.org
COMMENT=	Perl module for detecting mailing list messages

BUILD_DEPENDS=	${SITE_PERL}/Email/Valid.pm:${PORTSDIR}/mail/p5-Email-Valid \
		${SITE_PERL}/Email/Abstract.pm:${PORTSDIR}/mail/p5-Email-Abstract \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Mail::ListDetector.3 \
	Mail::ListDetector::Detector::AutoShare.3 \
	Mail::ListDetector::Detector::Base.3 \
	Mail::ListDetector::Detector::CommuniGate.3 \
	Mail::ListDetector::Detector::CommuniGatePro.3 \
	Mail::ListDetector::Detector::Ecartis.3 \
	Mail::ListDetector::Detector::Ezmlm.3 \
	Mail::ListDetector::Detector::Fml.3 \
	Mail::ListDetector::Detector::GoogleGroups.3 \
	Mail::ListDetector::Detector::LetterRip.3 \
	Mail::ListDetector::Detector::ListSTAR.3 \
	Mail::ListDetector::Detector::Listar.3 \
	Mail::ListDetector::Detector::Listbox.3 \
	Mail::ListDetector::Detector::Listserv.3 \
	Mail::ListDetector::Detector::Lyris.3 \
	Mail::ListDetector::Detector::Mailman.3 \
	Mail::ListDetector::Detector::Majordomo.3 \
	Mail::ListDetector::Detector::Onelist.3 \
	Mail::ListDetector::Detector::RFC2369.3 \
	Mail::ListDetector::Detector::RFC2919.3 \
	Mail::ListDetector::Detector::Smartlist.3 \
	Mail::ListDetector::Detector::Yahoogroups.3 \
	Mail::ListDetector::List.3

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/sample.pl \
		${EXAMPLESDIR}

.include <bsd.port.mk>
