# Ports collection makefile for:  turba
# Date created:			  Sat Nov 16, 2001
# Whom:				  Thierry Thomas (<thierry@thomas.as>)
#
# $FreeBSD$
#

PORTNAME=	turba
PORTVERSION=	3.0.15
PKGNAMEPREFIX=	horde-
CATEGORIES=	mail www pear

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde web based address book

LICENSE=	AL2
LICENSE_FILE=	${WRKSRC}/LICENSE

LATEST_LINK=	horde4-${PORTNAME}

OPTIONS=	FACEBOOK "Support connections with Facebook" Off \
		IMSP "Support IMSP addressbooks" Off \
		LDAP "Support LDAP Addressbooks" Off

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

.include <bsd.port.pre.mk>

.if defined(WITH_FACEBOOK)
USE_HORDE_RUN+=	Horde_Service_Facebook
.endif

.if defined(WITH_IMSP)
USE_HORDE_RUN+=	Horde_Imsp
.endif

.if defined(WITH_LDAP)
USE_HORDE_RUN+=	Horde_Ldap
.endif

.include "${PORTSDIR}/devel/pear-channel-horde/bsd.horde.mk"
.include <bsd.port.post.mk>
