# New ports collection makefile for:	p5-Mail-ListDetector
# Date created:				13 August 2001
# Whom:					petef
#
# $FreeBSD$
#

PORTNAME=	Mail-ListDetector
PORTVERSION=	0.22
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Mail
PKGNAMEPREFIX=	p5-

MAINTAINER=	petef@FreeBSD.org

BUILD_DEPENDS=	${SITE_PERL}/Email/Valid.pm:${PORTSDIR}/mail/p5-Email-Valid \
		${SITE_PERL}/Mail/Internet.pm:${PORTSDIR}/mail/p5-Mail-Tools \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

SITE_PERL=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}
PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=	Mail::ListDetector.3 \
	Mail::ListDetector::Detector::Base.3 \
	Mail::ListDetector::Detector::Ecartis.3 \
	Mail::ListDetector::Detector::Ezmlm.3 \
	Mail::ListDetector::Detector::Listar.3 \
	Mail::ListDetector::Detector::Mailman.3 \
	Mail::ListDetector::Detector::Majordomo.3 \
	Mail::ListDetector::Detector::RFC2369.3 \
	Mail::ListDetector::Detector::RFC2919.3 \
	Mail::ListDetector::Detector::Smartlist.3 \
	Mail::ListDetector::Detector::Yahoogroups.3 \
	Mail::ListDetector::List.3

post-install:
	@${MKDIR} ${PREFIX}/share/examples/Mail-ListDetector
	${INSTALL_SCRIPT} ${WRKSRC}/examples/sample.pl \
		${PREFIX}/share/examples/Mail-ListDetector

.include <bsd.port.mk>
