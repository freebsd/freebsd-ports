# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	aws
PORTVERSION=	3.3.0.0
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://downloads.dragonlace.net/src/
PKGNAMESUFFIX=	-demos

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Adacore Ada Web Server demos

LICENSE=	GPLv3 GPLv3RLE
LICENSE_COMB=	multi

BUILD_DEPENDS=	gprbuild:devel/gprbuild \
		xmlada>=4.4:textproc/xmlada \
		aws>=3.1:www/aws

USES=		ada gmake tar:bzip2

DISTINFO_FILE=	${PORTSDIR}/www/aws/distinfo

CONF_ARGS=	PROCESSORS=1
CONF_ARGS+=	GCC=ada
CONF_ARGS+=	prefix=${PREFIX}

OPTIONS_DEFINE=		SSL LDAP
OPTIONS_DEFAULT=	SSL
OPTIONS_SUB=		yes

DEMO_DIRS+=	auth
DEMO_DIRS+=	autobahn
DEMO_DIRS+=	cert
DEMO_DIRS+=	com
DEMO_DIRS+=	dispatch
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

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSSL}
CONF_ARGS+=	SOCKET=openssl
DEMO_DIRS+=	agent
DEMO_DIRS+=	runme
.endif

.if ${PORT_OPTIONS:MLDAP}
CONF_ARGS+=	LDAP=true
DEMO_DIRS+=	test_ldap
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|@PREFIX@|${LOCALBASE}|g' \
		${WRKSRC}/demos/test_ldap/test_ldap.gpr
	@${REINPLACE_CMD} -e 's| setup_tp | |' ${WRKSRC}/Makefile

do-configure:
	${MKDIR} ${WRKSRC}/.build/native/debug/static/obj
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
	   ${MAKE_CMD} setup ${CONF_ARGS}

do-build:
.for dd in ${DEMO_DIRS}
	@${ECHO_MSG} "=== BUILD ${dd} ==="
	cd ${WRKSRC}/demos/${dd} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD}
.endfor

do-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/templates \
		${STAGEDIR}${EXAMPLESDIR}/images
.for dd in ${DEMO_DIRS}
	${FIND} ${WRKSRC}/demos/${dd} -type f -perm -0001 \
	   -exec ${INSTALL} {} ${STAGEDIR}${EXAMPLESDIR}/ \;
.endfor
	cd ${WRKSRC} && \
		${COPYTREE_SHARE} web_elements ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/demos/runme/aws_*.png \
		${STAGEDIR}${EXAMPLESDIR}/images
	${INSTALL_DATA} ${WRKSRC}/demos/web_mail/*html \
		${STAGEDIR}${EXAMPLESDIR}/templates
	${INSTALL_DATA} ${FILESDIR}/templates.tads \
		${STAGEDIR}${EXAMPLESDIR}/templates

.include <bsd.port.mk>
