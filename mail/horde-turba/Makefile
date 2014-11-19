# $FreeBSD$

PORTNAME=	turba
PORTVERSION=	4.2.3
PKGNAMEPREFIX=	horde-
CATEGORIES=	mail www pear

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde web based address book

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

OPTIONS_DEFINE=	FACEBOOK IMSP LDAP
FACEBOOK_DESC=	Support connections with Facebook
IMSP_DSC=	Support IMSP addressbooks
LDAP_DESC=	Support LDAP Addressbooks

USES=	horde
USE_PHP=	gettext hash json
USE_HORDE_BUILD=	Horde_Role
USE_HORDE_RUN=	Horde_Role \
		horde \
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

FACEBOOK_USE=	HORDE_RUN=Horde_Service_Facebook
IMSP_USE=	HORDE_RUN=Horde_Imsp
LDAP_USE=	HORDE_RUN=Horde_Ldap

.include <bsd.port.mk>
