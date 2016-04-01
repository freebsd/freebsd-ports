# Created by: arved
# $FreeBSD$

PORTNAME=	nagios-spamd-plugin
PORTVERSION=	1.4
PORTREVISION=	3
CATEGORIES=	net-mgmt
MASTER_SITES=	ftp://jhweiss.de/pub/users/weiss/nagios/plugins/
DISTNAME=	check_spamd-${PORTVERSION}.pl
EXTRACT_SUFX=	# empty

MAINTAINER=	alexey@renatasystems.org
COMMENT=	Nagios plugin for checking SpamAssassins spamd

RUN_DEPENDS+=	${LOCALBASE}/${NAGIOS_PLUGIN_DIR}/utils.pm:net-mgmt/nagios-plugins

USES=		perl5 shebangfix
SHEBANG_FILES=	check_spamd.pl
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
PLIST_FILES=	${NAGIOS_PLUGIN_DIR}/check_spamd.pl

NAGIOS_PLUGIN_DIR=	libexec/nagios

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/${DISTNAME} ${WRKSRC}/check_spamd.pl

post-patch:
	${REINPLACE_CMD} -e \
		"s,/usr/local/nagios/libexec,${PREFIX}/${NAGIOS_PLUGIN_DIR}," \
		${WRKSRC}/check_spamd.pl

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${NAGIOS_PLUGIN_DIR}
	${INSTALL_SCRIPT} ${WRKSRC}/check_spamd.pl ${STAGEDIR}${PREFIX}/${NAGIOS_PLUGIN_DIR}

.include <bsd.port.mk>
