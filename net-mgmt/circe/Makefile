# New ports collection makefile for: circe
# Date created:		23 July 2010
# Whom:			Berkeley NAC-Team
#
# $FreeBSD$
#

PORTNAME=	circe
PORTVERSION=	0.2.3
CATEGORIES=	net-mgmt
MASTER_SITES=	http://bws.berkeley.edu/ports/

MAINTAINER=	circe-port-maintainers@bws.net.berkeley.edu
COMMENT=	A captive portal-based network access control solution in perl

LICENSE=	BSD

RUN_DEPENDS=	${SITE_PERL}/mach/Net/IP/Match/XS.pm:${PORTSDIR}/net-mgmt/p5-Net-IP-Match-XS \
		${SITE_PERL}/IO/Socket/SSL.pm:${PORTSDIR}/security/p5-IO-Socket-SSL \
		${SITE_PERL}/${PERL_ARCH}/IO.pm:${PORTSDIR}/devel/p5-IO \
		${SITE_PERL}/Error.pm:${PORTSDIR}/lang/p5-Error \
		${SITE_PERL}/${PERL_ARCH}/Sys/Syslog.pm:${PORTSDIR}/sysutils/p5-Sys-Syslog \
		${SITE_PERL}/${PERL_ARCH}/TryCatch.pm:${PORTSDIR}/lang/p5-TryCatch \
		${SITE_PERL}/Data/Validate/IP.pm:${PORTSDIR}/net-mgmt/p5-Data-Validate-IP \
		${SITE_PERL}/Regexp/Common.pm:${PORTSDIR}/textproc/p5-Regexp-Common \
		${SITE_PERL}/Getopt/Long.pm:${PORTSDIR}/devel/p5-Getopt-Long \
		${SITE_PERL}/${PERL_ARCH}/BerkeleyDB.pm:${PORTSDIR}/databases/p5-BerkeleyDB \
		${SITE_PERL}/Crypt/CBC.pm:${PORTSDIR}/security/p5-Crypt-CBC \
		${SITE_PERL}/Proc/PID/File.pm:${PORTSDIR}/devel/p5-Proc-PID-File

USE_PERL5=	yes

DIST_SUBDIR=	${PORTNAME}
WRKSRC=		${WRKDIR}

OPTIONS=	ENCRYPT "Encrypt the destination URL in redirection" Off

.include <bsd.port.options.mk>

.if defined(WITH_ENCRYPT)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Crypt/DES.pm:${PORTSDIR}/security/p5-Crypt-DES \
		${SITE_PERL}/${PERL_ARCH}/Crypt/OpenSSL/AES.pm:${PORTSDIR}/security/p5-Crypt-OpenSSL-AES
.endif

MANCOMPRESSED=	no

post-patch:
	@${REINPLACE_CMD} -e 's|$$(SITE_PERL)|${PREFIX}/${SITE_PERL_REL}|g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|$$(SITE_PERL_REL)|${SITE_PERL_REL}|g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
