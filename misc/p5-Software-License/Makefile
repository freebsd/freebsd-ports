# New ports collection makefile for:	Software::License
# Date created:				11 May 2010
# Whom:					Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Software-License
PORTVERSION=	0.016
CATEGORIES=	misc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/R/RJ/RJBS
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Packages that provide templated software licenses

BUILD_DEPENDS=	p5-Data-Section>=0:${PORTSDIR}/devel/p5-Data-Section \
		p5-Sub-Install>=0:${PORTSDIR}/devel/p5-Sub-Install \
		p5-Text-Template>=0:${PORTSDIR}/textproc/p5-Text-Template
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Software::License.3 \
		Software::License::AGPL_3.3 \
		Software::License::Apache_1_1.3 \
		Software::License::Apache_2_0.3 \
		Software::License::Artistic_1_0.3 \
		Software::License::Artistic_2_0.3 \
		Software::License::BSD.3 \
		Software::License::CC0_1_0.3 \
		Software::License::FreeBSD.3 \
		Software::License::GFDL_1_2.3 \
		Software::License::GPL_1.3 \
		Software::License::GPL_2.3 \
		Software::License::GPL_3.3 \
		Software::License::LGPL_2_1.3 \
		Software::License::LGPL_3_0.3 \
		Software::License::MIT.3 \
		Software::License::Mozilla_1_0.3 \
		Software::License::Mozilla_1_1.3 \
		Software::License::None.3 \
		Software::License::OpenSSL.3 \
		Software::License::Perl_5.3 \
		Software::License::QPL_1_0.3 \
		Software::License::SSLeay.3 \
		Software::License::Sun.3 \
		Software::License::Zlib.3 \
		Software::LicenseUtils.3

.include <bsd.port.mk>
