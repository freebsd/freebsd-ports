# $FreeBSD$

PORTNAME=	ejabberd
PORTVERSION=	19.09.1
CATEGORIES=	net-im

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Free and Open Source distributed fault-tolerant Jabber server

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	erlc:lang/erlang
RUN_DEPENDS=	erl:lang/erlang
LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libyaml.so:textproc/libyaml \
		libgd.so:graphics/gd \
		libpng.so:graphics/png \
		libwebp.so:graphics/webp

USES=		cpe gmake pkgconfig shebangfix ssl jpeg autoreconf:build

USERS=		ejabberd
GROUPS=		${USERS}

GNU_CONFIGURE=	yes
USE_RC_SUBR=	${PORTNAME}
NOPRECIOUSMAKEVARS=	yes
CPE_VENDOR=	process-one

USE_GITHUB=	yes
GH_ACCOUNT=	processone
GH_TUPLE=	erlang-lager:lager:${LAGER_VER}:lager/deps/lager \
		processone:p1_utils:${P1_UTILS_VER}:p1_utils/deps/p1_utils \
		processone:cache_tab:${CACHE_TAB_VER}:cache_tab/deps/cache_tab \
		processone:fast_tls:${FAST_TLS_VER}:fast_tls/deps/fast_tls \
		processone:stringprep:${STRINGPREP_VER}:stringprep/deps/stringprep \
		processone:fast_xml:${FAST_XML_VER}:fast_xml/deps/fast_xml \
		processone:xmpp:${XMPP_VER}:xmpp/deps/xmpp \
		processone:fast_yaml:${FAST_YAML_VER}:fast_yaml/deps/fast_yaml \
		davisp:jiffy:${JIFFY_VER}:jiffy/deps/jiffy \
		processone:p1_oauth2:${P1_OAUTH2_VER}:p1_oauth2/deps/p1_oauth2 \
		potatosalad:erlang-jose:${JOSE_VER}:jose/deps/jose \
		processone:eimp:${EIMP_VER}:eimp/deps/eimp \
		DeadZen:goldrush:${GOLDRUSH_VER}:goldrush/deps/goldrush \
		dvv:base64url:f2c64ed8:base64url/deps/base64url \
		processone:ezlib:${EZLIB_VER}:ezlib/deps/ezlib \
		processone:pkix:${PKIX_VER}:pkix/deps/pkix \
		processone:mqtree:${MQTREE_VER}:mqtree/deps/mqtree \
		processone:yconf:${YCONF_VER}:yconf/deps/yconf \
		processone:p1_acme:${P1_ACME_VER}:p1_acme/deps/p1_acme \
		benoitc:erlang-idna:${IDNA_VER}:idna/deps/idna \
		benoitc:unicode_util_compat:${UNICODE_UTIL_COMPAT_VER}:unicode_util_compat/deps/unicode_util_compat

OPTIONS_DEFINE=	ODBC PAM DOCS MYSQL PGSQL REDIS SIP SQLITE \
		STUN TOOLS FULLXML

