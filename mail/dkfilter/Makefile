# New ports collection makefile for:	dkfilter
# Date created:				3 Nov 2005
# Whom:					Yoshisato YANAGISAWA
#
# $FreeBSD$
#

PORTNAME=	dkfilter
PORTVERSION=	0.10
CATEGORIES=	mail
MASTER_SITES=	http://jason.long.name/dkfilter/

MAINTAINER=	yanagisawa@csg.is.titech.ac.jp
COMMENT=	Domainkeys filter for Postfix

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Crypt/OpenSSL/RSA.pm:${PORTSDIR}/security/p5-Crypt-OpenSSL-RSA \
		${SITE_PERL}/Mail/Address.pm:${PORTSDIR}/mail/p5-Mail-Tools \
		${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
		${SITE_PERL}/${PERL_ARCH}/Net/DNS.pm:${PORTSDIR}/dns/p5-Net-DNS \
		${SITE_PERL}/Net/Server.pm:${PORTSDIR}/net/p5-Net-Server \
		${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
USE_RC_SUBR=	dkfilter_in dkfilter_out

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	require Perl 5.8 or newer. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
