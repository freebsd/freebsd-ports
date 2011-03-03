# New ports collection makefile for:  aws
# Date created:                       12 December 2010
# Whom:                               John Marino <draco@marino.st>
#
# $FreeBSD$
#

PORTNAME=	aws
PORTVERSION=	2.10.0
CATEGORIES=	www
MASTER_SITES=	http://downloads.dragonlace.net/src/ \
		http://dragonlace.mirrors.ada.cx/src/

MAINTAINER=	draco@marino.st
COMMENT=	Adacore Ada Web Server and framework

BUILD_DEPENDS=	gnat-aux>=20101204:${PORTSDIR}/lang/gnat-aux \
		gprbuild-aux>=20101120:${PORTSDIR}/devel/gprbuild-aux \
		xmlada>=3.2:${PORTSDIR}/textproc/xmlada \
		gnatpython>=20101207:${PORTSDIR}/devel/gnatpython

USE_PYTHON=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
CC=		gnatgcc
DOTBUILD=	release
MAKE_ENV+=	ADA_PROJECT_PATH=${PREFIX}/lib/gnat

OPTIONS=	SSL   "Enable HTTPS/SSL support" on
OPTIONS+=	IPV6  "Enable IPv6 support" off
OPTIONS+=	DEMOS "Build demo programs in examples/aws/demos" off
OPTIONS+=	DEBUG "Build AWS with debugging symbols" off
OPTIONS+=	LDAP  "Enable LDAP support" off
OPTIONS+=	DSRT  "Disable shared runtime" off
OPTIONS+=	RELOC "Build shared libraries (default is static)" off

CONF_ARGS=	PROCESSORS=1
CONF_ARGS+=	GCC=gnatgcc
CONF_ARGS+=	PYTHON=python${PYTHON_VER}

.include <bsd.port.options.mk>

###################
##  SSL Support  ##
###################

.if defined(WITH_SSL)
CONF_ARGS+=	SOCKET=openssl
BUILD_DEPENDS+=	openssl>=1:${PORTSDIR}/security/openssl
RUN_DEPENDS+=	openssl>=1:${PORTSDIR}/security/openssl
PLIST_SUB+=	YSSL=""
PLIST_SUB+=	NSSL="@comment "
.else
PLIST_SUB+=	YSSL="@comment "
PLIST_SUB+=	NSSL=""
.endif

####################
##  LDAP Support  ##
####################

.if defined(WITH_LDAP)
CONF_ARGS+=	LDAP=true
RUN_DEPENDS+=	openldap24>=2.4:${PORTSDIR}/net/openldap24-client
.endif

####################
##  IPv6 Support  ##
####################

.if defined(WITH_IPV6)
CONF_ARGS+=	IPv6=true
.endif

#####################
##  Debug Support  ##
#####################

.if defined(WITH_DEBUG)
CONF_ARGS+=	DEBUG=true
.endif

##############################
##  Shared Runtime Library  ##
##############################

.if defined(WITH_DSRT)
CONF_ARGS+=	ENABLE_SHARED=false
.endif

############################
##  Default Library Type  ##
############################

.if defined(WITH_RELOC)
CONF_ARGS+=	DEFAULT_LIBRARY_TYPE=relocatable
.endif

#####################
##  DEMOS Support  ##
#####################

.if defined(WITH_DEMOS)
DEMO_DIRS+=	agent
DEMO_DIRS+=	auth
DEMO_DIRS+=	com
DEMO_DIRS+=	dispatch
DEMO_DIRS+=	hello_world
DEMO_DIRS+=	hello_wsdl
DEMO_DIRS+=	hotplug
DEMO_DIRS+=	interoplab
DEMO_DIRS+=	jabber_demo
DEMO_DIRS+=	multiple_sessions
DEMO_DIRS+=	res_demo
DEMO_DIRS+=	runme
DEMO_DIRS+=	soap_demo
DEMO_DIRS+=	soap_disp
DEMO_DIRS+=	soap_vs
DEMO_DIRS+=	split
DEMO_DIRS+=	test_mail
DEMO_DIRS+=	text_input
DEMO_DIRS+=	vh_demo
DEMO_DIRS+=	web_block
DEMO_DIRS+=	web_block_ajax
DEMO_DIRS+=	web_block_ajax_templates
DEMO_DIRS+=	web_elements
DEMO_DIRS+=	web_mail
DEMO_DIRS+=	wps
DEMO_DIRS+=	ws
DEMO_DIRS+=	zdemo

.if defined (WITH_LDAP)
DEMO_DIRS+=	test_ldap
PLIST_SUB+=	LDAP=""
.else
PLIST_SUB+=	LDAP="@comment "
.endif
PLIST_SUB+=	DEMO=""
.else
PLIST_SUB+=	DEMO="@comment "
PLIST_SUB+=	LDAP="@comment "
.endif

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
	${GMAKE} setup ${CONF_ARGS}

do-build:
	# docs are built, but the .pdf format is intentionally disabled
	# The taTeX dependency brings in ~100MB so it's not worth it.
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} build build_doc

test: install
	cd ${WRKSRC}/regtests && python2.6 testsuite.py

do-install:
	cd ${WRKSRC} && ${GMAKE} install
.if defined(WITH_DEMOS)
	${MAKE} demos
	${MAKE} demos-install
.endif

demos:
.for dd in ${DEMO_DIRS}
	cd ${WRKSRC}/demos/${dd} && ${GMAKE}
.endfor

demos-install:
	${MKDIR} ${PREFIX}/share/examples/aws/demos
.for dd in ${DEMO_DIRS}
	${FIND} ${WRKSRC}/demos/${dd} -type f -perm -0001 \
	-exec ${INSTALL} {} ${PREFIX}/share/examples/aws/demos/ \;
.endfor

.include <bsd.port.mk>
