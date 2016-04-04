# Created by: steinex
# $FreeBSD$

PORTNAME=	check_smartmon
PORTVERSION=	20100318
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	http://ftp.bsdserwis.com/pub/FreeBSD/ports/distfiles/
PKGNAMEPREFIX=	nagios-

MAINTAINER=	ports@bsdserwis.com
COMMENT=	Nagios plug-in to get status from smartmontools

LICENSE=	GPLv2+

RUN_DEPENDS=	${LOCALBASE}/sbin/smartctl:sysutils/smartmontools

USES=		python shebangfix
NO_BUILD=	yes
NO_ARCH=	yes

SHEBANG_FILES=	check_smartmon

PLIST_FILES=	libexec/nagios/check_smartmon

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/nagios
	${INSTALL_SCRIPT} ${WRKSRC}/check_smartmon \
		${STAGEDIR}${PREFIX}/libexec/nagios

.include <bsd.port.mk>
