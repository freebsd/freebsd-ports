# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	aws
PORTVERSION=	17.1
PORTREVISION=	1
CATEGORIES=	www
PKGNAMESUFFIX=	-demos

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Adacore Ada Web Server demos

LICENSE=	GPLv3 GPLv3RLE
LICENSE_COMB=	multi

BUILD_DEPENDS=	gprbuild:devel/gprbuild \
		xmlada>=4.4:textproc/xmlada \
		aws>=3.1:www/aws

USES=		ada gmake python
USE_GITHUB=	yes
GH_ACCOUNT=	AdaCore
GH_TUPLE=	AdaCore:templates-parser:${PORTVERSION}:tp/templates_parser

DISTINFO_FILE=	${PORTSDIR}/www/aws/distinfo

CONF_ARGS=	PROCESSORS=1
CONF_ARGS+=	GCC=ada
CONF_ARGS+=	prefix=${PREFIX}

OPTIONS_DEFINE=		SSL LDAP
OPTIONS_DEFAULT=	SSL
OPTIONS_SUB=		yes

SSL_USES=		ssl

DEMO_DIRS+=	auth
DEMO_DIRS+=	autobahn
DEMO_DIRS+=	cert
DEMO_DIRS+=	com
DEMO_DIRS+=	dispatch
DEMO_DIRS+=	gSOAP
DEMO_DIRS+=	dowload_manager
DEMO_DIRS+=	hello_world
DEMO_DIRS+=	hello_wsdl
DEMO_DIRS+=	hotplug
DEMO_DIRS+=	interoplab
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
DEMO_DIRS+=	ws_candy
DEMO_DIRS+=	zdemo

PROGS=		multiple_sessions/multiple_sessions \
		jabber_demo/jabber_demo \
		auth/auth \
		text_input/text_input \
		web_block/web_block \
		web_mail/web_mail \
		websockets/websock \
		wps/wps \
		interoplab/interoplab_main \
		soap_demo/soap_server \
		soap_demo/soap_client \
		web_block_ajax/web_block_ajax \
		web_elements/web_elements_program \
		cert/cert \
		com/com_2 \
		com/com_1 \
		dowload_manager/download_manager \
		hello_world/hello_world \
		hello_wsdl/wsdl_demo_client \
		hello_wsdl/wsdl_demo_server \
		hotplug/main \
		hotplug/hotplug \
		res_demo/res_demo \
		soap_vs/soap_svs \
		soap_vs/soap_cvs \
		test_mail/test_mail \
		upload/upload \
		vh_demo/vh_demo \
		ws/ws \
		ws_candy/candy \
		split/split \
		dispatch/dispatch \
		zdemo/zdemo \
		soap_disp/soap_server_disp \
		soap_disp/soap_client

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSSL}
CONF_ARGS+=	SOCKET=openssl
DEMO_DIRS+=	agent
DEMO_DIRS+=	https
DEMO_DIRS+=	runme
PROGS+=		agent/agent \
		https/https \
		runme/runme
.endif

.if ${PORT_OPTIONS:MLDAP}
CONF_ARGS+=	LDAP=true
DEMO_DIRS+=	test_ldap
PROGS+=		test_ldap/test_ldap
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|@PREFIX@|${LOCALBASE}|g' \
		${WRKSRC}/demos/test_ldap/test_ldap.gpr
	@${REINPLACE_CMD} -e 's|latexpdf||' ${WRKSRC}/Makefile
.for dd in ${DEMO_DIRS}
	@${REINPLACE_CMD} -i '' -e 's|gprclean|gprclean -c|' \
		${WRKSRC}/demos/${dd}/Makefile
.endfor

do-configure:
	${MKDIR} ${WRKSRC}/.build/native/debug/static/obj
	(cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${MAKE_CMD} setup ${CONF_ARGS})

do-build:
.for dd in ${DEMO_DIRS}
	@${ECHO_MSG} "=== BUILD ${dd} ==="
	(cd ${WRKSRC}/demos/${dd} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD})
	(cd ${WRKSRC}/demos/${dd} && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} clean && ${RM} -r Makefile *.ad[bs] *.gpr src)
.endfor

do-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/demos
	(cd ${WRKSRC} && ${COPYTREE_SHARE} web_elements \
		${STAGEDIR}${EXAMPLESDIR})
.for dd in ${DEMO_DIRS:Nautobahn}
	(cd ${WRKSRC}/demos && ${COPYTREE_SHARE} ${dd} \
		${STAGEDIR}${EXAMPLESDIR}/demos)
.endfor
.for prog in ${PROGS}
	@${CHMOD} 755 ${STAGEDIR}${EXAMPLESDIR}/demos/${prog}
	@${STRIP_CMD} ${STAGEDIR}${EXAMPLESDIR}/demos/${prog}
	@${CHMOD} ${BINMODE} ${STAGEDIR}${EXAMPLESDIR}/demos/${prog}
.endfor

.include <bsd.port.mk>
