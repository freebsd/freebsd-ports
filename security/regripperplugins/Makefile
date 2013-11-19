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
NO_BUILD=	yes
USES=		dos2unix

PORTDATA=	*.pl all ntuser sam security software system usrclass

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${PORTDATA:S,^,${WRKSRC}/,} ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
