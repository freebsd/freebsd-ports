# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	regripperplugins
PORTVERSION=	20130429
CATEGORIES=	security
MASTER_SITES=	GOOGLE_CODE
PROJECTHOST=	regripper
DISTNAME=	plugins${PORTVERSION}
EXTRACT_SUFX=	.zip

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Supplemental plugins for Harlan Carvey's RegRipper

LICENSE=	GPLv3

RUN_DEPENDS=	regripper>=0:${PORTSDIR}/security/regripper

NO_WRKSUBDIR=	yes
USE_DOS2UNIX=	yes
NO_BUILD=	yes
PORTDATA=	*

do-install:
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/* ${DATADIR}

.include <bsd.port.mk>
