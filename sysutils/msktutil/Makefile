PORTNAME=	msktutil
DISTVERSION=	1.2.2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/msktutil/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Utility to manage Active Directory interoperability
WWW=		https://github.com/msktutil/msktutil

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	cyrus-sasl-gssapi>0:security/cyrus-sasl2-gssapi

USES=		ldap ssl tar:bz2

GNU_CONFIGURE=	yes

PLIST_FILES=	sbin/msktutil \
		share/man/man1/msktutil.1.gz

CONFIGURE_ARGS=		--with-krb5-config=${KRB5CONFIG} \
			--with-ldapdir=${LOCALBASE} \
			--with-sasldir=${LOCALBASE}
OPTIONS_SINGLE=		GSSAPI
OPTIONS_SINGLE_GSSAPI=	GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT

OPTIONS_DEFAULT=	GSSAPI_BASE

GSSAPI_BASE_USES=		gssapi
.if exists(/usr/libdata/pkgconfig/mit-krb5.pc)
GSSAPI_BASE_CONFIGURE_ON=	--with-krb5=mit
.else
GSSAPI_BASE_CONFIGURE_ON=	--with-krb5=heimdal
.endif

GSSAPI_HEIMDAL_USES=		gssapi:heimdal
GSSAPI_HEIMDAL_CONFIGURE_ON=	--with-krb5=heimdal

GSSAPI_MIT_USES=		gssapi:mit
GSSAPI_MIT_CONFIGURE_ON=	--with-krb5=mit

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/msktutil

.include <bsd.port.mk>
