PORTNAME=	glpi
PORTVERSION=	10.0.16
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	https://github.com/glpi-project/glpi/releases/download/${PORTVERSION}/

MAINTAINER=	mathias@monnerville.com
COMMENT=	Free IT and asset management software
WWW=		https://glpi-project.org/

LICENSE=	GPLv2

USES=		cpe gettext php tar:tgz
CPE_VENDOR=	glpi-project
USE_PHP=	bz2 ctype curl dom exif fileinfo filter gd iconv intl json \
		mbstring mysqli opcache session simplexml sodium xml xmlreader \
		xmlrpc xmlwriter zip zlib

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message
SUB_LIST=	GLPIDIR=${GLPIDIR} PREFIX=${PREFIX}
GLPIDIR?=	www/${PORTNAME}

WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	LDAP IMAP
OPTIONS_DEFAULT=	LDAP IMAP

IMAP_DESC=	IMAP support
IMAP_USE=	PHP=imap
LDAP_USE=	PHP=ldap

post-extract:
	${FIND} ${WRKSRC} \( -name '*~' -o -name '*.orig' -o -name '*.rej' \) -delete

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
