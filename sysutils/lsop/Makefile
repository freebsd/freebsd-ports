# $FreeBSD$

PORTNAME=	lsop
PORTVERSION=	0.2
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	606u@dir.bg
COMMENT=	List all processes running with outdated binaries or shared libraries

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	606u

PLIST_FILES=	sbin/lsop \
		libexec/nagios/check_restart

post-patch:
	@${REINPLACE_CMD} -e 's|lsop|${PREFIX}/sbin/lsop|' ${WRKSRC}/check_restart

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lsop ${STAGEDIR}${PREFIX}/sbin
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/nagios
	${INSTALL_SCRIPT} ${WRKSRC}/check_restart ${STAGEDIR}${PREFIX}/libexec/nagios

.include <bsd.port.mk>
