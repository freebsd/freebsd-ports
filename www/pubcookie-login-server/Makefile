# Ports collection makefile for:	pubcookie
# Date created:				Sat Jan 21, 2006
# Whom:					Brooks Davis <brooks@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	pubcookie
PORTVERSION=	3.3.0
PORTREVISION=	3
CATEGORIES=	www security
MASTER_SITES=	http://pubcookie.org/downloads/
PKGNAMESUFFIX=	-login-server
DISTNAME=	${PORTNAME}-3.3.0a

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	A single sign-on system for websites (login server)

CONFLICTS=      mod_pubcookie-[0-9]*

OPTIONS=	LDAP "Enable LDAP verifier" on \
		FCGI "Enable FastCGI support" on

HAS_CONFIGURE=	YES
# GNU_CONFIGURE things since we're not installing directly in PREFIX
CONFIGURE_ARGS+=	--prefix=${PC_DIR} ${CONFIGURE_TARGET}

# We want to build the login server
CONFIGURE_ARGS+=	--enable-login --disable-apache

USE_OPENSSL=	YES
CONFIGURE_ARGS+=	--with-ssl=${OPENSSLBASE}

PC_BASE?=	${PORTNAME}
PC_DIR=		${PREFIX}/${PC_BASE}

SUB_FILES+=	pkg-install
SUB_LIST+=	CONF_FILES="${CONF_FILES}" CONF_DIRS="${CONF_DIRS}"
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${PKGINSTALL}
.include "${.CURDIR}/Makefile.templates"
CONF_FILES+=	${LOGIN_TEMPLATES:C|(.*)|${PC_BASE}/login_templates.default/\1:${PC_BASE}/login_templates/\1|}
CONF_DIRS+=	${PC_BASE}/login_templates
CONF_FILES+=	${LOGIN_IMAGES:C|(.*)|${PC_BASE}/login_templates.default/images/\1:${PC_BASE}/login/images/\1|}
CONF_DIRS+=	${PC_BASE}/login/images
CONF_FILES+=	${PC_BASE}/config.login.sample:${PC_BASE}/config

# XXX Add Kerberos

.include <bsd.port.pre.mk>

.if defined(WITH_LDAP)
USE_OPENLDAP=	YES
CONFIGURE_ARGS+=	--enable-ldap --with-ldap-dir=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--disable-ldap
.endif

.if defined(WITH_FCGI)
LIB_DEPENDS+=	fcgi.0:${PORTSDIR}/www/fcgi
CONFIGURE_ARGS+=	--with-fcgi=${LOCALBASE}
.endif

# XXX: more GNU_CONFIGURE hackery
pre-configure:
	@CONFIG_GUESS_DIRS=$$(${FIND} ${WRKDIR} -name config.guess -o -name config.sub \
		| ${XARGS} -n 1 ${DIRNAME}); \
	for _D in $${CONFIG_GUESS_DIRS}; do \
		${CP} -f ${TEMPLATES}/config.guess $${_D}/config.guess; \
		${CHMOD} a+rx $${_D}/config.guess; \
		${CP} -f ${TEMPLATES}/config.sub $${_D}/config.sub; \
		${CHMOD} a+rx $${_D}/config.sub; \
	done

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

###########################
# Port MAINTAINER targets #
###########################

Makefile.templates: configure
	${ECHO_CMD} "# Generated with Makefile.templates target" > Makefile.templates
	${ECHO_CMD} "LOGIN_TEMPLATES+=" `cd ${WRKSRC} && make -V LOGIN_TEMPLATES | ${SED} -e 's| *./src/login_templates.generic/| |g'` >> Makefile.templates
	${ECHO_CMD} "LOGIN_IMAGES+=" `cd ${WRKSRC} && make -V LOGIN_IMAGES | ${SED} -e 's| *./src/login_templates.generic/images/| |g'` >> Makefile.templates
	${CAT} Makefile.templates

.include <bsd.port.post.mk>
