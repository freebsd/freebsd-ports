# New ports collection makefile for:  wmmail
# Version required:    0.62
# Date created:        7 Jun 1998
# Whom:                rom
#
# $Id: Makefile,v 1.7 1999/01/18 06:43:00 asami Exp $
#

DISTNAME=	WMMail.app-0.62
PKGNAME=	wmmail-0.62
CATEGORIES=	mail windowmaker
MASTER_SITES=	http://www.eecg.utoronto.ca/~chanb/

MAINTAINER=	jim@phrantic.phear.net

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		PropList.1:${PORTSDIR}/devel/libPropList

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-PL-libs="-L${LOCALBASE}/lib" \
		--with-PL-incs="-I${LOCALBASE}/include"
WRKSRC=	${WRKDIR}/WMMail.app-0.62
USE_X_PREFIX=	yes

post-install:
	@${ECHO} "		"
	@${ECHO} "---------------------------------------------------------------------"
	@${ECHO} "===>	Installing WMMail.defaults in ${PREFIX}/share/doc/WMMail"
	@${ECHO} "===>	Modify to your config and copy to ~/GNUstep/Defaults/WMMail"
	@${ECHO} "---------------------------------------------------------------------"
	@${ECHO} "		"
	@${MKDIR} ${PREFIX}/share/doc/WMMail && chmod a+rx ${PREFIX}/share/doc/WMMail
	${INSTALL_DATA} ${WRKSRC}/WMMail.defaults ${PREFIX}/share/doc/WMMail

.include <bsd.port.mk>
