PORTNAME=	Net-TCLink
PORTVERSION=	3.4
PORTREVISION=	2
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	Net_TCLink.pm-${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Module to for connecting to the TrustCommerce payment gateway
WWW=		https://metacpan.org/release/Net_TCLink

LICENSE=	LGPL21

USES=		perl5 ssl
USE_PERL5=	configure

CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.endif

.include <bsd.port.mk>
