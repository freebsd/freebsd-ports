PORTNAME=	check_clamav
DISTVERSION=	1.2
PORTREVISION=	4
CATEGORIES=	net-mgmt
MASTER_SITES=	https://ftp.bsdserwis.com/pub/FreeBSD/ports/distfiles/
PKGNAMEPREFIX=	nagios-

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Nagios plugin that verifies ClamAV local signature database revision
WWW=		https://exchange.nagios.org/directory/Plugins/Anti-2DVirus/ClamAV/ClamAV-check-plugin/details

LICENSE=	MIT
LICENSE_FILE=	${FILESDIR}/MIT

RUN_DEPENDS+=	clamav>=0:security/clamav \
		p5-Net-DNS>=0:dns/p5-Net-DNS

USES=		perl5 shebangfix

USE_PERL5=	run
SHEBANG_FILES=	check_clamav

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	libexec/nagios/check_clamav

OPTIONS_DEFAULT=	NAGPLUGINS
OPTIONS_RADIO=		PLUGINS
OPTIONS_RADIO_PLUGINS=	MONPLUGINS NAGPLUGINS

MONPLUGINS_DESC=	Use net-mgmt/monitoring-plugins
NAGPLUGINS_DESC=	Use net-mgmt/nagios-plugins

MONPLUGINS_RUN_DEPENDS=	${LOCALBASE}/libexec/nagios/check_nagios:net-mgmt/monitoring-plugins
NAGPLUGINS_RUN_DEPENDS=	${LOCALBASE}/libexec/nagios/check_nagios:net-mgmt/nagios-plugins

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/nagios
	${INSTALL_SCRIPT} ${WRKSRC}/check_clamav \
		${STAGEDIR}${PREFIX}/libexec/nagios/check_clamav

.include <bsd.port.mk>
