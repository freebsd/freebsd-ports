PORTNAME=	turba
PORTVERSION=	4.2.29
CATEGORIES=	mail www pear
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}horde-

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde web based address book
WWW=		https://www.horde.org/apps/turba/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

IGNORE_WITH_PHP=80 81 82

USES=		horde php cpe
USE_HORDE_BUILD=	Horde_Role
USE_HORDE_RUN=	Horde_Role \
		horde \
		content \
		Horde_Auth \
		Horde_Core \
		Horde_Data \
		Horde_Date \
		Horde_Exception \
		Horde_Form \
		Horde_Group \
		Horde_History \
		Horde_Icalendar \
		Horde_Mail \
		Horde_Mime \
		Horde_Nls \
		Horde_Perms \
		Horde_Prefs \
		Horde_Serialize \
		Horde_Share \
		Horde_Support \
		Horde_Url \
		Horde_Util \
		Horde_View
USE_PHP=	gettext hash json

NO_ARCH=	yes

OPTIONS_DEFINE=	FACEBOOK IMSP LDAP

FACEBOOK_DESC=	Support connections with Facebook
IMSP_DESC=	Support IMSP addressbooks
LDAP_DESC=	Support LDAP Addressbooks

FACEBOOK_USE=	HORDE_RUN=Horde_Service_Facebook
IMSP_USE=	HORDE_RUN=Horde_Imsp
LDAP_USE=	HORDE_RUN=Horde_Ldap

.include <bsd.port.mk>
