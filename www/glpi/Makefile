# Created by: Mathias Monnerville <mathias@monnerville.com>

PORTNAME=	glpi
PORTVERSION=	9.5.5
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	https://github.com/glpi-project/glpi/releases/download/${PORTVERSION}/

MAINTAINER=	mathias@monnerville.com
COMMENT=	Free IT and asset management software

LICENSE=	GPLv2

USES=		cpe gettext php tar:tgz
CPE_VENDOR=	glpi-project
USE_PHP=	bz2 ctype curl exif fileinfo gd iconv intl json mbstring \
		mysqli opcache openssl session simplexml sodium xml xmlrpc zip zlib

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_ARCH=	yes
NO_BUILD=	yes
GLPIDIR?=	www/${PORTNAME}

SUB_FILES=	pkg-message
SUB_LIST=	GLPIDIR=${GLPIDIR} PREFIX=${PREFIX}

OPTIONS_DEFINE=	LDAP IMAP
OPTIONS_DEFAULT=	LDAP IMAP

IMAP_DESC=	IMAP support
LDAP_USE=	PHP=ldap
IMAP_USE=	PHP=imap

post-extract:
	${FIND} ${WRKSRC} \( -name '*~' -o -name '*.orig' -o -name '*.rej' \) -delete

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
