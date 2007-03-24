# New ports collection makefile for:	nagios-certexp-plugin
# Date created:				2007-03-20
# Whom:					ecronin@gizmolabs.org
#
# $FreeBSD$

PORTNAME=	nagios-certexp-plugin
PORTVERSION=	1.1
CATEGORIES=	net-mgmt
MASTER_SITES=	ftp://jhweiss.de/pub/users/weiss/nagios/plugins/
DISTNAME=	check_certexp.pl
EXTRACT_SUFX=

MAINTAINER=	ecronin@gizmolabs.org
COMMENT=	Nagios plugin for checking SSL server certificate expiration

RUN_DEPENDS+=	${SITE_PERL}/mach/Net/SSLeay.pm:${PORTSDIR}/security/p5-Net-SSLeay \
		${SITE_PERL}/Date/Manip.pm:${PORTSDIR}/devel/p5-Date-Manip \
		${SITE_PERL}/Getopt/Long.pm:${PORTSDIR}/devel/p5-Getopt-Long

USE_PERL5=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
PLIST_FILES=	${NAGIOS_PLUGIN_DIR}/check_certexp.pl
PLIST_DIRS=	${NAGIOS_PLUGIN_DIR}

NAGIOS_PLUGIN_DIR=	libexec/nagios

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/${DISTNAME} ${WRKSRC}/check_certexp.pl

post-patch:
	${REINPLACE_CMD} -e \
		"s,/usr/local/nagios/libexec,${PREFIX}/${NAGIOS_PLUGIN_DIR}," \
		${WRKSRC}/check_certexp.pl

do-install:
	${MKDIR} ${PREFIX}/${NAGIOS_PLUGIN_DIR}
	${INSTALL_SCRIPT} ${WRKSRC}/check_certexp.pl ${PREFIX}/${NAGIOS_PLUGIN_DIR}

.include <bsd.port.mk>
