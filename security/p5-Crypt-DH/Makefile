# New ports collection makefile for:    p5-Crypt-DH
# Date created:				2002/03/14
# Whom:					jesper
#
# $FreeBSD$
#

PORTNAME=	Crypt-DH
PORTVERSION=	0.03
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Crypt
PKGNAMEPREFIX=	p5-

MAINTAINER=	jesper@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Math/Pari.pm:${PORTSDIR}/math/p5-Math-Pari \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Crypt/Random.pm:${PORTSDIR}/security/p5-Crypt-Random
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Crypt::DH.3

.include <bsd.port.mk>
