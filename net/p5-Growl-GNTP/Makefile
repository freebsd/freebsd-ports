# New ports collection makefile for:	Growl-GNTP
# Date created:				09 Oct 2011
# Whom:					brix@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	Growl-GNTP
PORTVERSION=	0.10
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	brix@FreeBSD.org
COMMENT=	Perl implementation of the Growl GNTP Protocol (Client Part)

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Data/UUID.pm:${PORTSDIR}/devel/p5-Data-UUID \
		${SITE_PERL}/Crypt/CBC.pm:${PORTSDIR}/security/p5-Crypt-CBC
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Growl::GNTP.3

.include <bsd.port.mk>
