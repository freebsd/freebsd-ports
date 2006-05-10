# New ports collection makefile for:	sylpheed-claws-vcalendar
# Date created:	3 April 2006
# Whom:	Pawel Pekala <c0rn@o2.pl>
#
# $FreeBSD$
#

PORTNAME=	vcalendar
PORTVERSION=	1.78
CATEGORIES=	mail
MASTER_SITES=	http://claws.sylpheed.org/downloads/plugins/
PKGNAMEPREFIX=	sylpheed-claws-

MAINTAINER=	c0rn@o2.pl
COMMENT=	vCalendar plugin for sylpheed-claws

LIB_DEPENDS=	curl.3:${PORTSDIR}/ftp/curl
BUILD_DEPENDS=	sylpheed-claws>=2.1:${PORTSDIR}/mail/sylpheed-claws
RUN_DEPENDS=	sylpheed-claws>=2.1:${PORTSDIR}/mail/sylpheed-claws

USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_ICONV=	yes
USE_X_PREFIX=	yes
USE_AUTOTOOLS=	autoconf:259

CONFIGURE_ARGS=	--with-libiconv-prefix=${LOCALBASE} \
	--with-libintl-prefix=${LOCALBASE}

pre-configure:
	@cd ${WRKDIR}/${PORTNAME}-${PORTVERSION} && ${AUTOHEADER}

.include <bsd.port.mk>
