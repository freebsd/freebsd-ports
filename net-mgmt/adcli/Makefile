# Created by: Mikhail T. <mi@aldan.algebra.com>
# $FreeBSD$

PORTNAME=	adcli
PORTVERSION=	0.8.1
CATEGORIES=	net-mgmt net security
MASTER_SITES=	https://www.freedesktop.org/software/realmd/releases/

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Tool for performing actions on an Active Directory domain

LICENSE=	LGPL21

LIB_DEPENDS=	libldap.so:net/openldap24-sasl-client
BUILD_DEPENDS=	xsltproc:textproc/libxslt	\
		docbook-xml>0:textproc/docbook-xml	\
		docbook-xsl>0:textproc/docbook-xsl

PLIST_FILES=	sbin/adcli man/man8/adcli.8.gz
GNU_CONFIGURE=	yes
TEST_TARGET=	check

OPTIONS_SINGLE=		GSSAPI
OPTIONS_SINGLE_GSSAPI=	GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT
OPTIONS_DEFAULT=	GSSAPI_BASE

CONFIGURE_ENV+=	ac_cv_path_KRB5_CONFIG=${KRB5CONFIG}	\
		ac_cv_path_XMLTO=${TRUE}
CONFIGURE_ARGS+=--disable-silent-rules --sysconfdir=/etc

# Kerberos may or may not be there, but LDAP always is:
CFLAGS+=	-I${LOCALBASE}/include -DLDAP_DEPRECATED=0
LDFLAGS+=	-L${LOCALBASE}/lib

GSSAPI_BASE_USES=	gssapi
GSSAPI_MIT_USES=	gssapi:mit,flags
GSSAPI_HEIMDAL_USES=	gssapi:heimdal,flags

GSSAPI_BASE_CONFIGURE_ARGS=	--sysconfdir=/etc
GSSAPI_BASE_CONFIGURE_ENV=	KRB5_CFLAGS="-I${GSSAPIINCDIR}"	\
				KRB5_LIBS="${GSSAPILIBS}"
GSSAPI_HEIMDAL_CONFIGURE_ARGS=	--sysconfdir=${LOCALBASE}/etc
GSSAPI_HEIMDAL_CONFIGURE_ENV=	KRB5_CFLAGS="-I${GSSAPIINCDIR}/heimdal" \
				KRB5_LIBS="${GSSAPILDFLAGS} ${GSSAPILIBS}"
GSSAPI_MIT_CONFIGURE_ARGS=	--sysconfdir=${LOCALBASE}/etc
GSSAPI_MIT_CONFIGURE_ENV=	KRB5_CFLAGS="-I${GSSAPIINCDIR}/gssapi" \
				KRB5_LIBS="${GSSAPILDFLAGS} ${GSSAPILIBS} -lk5crypto"
# Quiets down warnings inside MIT's headers:
GSSAPI_BASE_CFLAGS+=	-DHEIMDAL
GSSAPI_HEIMDAL_CFLAGS+=	-DHEIMDAL
GSSAPI_MIT_CFLAGS+=	-DTARGET_OS_MAC=0

.include <bsd.port.mk>
