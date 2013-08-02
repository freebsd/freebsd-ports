# Created by: petef
# $FreeBSD$

PORTNAME=	Mail-ListDetector
PORTVERSION=	1.04
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MSTEVENS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module for detecting mailing list messages

RUN_DEPENDS=	p5-Email-Abstract>=3.001:${PORTSDIR}/mail/p5-Email-Abstract \
		p5-Email-Valid>=0.182:${PORTSDIR}/mail/p5-Email-Valid \
		p5-Mail-Tools>=2.04:${PORTSDIR}/mail/p5-Mail-Tools \
		p5-URI>=1.1:${PORTSDIR}/net/p5-URI
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

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
	${INSTALL_SCRIPT} ${WRKSRC}/examples/sample.pl ${EXAMPLESDIR}

.include <bsd.port.mk>
