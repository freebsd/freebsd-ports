# New ports collection makefile for:	EasyTCP
# Date created:				24 Jan 2002
# Whom:					Seamus Venasse <svenasse@polaris.ca>
#
# $FreeBSD$
#

PORTNAME=		EasyTCP
PORTVERSION=		0.17
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/M/MN/MNAGUIB
PKGNAMEPREFIX=		p5-

MAINTAINER=		svenasse@polaris.ca

BUILD_DEPENDS=		${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable \
			${SITE_PERL}/Crypt/RSA.pm:${PORTSDIR}/security/p5-Crypt-RSA
RUN_DEPENDS=		${BUILD_DEPENDS}

SITE_PERL=		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}
PERL_CONFIGURE=		yes

MAN3=			Net::EasyTCP.3
MANPREFIX=		${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
