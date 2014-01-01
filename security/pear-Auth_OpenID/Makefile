# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Auth_OpenID
PORTVERSION=	2.1.3
CATEGORIES=	security www pear
MASTER_SITES=	http://openidenabled.com/files/php-openid/packages/
DISTNAME=	php-openid-${PORTVERSION}

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PHP OpenID library v2 for PEAR

RUN_DEPENDS=	pear:${PORTSDIR}/devel/pear
BUILD_DEPENDS:=	${RUN_DEPENDS}

CONFLICTS=	php-Auth_OpenID-1.*

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

USE_BZIP2=	yes
LATEST_LINK=	pear-Auth_OpenID

WRKSRC=		${WRKDIR}/php-openid-${PORTVERSION}

OPTIONS_DEFINE=	BCMATH PEAR_DB
BCMATH_DESC=	Use bcmath instead of libgmp
PEAR_DB_DESC=	Support SQL stores

USE_PHP=	curl dom
USE_PYTHON_BUILD=	yes
PEAR_AUTOINSTALL=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
EXTRACT_SUFX=	.tar.bz2

.if ${PORT_OPTIONS:MBCMATH}
USE_PHP+=	bcmath
.else
USE_PHP+=	gmp
.endif

.if ${PORT_OPTIONS:MPEAR_DB}
BUILD_DEPENDS+=	${PEARDIR}/DB.php:${PORTSDIR}/databases/pear-DB
RUN_DEPENDS+=	${PEARDIR}/DB.php:${PORTSDIR}/databases/pear-DB
.endif

post-configure:
	@cd ${WRKSRC}/admin && ${PYTHON_CMD} packagexml.py ${PORTVERSION} package2.xml ../CHANGELOG > ${WRKDIR}/package.xml

.include <bsd.port.post.mk>
