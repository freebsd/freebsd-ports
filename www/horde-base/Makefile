# $FreeBSD$

PORTNAME=	horde
PORTVERSION=	5.1.5
CATEGORIES=	www pear
PKGNAMEPREFIX=

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde Application Framework

RUN_DEPENDS=	${PEARDIR}/Net/DNS2.php:${PORTSDIR}/dns/pear-Net_DNS2

OPTIONS_DEFAULT=	ICONV
OPTIONS_DEFINE=	FACEBOOK ICONV TWITTER WEATHER

FACEBOOK_DESC=	Support connections to Facebook
ICONV_DESC=	Depend on PHP iconv extension
TWITTER_DESC=	Support connections to Twitter
WEATHER_DESC=	Support weather forecast display

USE_PHP=	filter gettext hash

USE_HORDE_BUILD=	Horde_Role
USE_HORDE_RUN=	Horde_Role \
		Horde_Alarm \
		Horde_Argv \
		Horde_Auth \
		Horde_Autoloader \
		Horde_Browser \
		Horde_Core \
		Horde_Date \
		Horde_Exception \
		Horde_Form \
		Horde_Group \
		Horde_Http \
		Horde_Image \
		Horde_LoginTasks \
		Horde_Mail \
		Horde_Mime \
		Horde_Nls \
		Horde_Perms \
		Horde_Prefs \
		Horde_Rpc \
		Horde_Serialize \
		Horde_Support \
		Horde_Template \
		Horde_Text_Diff \
		Horde_Token \
		Horde_Text_Filter \
		Horde_Tree \
		Horde_Url \
		Horde_Util \
		Horde_View \
		Horde_Vfs

# Optional in package but we want them in
USE_HORDE_RUN+=	Horde_Feed

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if defined(WITH_FACEBOOK)
USE_HORDE_RUN+=	Horde_Service_Facebook
.endif

.if !defined(WITHOUT_ICONV)
USE_PHP+=	iconv
.endif

.if defined(WITH_TWITTER)
USE_HORDE_RUN+=	Horde_Service_Twitter
.endif

.if defined(WITH_WEATHER)
USE_HORDE_RUN+=	Horde_Service_Weather
.endif

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-channel-horde/bsd.horde.mk"
.include <bsd.port.post.mk>
