# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	aws
PORTVERSION=	17.0.1
CATEGORIES=	www

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Adacore Ada Web Server and framework

LICENSE=	GPLv3 GPLv3RLE
LICENSE_COMB=	multi

BUILD_DEPENDS=	gprbuild:devel/gprbuild \
		xmlada>=4.4:textproc/xmlada \
		asis>=2013:lang/asis \
		gnatpython>=20101207:devel/gnatpython
RUN_DEPENDS=	xmlada>=4.4:textproc/xmlada

USES=		ada:run gmake python shebangfix tar:bzip2
USE_GITHUB=	yes
GH_ACCOUNT=	AdaCore
GH_TAGNAME=	17.0
GH_TUPLE=	AdaCore:templates-parser:17.0:tp/templates_parser

GNU_CONFIGURE=	yes
NO_MTREE=	yes
DOTBUILD=	release
LINK_SSL=	--
LINK_TLS=	--
LINK_LDP=	--
NAME_IP6=	--
NAME_STD=	--
BUILD_TYPE=	release
ADDL_RPATH=	${LOCALBASE}/lib:${LOCALBASE}/lib/aws/native/relocatable
SHEBANG_FILES=	tools/awsascb

OPTIONS_SINGLE=		Secure-Socket-Layer
OPTIONS_DEFINE=		IP6 DEBUG LDAP SHARED DOCS
OPTIONS_DEFAULT=	SSL SHARED
OPTIONS_SUB=		yes
NO_OPTIONS_SORT=	yes
DOCS_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx
OPTIONS_SINGLE_Secure-Socket-Layer= SSL GNUTLS

SHARED_DESC=		Build shared libraries in addition to static ones
IP6_DESC=		Support IPv6 instead of IPv4

SSL_USES=		ssl
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
LDAP_USE=		OPENLDAP=yes

CONF_ARGS=	PROCESSORS=${MAKE_JOBS_NUMBER}
CONF_ARGS+=	GCC=ada
CONF_ARGS+=	PYTHON=python${PYTHON_VER}
CONF_ARGS+=	XMLADA=true
CONF_ARGS+=	PRJ_BUILD=${DOTBUILD}
CONF_ARGS+=	prefix=${PREFIX}
CONF_ARGS+=	ZPATH=/usr/lib
CONF_ARGS+=	ZLIB=true
CONF_ARGS+=	ASIS=true
CONF_ARGS+=	DEFAULT_LIBRARY_TYPE=static

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT} == base
IGNORE_FreeBSD_9=	Requires newer OpenSSL (set DEFAULT_VERSIONS+=ssl=openssl)
.endif

###################
##  SSL Support  ##
###################

.if ${PORT_OPTIONS:MSSL}
CONF_ARGS+=	SOCKET=openssl
CONF_ARGS+=	LPATH=${OPENSSLLIB}
LINK_SSL=
.else	
# it's not SSL so it must be GNUTLS
CONF_ARGS+=	LPATH=${PREFIX}/lib
CONF_ARGS+=	SOCKET=gnutls
LINK_TLS=
.endif

####################
##  LDAP Support  ##
####################

.if ${PORT_OPTIONS:MLDAP}
CONF_ARGS+=	LDAP=true
LINK_LDP=
.endif

####################
##  IPv6 Support  ##
####################

.if ${PORT_OPTIONS:MIP6}
CONF_ARGS+=	IPv6=true
NAME_IP4=	--
NAME_IP6=
.endif

#####################
##  Debug Support  ##
#####################

.if ${PORT_OPTIONS:MDEBUG}
CONF_ARGS+=	DEBUG=true
BUILD_TYPE=	debug
.endif

##############################
##  Shared Runtime Library  ##
##############################

.if ${PORT_OPTIONS:MSHARED}
CONF_ARGS+=	ENABLE_SHARED=true
.else
CONF_ARGS+=	ENABLE_SHARED=false
.endif

post-patch:
	@${REINPLACE_CMD} \
	    -e 's|@ADDITIONAL_RPATH@|${ADDL_RPATH}|' \
	    -e 's|@PREFIX@|${LOCALBASE}|g' \
		${WRKSRC}/aws.gpr \
		${WRKSRC}/src/src.gpr \
		${WRKSRC}/include/include.gpr
	@${REINPLACE_CMD} -e 's|latexpdf||' ${WRKSRC}/Makefile

do-configure:
	(cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${MAKE_CMD} setup ${CONF_ARGS})

do-build:
#	We cannot use a redefined ALL_TARGET because MAKE_JOBS_SAFE is set
#	for PROCESSORS, but that also sets -j for gmake which breaks build
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} ${MAKE_ARGS} build

do-build-DOCS-on:
	cd ${WRKSRC}/docs && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} ${MAKE_ARGS} html

test:
.if exists(${LOCALBASE}/bin/awsres)
	@cd ${WRKSRC}/regtests && ${SETENV} ${MAKE_ENV} TIMEOUT=75 \
		python${PYTHON_VER} testsuite.py
.else
	@${ECHO} "AWS has to be installed before testing"
.endif

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/share/gpr/manifests
	${RM} ${STAGEDIR}${PREFIX}/include/aws.relocatable/Makefile
	${RM} ${STAGEDIR}${PREFIX}/include/aws/Makefile
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/gnat \
		${STAGEDIR}${PREFIX}/share/gps/plug-ins
	${CAT} ${FILESDIR}/aws.gpr.in | ${SED} -e 's|@PREFIX@|${PREFIX}|g' \
		-e 's|@SSL@|${LINK_SSL}|g' -e 's|@TLS@|${LINK_TLS}|g' \
		-e 's|@LDP@|${LINK_LDP}|g' -e 's|@IP4@|${NAME_IP4}|g' \
		-e 's|@IP6@|${NAME_IP6}|g' -e 's|@STD@|${NAME_STD}|g' \
		> ${STAGEDIR}${PREFIX}/lib/gnat/aws.gpr
	cd ${WRKSRC}/gps && ${INSTALL_DATA} *.xml aws.py \
		${STAGEDIR}${PREFIX}/share/gps/plug-ins

.include <bsd.port.post.mk>
