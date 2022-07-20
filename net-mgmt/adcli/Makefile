PORTNAME=	adcli
PORTVERSION=	0.9.1
CATEGORIES=	net-mgmt net security
MASTER_SITES=	https://gitlab.freedesktop.org/sbose/adcli//uploads/30880d967e79cee789194435e70fbf30/

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Tool for performing actions on an Active Directory domain

LICENSE=	LGPL21

USE_OPENLDAP=	yes
BUILD_DEPENDS=	xsltproc:textproc/libxslt	\
		docbook-xml>0:textproc/docbook-xml	\
		docbook-xsl>0:textproc/docbook-xsl

GNU_CONFIGURE=	yes
TEST_TARGET=	check

OPTIONS_DEFINE=	DOCS
OPTIONS_SINGLE=		GSSAPI
OPTIONS_SINGLE_GSSAPI=	GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT
OPTIONS_DEFAULT=	GSSAPI_BASE

# xsltproc and docbook are needed to create the man-page. xmlto is only
# required for generating HTML-documents, which are optional.
CONFIGURE_ENV+=	ac_cv_path_KRB5_CONFIG=${KRB5CONFIG}	\
	ac_cv_path_XMLTO=${PORT_OPTIONS:MDOCS:S|DOCS|${LOCALBASE}/bin/xmlto|:S|^$|${TRUE}|}
CONFIGURE_ARGS=	--sysconfdir=/etc

USES=	autoreconf libtool

# Kerberos may or may not be there, but LDAP always is:
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

DOCS_BUILD_DEPENDS=	xmlto:textproc/xmlto
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

GSSAPI_BASE_CFLAGS+=	-DHEIMDAL
GSSAPI_HEIMDAL_CFLAGS+=	-DHEIMDAL
# Quiets down warnings inside MIT's headers:
GSSAPI_MIT_CFLAGS+=	-DTARGET_OS_MAC=0

post-build:
	${RM} ${WRKSRC}/doc/html/adcli-docs.proc	# An empty file...

.include <bsd.port.mk>
