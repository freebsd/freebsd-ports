#
# $Id$
#

PKGNAMEPREFIX=	husky-
#MASTER_SITES=	http://www.physcip.uni-stuttgart.de:8080/fidosoft.husky/
MASTER_SITES?=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	husky
DIST_SUBDIR=	husky

WRKSRC?=	${WRKDIR}/${PORTNAME}

.if ${PORTNAME} != "base"
BUILD_DEPENDS=	${LOCALBASE}/etc/fido/huskymak.cfg:${PORTSDIR}/news/husky-base

USE_GMAKE=	yes

pre-build:
	@${LN} -sf ${LOCALBASE}/etc/fido/huskymak.cfg ${WRKDIR}
.endif
