#
# $Id$
#

PKGNAMEPREFIX=	husky-
#MASTER_SITES=	http://www.physcip.uni-stuttgart.de:8080/fidosoft.husky/
MASTER_SITES?=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	husky
DIST_SUBDIR=	husky

USE_REINPLACE=	yes
USE_GMAKE=	yes
WRKSRC?=	${WRKDIR}/${PORTNAME}

post-patch:
	@${LN} -sf ${LOCALBASE}/etc/fido/huskymak.cfg ${WRKDIR}
