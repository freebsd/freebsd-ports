# New ports collection makefile for:	ratproxy
# Date created:				3 July 2008
# Whom:					Steven Kreuzer <skreuzer@exit2shell.com>
#
# $FreeBSD$
#

PORTNAME=	ratproxy
PORTVERSION=	1.58
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Semi-automated, largely passive web application security audit tool

USE_OPENSSL=	YES
WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_FILES=	bin/ratproxy \
		bin/ratproxy-report.sh

post-patch:
	@${REINPLACE_CMD} -e 's#-Wno-pointer-sign##g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ratproxy ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/ratproxy-report.sh ${PREFIX}/bin

.include <bsd.port.mk>
