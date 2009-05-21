# Ports collection makefile for:	pubcookie
# Date created:				Sat Jan 21, 2006
# Whom:					Brooks Davis <brooks@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	pubcookie
PORTVERSION=	3.3.0
CATEGORIES=	www security
MASTER_SITES=	http://pubcookie.org/downloads/
PKGNAMEPREFIX=	mod_
DISTNAME=	${PORTNAME}-3.3.0a

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	A single sign-on system for websites (apache module)

MAKE_JOBS_UNSAFE=	yes

CONFLICTS=	pubcookie-login-server-[0-9]*

FILESDIR=	${.CURDIR}/../pubcookie-login-server/files
MD5_FILE=	${.CURDIR}/../pubcookie-login-server/distinfo
PATCHDIR=	${.CURDIR}/../pubcookie-login-server/files

HAS_CONFIGURE=	YES
# GNU_CONFIGURE things since we're not installing directly in PREFIX
CONFIGURE_ARGS+=	--prefix=${PC_DIR} ${CONFIGURE_TARGET}

# We want to build the module server
CONFIGURE_ARGS+=	--enable-apache --disable-login

# mod_pubcookie supports other Apache versions, but the port doesn't yet
USE_APACHE=	20
CONFIGURE_ARGS+=	--with-apxs=${APXS}
MODULENAME=	mod_${PORTNAME}
#SHORTMODNAME=	${PORTNAME}

USE_OPENSSL=	YES
CONFIGURE_ARGS+=	--with-ssl=${OPENSSLBASE}

PC_BASE?=	${PORTNAME}
PC_DIR=		${PREFIX}/${PC_BASE}

SUB_FILES+=	pkg-install
SUB_LIST+=	CONF_FILES="${CONF_FILES}" CONF_DIRS="${CONF_DIRS}"
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${PKGINSTALL}
CONF_FILES+=	${PC_BASE}/config.sample:${PC_BASE}/config

# XXX Add Kerberos

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

do-install:
	${MKDIR} ${PC_DIR}/keys
	${INSTALL_PROGRAM} ${WRKSRC}/keyclient ${PC_DIR}
	${INSTALL_DATA} ${WRKSRC}/doc/config.sample ${PC_DIR}
	${APXS} -i -A -n ${SHORTMODNAME} ${WRKSRC}/module/${MODULENAME}.${AP_BUILDEXT}

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