EJABBERD_LIBDIR=lib/erlang/lib
MAKE_ENV=	PORTVERSION=${PORTVERSION}
CONFIGURE_ARGS+=--localstatedir=/var --libdir=${PREFIX}/${EJABBERD_LIBDIR}
MAKE_ARGS=	"CPPFLAGS=${CPPFLAGS}" "CFLAGS=${CFLAGS}" "LDFLAGS=${LDFLAGS}"
CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
SUBS= 		PORTNAME=${PORTNAME} PORTVERSION=${PORTVERSION}		\
		EJABBERD_LIBDIR=${EJABBERD_LIBDIR}			\
		BASE64URL_VER=${BASE64URL_VER}				\
		CACHE_TAB_VER=${CACHE_TAB_VER} EIMP_VER=${EIMP_VER}	\
		EPAM_VER=${EPAM_VER} EREDIS_VER=${EREDIS_VER}		\
		ESIP_VER=${ESIP_VER} EZLIB_VER=${EZLIB_VER}		\
		FAST_TLS_VER=${FAST_TLS_VER}				\
		FAST_XML_VER=${FAST_XML_VER}				\
		FAST_YAML_VER=${FAST_YAML_VER}				\
		GOLDRUSH_VER=${GOLDRUSH_VER}				\
		IDNA_VER=${IDNA_VER}					\
		JIFFY_VER=${JIFFY_VER} JOSE_VER=${JOSE_VER}		\
		LAGER_VER=${LAGER_VER} LUERL_VER=${LUERL_VER}		\
		MQTREE_VER=${MQTREE_VER}				\
		P1_ACME_VER=${P1_ACME_VER}				\
		P1_MYSQL_VER=${P1_MYSQL_VER}				\
		P1_OAUTH2_VER=${P1_OAUTH2_VER}				\
		P1_PGSQL_VER=${P1_PGSQL_VER}				\
		P1_UTILS_VER=${P1_UTILS_VER} PKIX_VER=${PKIX_VER}	\
		SQLITE3_VER=${SQLITE3_VER}				\
		STRINGPREP_VER=${STRINGPREP_VER} STUN_VER=${STUN_VER}	\
		UNICODE_UTIL_COMPAT_VER=${UNICODE_UTIL_COMPAT_VER}	\
		XMPP_VER=${XMPP_VER} YCONF_VER=${YCONF_VER}

SUB_FILES=	pkg-message pkg-install
PLIST_SUB=	${SUBS}
SUB_LIST=	${SUBS} \
		USERS=${USERS} GROUPS=${GROUPS} SHAREMODE=${SHAREMODE} \
		SHAREOWN=${SHAREOWN} SHAREGRP=${SHAREGRP} \
		EJABBERD_LIBDIR=${EJABBERD_LIBDIR}
SHEBANG_FILES=	${WRKSRC}/ejabberdctl.template

BASE64URL_VER=	0.0.1
CACHE_TAB_VER=	1.0.20
EIMP_VER=	1.0.12
EPAM_VER=	1.0.6
EREDIS_VER=	1.0.8
ESIP_VER=	1.0.30
EZLIB_VER=	1.0.6
FAST_TLS_VER=	1.1.2
FAST_XML_VER=	1.1.37
FAST_YAML_VER=	1.0.21
GOLDRUSH_VER=	0.1.9
IDNA_VER=	6.0.0
JIFFY_VER=	0.14.8
JOSE_VER=	1.8.4
LAGER_VER=	3.6.10
LUERL_VER=	0.3
MQTREE_VER=	1.0.5
P1_ACME_VER=	1.0.1
P1_MYSQL_VER=	1.0.11
P1_OAUTH2_VER=	0.6.5
P1_PGSQL_VER=	1.1.8
P1_UTILS_VER=	1.0.16
PKIX_VER=	1.0.4
SQLITE3_VER=	1.1.6
STRINGPREP_VER=	1.0.17
STUN_VER=	1.0.29
UNICODE_UTIL_COMPAT_VER=	0.4.1
XMPP_VER=	1.4.2
YCONF_VER=	1.0.1

