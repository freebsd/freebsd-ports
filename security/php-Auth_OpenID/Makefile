# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Auth_OpenID
PORTVERSION=	1.2.3
CATEGORIES=	security www pear
MASTER_SITES=	http://openidenabled.com/files/php-openid/packages/
PKGNAMEPREFIX=	php-
DISTNAME=	php-openid-${PORTVERSION}

MAINTAINER=	gslin@gslin.org
COMMENT=	PHP OpenID library

RUN_DEPENDS=	pear:${PORTSDIR}/devel/pear
BUILD_DEPENDS:=	${RUN_DEPENDS}

CONFLICTS=	pear-Auth_OpenID-2.*

USE_BZIP2=	yes
NO_BUILD=	yes
OPTIONS_DEFINE=	BCMATH MYSQL PGSQL SQLITE
BCMATH_DESC=	Use bcmath instead of libgmp

USE_PHP=	curl dom

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MBCMATH}
USE_PHP+=	bcmath
.else
USE_PHP+=	gmp
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_PHP+=	mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PHP+=	pgsql
.endif

.if ${PORT_OPTIONS:MSQLITE}
USE_PHP+=	sqlite
.endif

do-install:
	${MKDIR} ${PREFIX}/share/pear/Auth/OpenID
	${CP} ${WRKSRC}/Auth/OpenID.php ${PREFIX}/share/pear/Auth
	${CP} ${WRKSRC}/Auth/OpenID/* ${PREFIX}/share/pear/Auth/OpenID
	${MKDIR} ${PREFIX}/share/pear/Services/Yadis
	${CP} ${WRKSRC}/Services/Yadis/* ${PREFIX}/share/pear/Services/Yadis
	${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/ ${EXAMPLESDIR}

.include <bsd.port.post.mk>
