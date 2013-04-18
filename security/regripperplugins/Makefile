# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	regripperplugins
PORTVERSION=	20130404
CATEGORIES=	security
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	plugins${PORTVERSION}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Supplemental plugins for Harlan Carvey's RegRipper

LICENSE=	GPLv3

RUN_DEPENDS=	regripper>=0:${PORTSDIR}/security/regripper

USE_ZIP=	yes
WRKSRC=		${WRKDIR}/plugins
USE_DOS2UNIX=	yes
NO_BUILD=	yes
PROJECTHOST=	regripper
PORTDATA=	*

do-install:
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/* ${DATADIR}

.include <bsd.port.mk>
