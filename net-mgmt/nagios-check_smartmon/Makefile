PORTNAME=	check_smartmon
PORTVERSION=	20100318
PORTREVISION=	5
CATEGORIES=	net-mgmt
MASTER_SITES=	http://ftp.bsdserwis.com/pub/FreeBSD/ports/distfiles/
PKGNAMEPREFIX=	nagios-
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}

MAINTAINER=	ports@bsdserwis.com
COMMENT=	Nagios plug-in to get status from smartmontools

LICENSE=	GPLv2+

RUN_DEPENDS=	${LOCALBASE}/sbin/smartctl:sysutils/smartmontools

USES=		python shebangfix
USE_PYTHON=	concurrent

SHEBANG_FILES=	check_smartmon

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	libexec/nagios/check_smartmon

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/nagios
	${INSTALL_SCRIPT} ${WRKSRC}/check_smartmon \
		${STAGEDIR}${PREFIX}/libexec/nagios

.include <bsd.port.mk>
