# Created by: Matthew Seaman <matthew@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Log-Syslog-Fast
PORTVERSION=	0.66
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Send syslog messages over TCP, UDP, or UNIX sockets

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Log-Syslog-Constants>-1.01:sysutils/p5-Log-Syslog-Constants

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Log/Syslog/Fast/Fast.so

# Note: the regression tests for this module depend on receiving an
# ICMP 'port unreachable' message for several of the UDP transmission
# tests.  These won't return the expected output if you have sysctl
# net.inet.udp.blackhole set to 1, and they'll quite likely be
# confused by a some common firewall configurations.

.include <bsd.port.mk>
