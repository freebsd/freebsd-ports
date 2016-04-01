# Created by: Douglas K. Rand <rand@iteris.com>
# $FreeBSD$

PORTNAME=	check_relayd_status
PORTVERSION=	1.1
CATEGORIES=	net-mgmt
MASTER_SITES=	# none
PKGNAMEPREFIX=	nagios-
DISTFILES=	# none

MAINTAINER=	rand@iteris.com
COMMENT=	Nagios plug-in to check on the status of relayd

LICENSE=	MPL

RUN_DEPENDS=	${LOCALBASE}/sbin/relayctl:net/relayd

USES=		perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	check_relayd_status
NO_BUILD=	yes

do-extract:
	@${MKDIR} ${WRKSRC}
	${INSTALL_SCRIPT} ${FILESDIR}/check_relayd_status ${WRKSRC}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/nagios
	${INSTALL_SCRIPT} ${WRKSRC}/check_relayd_status ${STAGEDIR}${PREFIX}/libexec/nagios/

.include <bsd.port.mk>
