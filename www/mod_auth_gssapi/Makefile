# $FreeBSD$

PORTNAME=	mod_auth_gssapi
PORTVERSION=	1.4.1
DISTVERSIONPREFIX=	v
CATEGORIES=	www
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	chris@chrullrich.net
COMMENT=	Apache module for authenticating users with GSSAPI

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	modauthgssapi

USE_APACHE=	24+
USES=		autoreconf libtool ssl gssapi:mit,flags
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	KRB5_CONFIG=${KRB5CONFIG}
CONFIGURE_ARGS+=	OPENSSL_CFLAGS=-I${OPENSSLINC}
CONFIGURE_ARGS+=	OPENSSL_LIBS=-lcrypto

PLIST_FILES=	@sample\ %%APACHEETCDIR%%/modules.d/%%APMOD_FILE%% \
		%%APACHEMODDIR%%/mod_auth_gssapi.so

SUB_FILES=	${APMOD_FILE}
APMOD_FILE=	240_${PORTNAME}.conf.sample
PLIST_SUB+=	APMOD_FILE=${APMOD_FILE}

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT:Mlibressl*}
IGNORE=		mod_auth_gssapi currently only supports OpenSSL
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}
	${APXS} -S LIBEXECDIR=${STAGEDIR}${PREFIX}/${APACHEMODDIR} \
		-i -n ${MODULENAME} ${WRKSRC}/src/${MODULENAME}.la
	@${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEETCDIR}/modules.d
	${INSTALL_DATA} ${WRKDIR}/${APMOD_FILE} ${STAGEDIR}${PREFIX}/${APACHEETCDIR}/modules.d
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}/${MODULENAME}.so

.include <bsd.port.post.mk>
