PORTNAME=	mod_lookup_identity
DISTVERSIONPREFIX=	mod_lookup_identity-
DISTVERSION=	1.0.0
CATEGORIES=	www
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Apache module for retrieving user identity information from SSSD
WWW=		https://github.com/adelton/mod_lookup_identity

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libdbus-1.so:devel/dbus

USES=		apache pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	adelton

CFLAGS+=	-Wall -pedantic -std=c99

AP_FAST_BUILD=	yes
AP_EXTRAS=	$$(${LOCALBASE}/bin/pkgconf --cflags dbus-1) \
		$$(${LOCALBASE}/bin/pkgconf --libs dbus-1) \
		-Wc,"${CFLAGS}"

APMOD_FILE=	240_${PORTNAME}.conf.sample
SUB_FILES=	${APMOD_FILE}

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEETCDIR}/modules.d
	${INSTALL_DATA} ${WRKDIR}/${APMOD_FILE} \
		${STAGEDIR}${PREFIX}/${APACHEETCDIR}/modules.d

.include <bsd.port.mk>
