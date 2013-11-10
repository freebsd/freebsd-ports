# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	aws
PORTVERSION=	3.1.0.0
CATEGORIES=	www
MASTER_SITES=	http://downloads.dragonlace.net/src/
PKGNAMESUFFIX=	-demos

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Adacore Ada Web Server demos

BUILD_DEPENDS+=	gprbuild>=20120510:${PORTSDIR}/devel/gprbuild \
		xmlada>=3.2:${PORTSDIR}/textproc/xmlada \
		aws>=3.1:${PORTSDIR}/www/aws

USE_BZIP2=	yes
USES=		ada gmake

CONF_ARGS=	PROCESSORS=1
CONF_ARGS+=	GCC=ada
CONF_ARGS+=	prefix=${PREFIX}

OPTIONS_DEFINE=		SSL LDAP
OPTIONS_DEFAULT=	SSL

DEMO_DIRS+=	auth
DEMO_DIRS+=	autobahn
DEMO_DIRS+=	cert
DEMO_DIRS+=	com
DEMO_DIRS+=	dispatch
DEMO_DIRS+=	dowload_manager
DEMO_DIRS+=	hello_world
DEMO_DIRS+=	hotplug
DEMO_DIRS+=	jabber_demo
DEMO_DIRS+=	multiple_sessions
DEMO_DIRS+=	res_demo
DEMO_DIRS+=	soap_demo
DEMO_DIRS+=	soap_disp
DEMO_DIRS+=	soap_vs
DEMO_DIRS+=	split
DEMO_DIRS+=	test_mail
DEMO_DIRS+=	text_input
DEMO_DIRS+=	upload
DEMO_DIRS+=	vh_demo
DEMO_DIRS+=	web_block
DEMO_DIRS+=	web_block_ajax
DEMO_DIRS+=	web_block_ajax_templates
DEMO_DIRS+=	web_elements
DEMO_DIRS+=	web_mail
DEMO_DIRS+=	websockets
DEMO_DIRS+=	wps
DEMO_DIRS+=	ws
DEMO_DIRS+=	zdemo

# These don't build, fail finding "aws.ini"
#DEMO_DIRS+=	hello_wsdl
#DEMO_DIRS+=	interoplab

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSSL}
CONF_ARGS+=	SOCKET=openssl
DEMO_DIRS+=	agent
DEMO_DIRS+=	runme
PLIST_SUB+=	OSSL=""
.else
PLIST_SUB+=	OSSL="@comment "
.endif

.if ${PORT_OPTIONS:MLDAP}
CONF_ARGS+=	LDAP=true
DEMO_DIRS+=	test_ldap
PLIST_SUB+=	LDAP=""
.else
PLIST_SUB+=	LDAP="@comment "
.endif

EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME}${PKGNAMESUFFIX}

post-patch:
	@${REINPLACE_CMD} -e 's|@PREFIX@|${LOCALBASE}|g' \
		${WRKSRC}/demos/test_ldap/test_ldap.gpr

do-configure:
	${MKDIR} ${WRKSRC}/.build/native/debug/static/obj
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
	   ${GMAKE} setup ${CONF_ARGS}

do-build:
.for dd in ${DEMO_DIRS}
	@${ECHO_MSG} "=== BUILD ${dd} ==="
	cd ${WRKSRC}/demos/${dd} && ${SETENV} ${MAKE_ENV} ${GMAKE}
.endfor

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/examples/aws-demos
.for dd in ${DEMO_DIRS}
	${FIND} ${WRKSRC}/demos/${dd} -type f -perm -0001 \
	   -exec ${INSTALL} {} ${STAGEDIR}${PREFIX}/share/examples/aws-demos/ \;
.endfor

.include <bsd.port.mk>
