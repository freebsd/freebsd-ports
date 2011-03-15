# New ports collection makefile for: circe
# Date created:		23 July 2010
# Whom:			Berkeley NAC-Team
#
# $FreeBSD$
#

PORTNAME=	circe
PORTVERSION=	0.1.2
CATEGORIES=	net-mgmt
MASTER_SITES=	http://bws.berkeley.edu/ports/

MAINTAINER=	circe-port-maintainers@bws.berkeley.edu
COMMENT=	Code that implements a perl based circe captive portal system

DIST_SUBDIR=	${PORTNAME}

BUILD_DEPENDS=	${SITE_PERL}/mach/Net/IP/Match/XS.pm:${PORTSDIR}/net-mgmt/p5-Net-IP-Match-XS \
		${SITE_PERL}/IO/Socket/SSL.pm:${PORTSDIR}/security/p5-IO-Socket-SSL \
		${SITE_PERL}/mach/IO.pm:${PORTSDIR}/devel/p5-IO \
		${SITE_PERL}/mach/IO/Interface.pm:${PORTSDIR}/net/p5-IO-Interface \
		${SITE_PERL}/Error.pm:${PORTSDIR}/lang/p5-Error \
		${SITE_PERL}/mach/Sys/Syslog.pm:${PORTSDIR}/sysutils/p5-Sys-Syslog \
		${SITE_PERL}/mach/TryCatch.pm:${PORTSDIR}/lang/p5-TryCatch

MANCOMPRESSED=	no

WRKSRC=	${WRKDIR}

post-patch:
	@${REINPLACE_CMD} -e 's|$$(SITE_PERL)|${SITE_PERL}|g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
