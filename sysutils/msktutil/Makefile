# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	msktutil
PORTVERSION=	1.1
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Utility to manage Active Directory interoperability

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libudns.so:dns/udns
RUN_DEPENDS=	cyrus-sasl-gssapi>0:security/cyrus-sasl2-gssapi

USES=		autoreconf ssl
USE_GITHUB=	yes
USE_OPENLDAP=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-sasldir=${LOCALBASE} --with-ldapdir=${LOCALBASE}
WANT_OPENLDAP_SASL=	yes

OPTIONS_SINGLE=	GSSAPI
OPTIONS_SINGLE_GSSAPI=	GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT

OPTIONS_DEFAULT=GSSAPI_BASE

GSSAPI_BASE_USES=	gssapi
GSSAPI_HEIMDAL_USES=	gssapi:heimdal
GSSAPI_MIT_USES=	gssapi:mit

GSSAPI_BASE_CONFIGURE_ON=	--with-krb5=heimdal
GSSAPI_HEIMDAL_CONFIGURE_ON=	--with-krb5=heimdal
GSSAPI_MIT_CONFIGURE_ON=	--with-krb5=mit
CONFIGURE_ARGS+=		--with-krb5-config=${KRB5CONFIG}

PLIST_FILES=	man/man1/msktutil.1.gz sbin/msktutil

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/msktutil

.include <bsd.port.mk>
