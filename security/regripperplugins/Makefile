# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	regripperplugins
PORTVERSION=	20140414
CATEGORIES=	security
# Downloaded from https://www.dropbox.com/s/6a37htpkf3iq7eg/rr_20140414.zip
MASTER_SITES=	LOCAL/antoine
DISTNAME=	rr_${PORTVERSION}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Supplemental plugins for Harlan Carvey's RegRipper

LICENSE=	GPLv3

RUN_DEPENDS=	regripper>=0:${PORTSDIR}/security/regripper

USES=		dos2unix zip
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/regripper

PORTDATA=	*.pl all amcache.txt ntuser sam security software system usrclass

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${PORTDATA:S,^,${WRKSRC}/plugins/,} ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
