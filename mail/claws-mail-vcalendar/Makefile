PORTNAME=	vcalendar

COMMENT=	vCalendar plugin for Claws Mail
WWW=		https://www.claws-mail.org/plugin.php?plugin=vcalendar

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libical.so:devel/libical

USES=		cpe
CPE_VENDOR=	claws-mail

CLAWS_PLUGINS_BUILD=	${PORTNAME}

.include "../claws-mail/Makefile.claws"
.include <bsd.port.mk>
