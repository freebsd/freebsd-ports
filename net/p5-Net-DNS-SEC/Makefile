# New ports collection makefile for:	p5-Net-DNS-SEC
# Date created:			21 July 2002
# Whom:				Kimura Fuyuki <fuyuki@hadaly.org>
#
# $FreeBSD$
#

PORTNAME=	Net-DNS-SEC
PORTVERSION=	0.07
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN} \
		http://www.ripe.net/ripencc/pub-services/np/DISI/SRC/
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Net/DNS.pm:${PORTSDIR}/net/p5-Net-DNS \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Crypt/OpenSSL/RSA.pm:${PORTSDIR}/security/p5-Crypt-OpenSSL-RSA \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Crypt/OpenSSL/DSA.pm:${PORTSDIR}/security/p5-Crypt-OpenSSL-DSA \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Net::DNS::Keyset.3 Net::DNS::RR::DS.3 Net::DNS::RR::KEY.3 \
		Net::DNS::RR::NXT.3 Net::DNS::RR::SIG.3 Net::DNS::SEC.3

.include <bsd.port.mk>
