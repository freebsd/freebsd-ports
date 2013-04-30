# Created by: John Marino <draco@marino.st>
# $FreeBSD$

PORTNAME=	aws
PORTVERSION=	2.10.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://downloads.dragonlace.net/src/

MAINTAINER=	draco@marino.st
COMMENT=	Adacore Ada Web Server and framework

BUILD_DEPENDS=	gprbuild>=20120510:${PORTSDIR}/devel/gprbuild \
		xmlada>=3.2:${PORTSDIR}/textproc/xmlada \
		gnatpython>=20101207:${PORTSDIR}/devel/gnatpython

USE_PYTHON=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USES+=		ada
MAKE_JOBS_SAFE=	yes
DOTBUILD=	release
ADDL_RPATH=	${LOCALBASE}/lib:${LOCALBASE}/lib/aws/native/relocatable

OPTIONS_DEFINE=		SSL IP6 DEBUG LDAP DSRT RELOC
OPTIONS_DEFAULT=	SSL
NO_OPTIONS_SORT=	yes

SSL_DESC=		Enable HTTPS/SSL support
DSRT_DESC=		Disable shared runtime
RELOC_DESC=		Build shared libraries (default is static)
IP6_DESC=		Support IPv6 instead of IPv4

CONF_ARGS=	PROCESSORS=${MAKE_JOBS_NUMBER}
CONF_ARGS+=	GCC=ada
CONF_ARGS+=	PYTHON=python${PYTHON_VER}
CONF_ARGS+=	XMLADA=true
CONF_ARGS+=	PRJ_BUILD=${DOTBUILD}
CONF_ARGS+=	prefix=${PREFIX}

.include <bsd.port.options.mk>

###################
##  SSL Support  ##
###################

.if ${PORT_OPTIONS:MSSL}
USE_OPENSSL=	yes
CONF_ARGS+=	SOCKET=openssl
PLIST_SUB+=	YSSL=""
PLIST_SUB+=	NSSL="@comment "
.else
PLIST_SUB+=	YSSL="@comment "
PLIST_SUB+=	NSSL=""
.endif

####################
##  LDAP Support  ##
####################

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=	yes
CONF_ARGS+=	LDAP=true
PLIST_SUB+=	LDAP=""
.else
PLIST_SUB+=	LDAP="@comment "
.endif

####################
##  IPv6 Support  ##
####################

.if ${PORT_OPTIONS:MIP6}
CONF_ARGS+=	IPv6=true
PLIST_SUB+=	NIP6="@comment "
PLIST_SUB+=	YIP6=""
.else
PLIST_SUB+=	YIP6="@comment "
PLIST_SUB+=	NIP6=""
.endif

#####################
##  Debug Support  ##
#####################

.if ${PORT_OPTIONS:MDEBUG}
CONF_ARGS+=	DEBUG=true
.endif

##############################
##  Shared Runtime Library  ##
##############################

.if ${PORT_OPTIONS:MDSRT}
CONF_ARGS+=	ENABLE_SHARED=false
.endif

############################
##  Default Library Type  ##
############################

.if ${PORT_OPTIONS:MRELOC}
CONF_ARGS+=	DEFAULT_LIBRARY_TYPE=relocatable
.endif

#####################
##  DEMOS Support  ##
#####################

# Option removed.
# Demos require an installed AWS to build.
# These demos must be moved to a separate port, e.g. www/aws-demos

post-patch:
	@${REINPLACE_CMD} \
	   -e 's|@ADDITIONAL_RPATH@|${ADDL_RPATH}|' \
	   -e 's|@PREFIX@|${LOCALBASE}|g' \
		${WRKSRC}/src/src.gpr \
		${WRKSRC}/include/include.gpr

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${GMAKE} setup ${CONF_ARGS}

do-build:
	# docs are built, but the .pdf format is intentionally disabled
	# The taTeX dependency brings in ~100MB so it's not worth it.
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${GMAKE} build build_doc

test: install
	cd ${WRKSRC}/regtests && python${PYTHON_VER} testsuite.py

do-install:
	cd ${WRKSRC} && ${GMAKE} install

.include <bsd.port.mk>
