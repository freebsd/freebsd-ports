PORTNAME=	Horde_Mime_Viewer
PORTVERSION=	2.2.4
CATEGORIES=	mail www pear

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde MIME Viewer Library
WWW=		https://pear.horde.org

LICENSE=	LGPL21

USES=		horde php cpe
USE_HORDE_BUILD=	Horde_Role
USE_HORDE_RUN=	Horde_Role \
		Horde_Browser \
		Horde_Compress \
		Horde_Exception \
		Horde_Mime \
		Horde_Text_Filter \
		Horde_Text_Flowed \
		Horde_Util \
		Horde_Translation
USE_PHP=	xml

CONFLICTS=	horde-3*

NO_ARCH=	yes

.include <bsd.port.mk>
