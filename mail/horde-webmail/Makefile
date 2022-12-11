PORTNAME=	webmail
PORTVERSION=	5.2.22
CATEGORIES=	mail www pear
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}horde-

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde Groupware Webmail Edition
WWW=		https://www.horde.org/apps/webmail/

IGNORE_WITH_PHP=80 81 82

USES=		horde cpe php
CPE_PRODUCT=	groupware
CPE_EDITION=	webmail
USE_HORDE_BUILD=	Horde_Role
USE_HORDE_RUN=	Horde_Role \
		content \
		gollem \
		horde \
		imp \
		ingo \
		kronolith \
		mnemo \
		nag \
		timeobjects \
		trean \
		turba

CONFLICTS=	horde-groupware-[456]*

.include <bsd.port.mk>