OPTIONS_SUB=		yes
SIP_DESC=	SIP support
STUN_DESC=	STUN/TURN support
TOOLS_DESC=	Build development tools
FULLXML_DESC=	Full XML support
PAM_CONFIGURE_ENABLE=	pam
PAM_GH_TUPLE=	processone:epam:${EPAM_VER}:epam/deps/epam
ODBC_CONFIGURE_ENABLE=	odbc
MYSQL_CONFIGURE_ENABLE=	mysql
MYSQL_GH_TUPLE=	processone:p1_mysql:${P1_MYSQL_VER}:p1_mysql/deps/p1_mysql
PGSQL_CONFIGURE_ENABLE=	pgsql
PGSQL_GH_TUPLE=	processone:p1_pgsql:${P1_PGSQL_VER}:p1_pgsql/deps/p1_pgsql
REDIS_CONFIGURE_ENABLE=	redis
REDIS_GH_TUPLE=	wooga:eredis:v${EREDIS_VER}:eredis/deps/eredis
SIP_CONFIGURE_ENABLE=	sip
SIP_GH_TUPLE=	processone:esip:${ESIP_VER}:esip/deps/esip
SIP_IMPLIES=	STUN
STUN_CONFIGURE_ENABLE=	stun
STUN_GH_TUPLE=	processone:stun:${STUN_VER}:stun/deps/stun
SQLITE_CONFIGURE_ENABLE=sqlite
SQLITE_GH_TUPLE=	processone:erlang-sqlite3:${SQLITE3_VER}:sqlite3/deps/sqlite3
TOOLS_CONFIGURE_ENABLE=	tools
TOOLS_GH_TUPLE=	rvirding:luerl:v${LUERL_VER}:luerl/deps/luerl
FULLXML_CONFIGURE_ENABLE=	full-xml
SQLITE_USES=		sqlite
DOCS_MAKE_ARGS_OFF=	NOPORTDOCS=yes

pre-everything::
	@if ${PKG_BIN} query %n-%v net-im/ejabberd; then \
		${ECHO_MSG} needs to be uninstalled, before this port build could proceed. ; \
		${ECHO_MSG} For details: https://github.com/processone/ejabberd/issues/2194 ; \
		${ECHO_MSG} Sorry for the inconvenience. ; \
		exit 1; \
	fi

post-patch:
	@${REINPLACE_CMD} -e 's,^convert,${LOCALBASE}/bin/convert,' ${WRKSRC}/tools/captcha.sh
	@${REINPLACE_CMD} -e 's,%%PORTVERSION%%,${PORTVERSION},' ${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e '/vsn/s/git/"${JIFFY_VER}"/' ${WRKSRC}/deps/jiffy/src/jiffy.app.src

pre-configure:
	cd ${WRKSRC} && ${SH} autogen.sh
	@${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},g' \
		${WRKSRC}/ejabberdctl.template

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EJABBERD_LIBDIR}

post-install-PAM-on:
	${INSTALL} -m 444 ${FILESDIR}/pam_ejabberd \
		${STAGEDIR}${PREFIX}/etc/pam.d/ejabberd
	${INSTALL} -m 0750 ${STAGEDIR}${PREFIX}/${EJABBERD_LIBDIR}/${PORTNAME}-${PORTVERSION}/lib/epam-${EPAM_VER}/priv/bin/epam \
		${STAGEDIR}${PREFIX}/${EJABBERD_LIBDIR}/${PORTNAME}-${PORTVERSION}/priv/bin/epam
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${EJABBERD_LIBDIR}/${PORTNAME}-${PORTVERSION}/lib/epam-${EPAM_VER}/priv/bin/epam \
		${STAGEDIR}${PREFIX}/${EJABBERD_LIBDIR}/${PORTNAME}-${PORTVERSION}/priv/bin/epam

post-install:
	@${FIND} ${STAGEDIR}${PREFIX}/${EJABBERD_LIBDIR} -type f \
		-name '*.so' -exec ${STRIP_CMD} {} \;
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${STAGEDIR}${PREFIX}/${EJABBERD_LIBDIR}/${PORTNAME}-${PORTVERSION}/priv/bin/captcha.sh \
		${STAGEDIR}${DATADIR}
	@${REINPLACE_CMD} -r -e '/captcha_cmd:/s,"[^"]+","${DATADIR}/captcha.sh",' ${STAGEDIR}${ETCDIR}/${PORTNAME}.yml.example
	@${CHMOD} +x ${STAGEDIR}${PREFIX}/${EJABBERD_LIBDIR}/${PORTNAME}-${PORTVERSION}/lib/eimp-${EIMP_VER}/priv/bin/eimp
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${EJABBERD_LIBDIR}/${PORTNAME}-${PORTVERSION}/lib/eimp-${EIMP_VER}/priv/bin/eimp

.include <bsd.port.mk>
