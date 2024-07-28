PORTNAME=	phpipam
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.0
CATEGORIES=	net-mgmt
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${DISTVERSIONFULL}/

MAINTAINER=	jake@xz.cx
COMMENT=	PHP IP Address Management IPv4/IPv6
WWW=		https://phpipam.net/

LICENSE=	GPLv3

RUN_DEPENDS=	${LOCALBASE}/share/pear/System.php:devel/pear@${PHP_FLAVOR}

USES=		cpe gettext php:web tar:tgz
USE_PHP=	ctype curl dom filter gd gettext gmp iconv mbstring mcrypt \
		pcntl pdo pdo_mysql posix session simplexml sockets
IGNORE_WITH_PHP=	84

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message
SUB_LIST=	DISTNAME=${DISTNAME}

WRKSRC=	${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	LDAP

LDAP_USE=	PHP=ldap

do-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR} \
		"! -name *.orig")

.include <bsd.port.mk>
