# Created by: wollman
# $FreeBSD$

PORTNAME=	mod_auth_kerb
PORTVERSION=	5.4
PORTREVISION=	5
CATEGORIES=	www
MASTER_SITES=	SF/modauthkerb/${PORTNAME}/${PORTNAME}-${PORTVERSION}
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}
PKGNAMESUFFIX=	2

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache module for authenticating users with Kerberos v5

USE_APACHE=	22
USES=		gmake
GNU_CONFIGURE=	yes

PORTSCOUT=	limit:^5.4

.if defined(KRB5_HOME)
BUILD_DEPENDS+=		${KRB5_HOME}/lib/libgssapi_krb5.so:${PORTSDIR}/security/krb5
RUN_DEPENDS+=		${KRB5_HOME}/lib/libgssapi_krb5.so:${PORTSDIR}/security/krb5
CONFIGURE_ARGS+=	--with-krb5=${KRB5_HOME} --without-krb4

.elif defined(HEIMDAL_HOME)
BUILD_DEPENDS+=		${HEIMDAL_HOME}/lib/libgssapi.so:${PORTSDIR}/security/heimdal
RUN_DEPENDS+=		${HEIMDAL_HOME}/lib/libgssapi.so:${PORTSDIR}/security/heimdal
CONFIGURE_ARGS+=	--with-krb5=${HEIMDAL_HOME} --without-krb4

.elif exists(${DESTDIR}/usr/lib/libkrb5.a) && exists(${DESTDIR}/usr/bin/krb5-config)
CONFIGURE_ARGS+=	--with-krb5=${DESTDIR}/usr --without-krb4

.else
LIB_DEPENDS+=		libgssapi_krb5.so:${PORTSDIR}/security/krb5
CONFIGURE_ARGS+=	--with-krb5=${LOCALBASE} --without-krb4
.endif

post-patch:
	${REINPLACE_CMD} -e 's|@APXS_STAGE@|-S LIBEXECDIR=${STAGEDIR}${PREFIX}/${APACHEMODDIR}|' \
		${WRKSRC}/Makefile.in

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}

.include <bsd.port.mk>
