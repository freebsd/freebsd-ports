PORTNAME=	adcli
PORTVERSION=	0.9.2
PORTREVISION=	3
CATEGORIES=	net-mgmt net security

MAINTAINER=	ports@virtual-estates.net
COMMENT=	Tool for performing actions on an Active Directory domain
WWW=		https://www.freedesktop.org/software/realmd/adcli/adcli.html

LICENSE=	LGPL21

BUILD_DEPENDS=	xsltproc:textproc/libxslt	\
		docbook-xml>0:textproc/docbook-xml	\
		docbook-xsl>0:textproc/docbook-xsl

USES=		autoreconf gssapi:mit,flags iconv ldap libtool localbase tar:bz2

USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	realmd

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	${GSSAPI_CONFIGURE_ARGS}
# xsltproc and docbook are needed to create the man-page. xmlto is only
# required for generating HTML-documents, which are optional.
CONFIGURE_ENV+=	ac_cv_path_KRB5_CONFIG=${KRB5CONFIG}	\
	ac_cv_path_XMLTO=${PORT_OPTIONS:MDOCS:S|DOCS|${LOCALBASE}/bin/xmlto|:S|^$|${TRUE}|}
TEST_TARGET=	check

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	xmlto:textproc/xmlto

post-build:
	${RM} ${WRKSRC}/doc/html/adcli-docs.proc	# An empty file...

.include <bsd.port.mk>
