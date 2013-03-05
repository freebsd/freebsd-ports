# Created by: TANAKA Takashi <tanaka@tahi.org>
# $FreeBSD$

PORTNAME=	ct
PORTVERSION=	2.1.2
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.tahi.org/release/ct/

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	IPv6 Conformance Test Kit

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

RUN_DEPENDS=	${LOCALBASE}/v6eval/bin/pktbuf:${PORTSDIR}/net/v6eval

USE_PERL5=      yes
NO_BUILD=	yes

MAKE_ENV+=	"NUTTYPE=host"

.include <bsd.port.mk>
