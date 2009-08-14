# New ports collection makefile for:   p5-Net-IP
# Date created:                30 May 2002
# Whom:                        Kimura Fuyuki <fuyuki@hadaly.org>
#
# $FreeBSD$
#

PORTNAME=	Net-IP
PORTVERSION=	1.25
PORTREVISION=	1
CATEGORIES=	net-mgmt perl5 ipv6
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	dougb@FreeBSD.org
COMMENT=	Perl extension for manipulating IPv4/IPv6 addresses

RUN_DEPENDS=	${SITE_PERL}/Math/BigInt.pm:${PORTSDIR}/math/p5-Math-BigInt
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::IP.3

post-configure:
	${PERL} -pi -e 's/-I\S+PERL\S+ //g if m{PERL_DL_NONLAZY}' ${WRKSRC}/Makefile

post-patch:
	@${CP} ${WRKSRC}/IP.pm ${WRKSRC}/IP.pm.presed
	@${SED} -e "1853s#\\s+#\s*#g" ${WRKSRC}/IP.pm.presed > \
		${WRKSRC}/IP.pm

.include <bsd.port.mk>
