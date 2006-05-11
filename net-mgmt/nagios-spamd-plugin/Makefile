# New ports collection makefile for:	nagios-spamd-plugin
# Date created:				2005-10-29
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	nagios-spamd-plugin
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	ftp://jhweiss.de/pub/users/weiss/nagios/plugins/
DISTNAME=	check_spamd.pl
EXTRACT_SUFX=

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Nagios plugin for checking SpamAssassins spamd

RUN_DEPENDS+=	${SITE_PERL}/Getopt/Long.pm:${PORTSDIR}/devel/p5-Getopt-Long

USE_PERL5=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
PLIST_FILES=	${NAGIOS_PLUGIN_DIR}/check_spamd.pl
PLIST_DIRS=	${NAGIOS_PLUGIN_DIR}

NAGIOS_PLUGIN_DIR=	libexec/nagios

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/${DISTNAME} ${WRKSRC}

post-patch:
	${REINPLACE_CMD} -e \
		"s,/usr/local/nagios/libexec,${PREFIX}/${NAGIOS_PLUGIN_DIR}," \
		${WRKSRC}/check_spamd.pl

do-install:
	${MKDIR} ${PREFIX}/${NAGIOS_PLUGIN_DIR}
	${INSTALL_SCRIPT} ${WRKSRC}/check_spamd.pl ${PREFIX}/${NAGIOS_PLUGIN_DIR}

.include <bsd.port.mk>
