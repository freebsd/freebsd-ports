# New ports collection makefile for:  wmmail
# Date created:        7 Jun 1998
# Whom:                rom
#
# $FreeBSD$
#

PORTNAME=	wmmail
PORTVERSION= 	0.63a
CATEGORIES=	mail windowmaker
MASTER_SITES=	http://www.eecg.utoronto.ca/~chanb/
DISTNAME=	WMMail.app-${PORTVERSION}

MAINTAINER=	jim@FreeBSD.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		PropList.2:${PORTSDIR}/devel/libPropList

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-PL-libs="-L${LOCALBASE}/lib" \
		--with-PL-incs="-I${LOCALBASE}/include"
WRKSRC=	${WRKDIR}/WMMail.app-0.63a
USE_X_PREFIX=	yes

post-install:
	@${ECHO} "		"
	@${ECHO} "------------------------------------------------------------------------------"
	@${ECHO} "===> Installing WMMail defaults in ${PREFIX}/GNUstep/Apps/WMMail.app/Defaults"
	@${ECHO} "===> Modify to your config and copy to ~/GNUstep/Defaults/WMMail"
	@${ECHO} "		"
	@${ECHO} "===> Installing README in ${PREFIX}/GNUstep/Apps/WMMail.app"
	@${ECHO} "------------------------------------------------------------------------------"
	@${ECHO} "		"
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/GNUstep/Apps/WMMail.app

.include <bsd.port.mk>
