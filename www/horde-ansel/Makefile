PORTNAME=	ansel
PORTVERSION=	3.0.10
CATEGORIES=	www pear graphics
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}horde-

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde Photo Management and Web Gallery

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		horde cpe php
USE_PHP=	gettext hash
USE_HORDE_BUILD=	Horde_Role
USE_HORDE_RUN=	Horde_Role \
		horde \
		content \
		Horde_Auth \
		Horde_Autoloader \
		Horde_Core \
		Horde_Date \
		Horde_Db \
		Horde_Exception \
		Horde_Form \
		Horde_Group \
		Horde_Image \
		Horde_Mime \
		Horde_Nls \
		Horde_Perms \
		Horde_Prefs \
		Horde_Serialize \
		Horde_Share \
		Horde_Support \
		Horde_Text_Filter \
		Horde_Url \
		Horde_Util \
		Horde_View \
		Horde_Vfs

CONFLICTS_INSTALL=	php*-horde-ansel # bin/AnselPublish.scpt bin/ansel bin/ansel-convert-sql-shares-to-sqlng bin/ansel-exif-to-tags bin/ansel-garbage-collection

.include <bsd.port.mk>
