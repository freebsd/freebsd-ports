PORTNAME=	devmon-templates
DISTVERSION=	20080206
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/devmon/${PORTNAME}/templates/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Device templates for use with devmon
WWW=		https://devmon.sourceforge.net/

RUN_DEPENDS=	devmon>0:net-mgmt/devmon

NO_BUILD=	yes

do-install:
	${INSTALL} -d ${STAGEDIR}${PREFIX}/devmon/templates/
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/devmon/templates/)

.include <bsd.port.mk>
