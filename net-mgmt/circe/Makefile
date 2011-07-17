# New ports collection makefile for: circe
# Date created:		23 July 2010
# Whom:			Berkeley NAC-Team
#
# $FreeBSD$
#

PORTNAME=	circe
PORTVERSION=	0.2.1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://bws.berkeley.edu/ports/

MAINTAINER=	circe-port-maintainers@bws.berkeley.edu
COMMENT=	A captive portal-based network access control solution in perl

DIST_SUBDIR=	${PORTNAME}

BUILD_DEPENDS=	${SITE_PERL}/mach/Net/IP/Match/XS.pm:${PORTSDIR}/net-mgmt/p5-Net-IP-Match-XS \
		${SITE_PERL}/IO/Socket/SSL.pm:${PORTSDIR}/security/p5-IO-Socket-SSL \
		${SITE_PERL}/mach/IO.pm:${PORTSDIR}/devel/p5-IO \
		${SITE_PERL}/Error.pm:${PORTSDIR}/lang/p5-Error \
		${SITE_PERL}/mach/Sys/Syslog.pm:${PORTSDIR}/sysutils/p5-Sys-Syslog \
		${SITE_PERL}/mach/TryCatch.pm:${PORTSDIR}/lang/p5-TryCatch \
		${SITE_PERL}/Data/Validate/IP.pm:${PORTSDIR}/net-mgmt/p5-Data-Validate-IP \
		${SITE_PERL}/Regexp/Common.pm:${PORTSDIR}/textproc/p5-Regexp-Common \
		${SITE_PERL}/Getopt/Long.pm:${PORTSDIR}/devel/p5-Getopt-Long \
		${SITE_PERL}/mach/BerkeleyDB.pm:${PORTSDIR}/databases/p5-BerkeleyDB \
		${SITE_PERL}/Crypt/CBC.pm:${PORTSDIR}/security/p5-Crypt-CBC \
		${SITE_PERL}/Proc/PID/File.pm:${PORTSDIR}/devel/p5-Proc-PID-File

MANCOMPRESSED=	no

post-patch:
	@${REINPLACE_CMD} -e 's|$$(SITE_PERL)|${SITE_PERL}|g' ${WRKSRC}/Makefile

WRKSRC=	${WRKDIR}

.include <bsd.port.mk>
