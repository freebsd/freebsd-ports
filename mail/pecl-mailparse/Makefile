# Ports collection makefile for:  pear-mailparse
# Date created:			  09 January 2003
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	mailparse
PORTVERSION=	0.9.1
CATEGORIES=	mail www
MASTER_SITES=	http://pear.php.net/get/
PKGNAMEPREFIX=	pear-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PEAR

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR classes to create and decode MIME messages

BUILD_DEPENDS=	automake:${PORTSDIR}/devel/automake			\
		autoconf:${PORTSDIR}/devel/autoconf213			\
		${LOCALBASE}/bin/phpize:${PORTSDIR}/www/mod_php4	\
		${PEARDIR}/PEAR.php.dist:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${PEARDIR}/PEAR.php.dist:${PORTSDIR}/devel/pear-PEAR

.include <bsd.port.pre.mk>

# Don't call autoconf directly, ./buildconf does this
GNU_CONFIGURE=	yes
USE_AUTOCONF=	no
USE_LIBTOOL=	no
USE_REINPLACE=	yes

REINPLACE_ARGS=	-i.before_mailparse

.if exists(${LOCALBASE}/bin/php-config)
PHP_BASE!=	${LOCALBASE}/bin/php-config --prefix
EXT_DIR!=	${LOCALBASE}/bin/php-config --extension-dir | ${SED} -e \
			"s:${PHP_BASE}/::"
.else
PHP_BASE!=	${LOCALBASE}
.endif
PEAR=		${LOCALBASE}/bin/pear
LPHP_LIB=	lib/php
PHP_DIR?=	${LOCALBASE}/etc
PHP_INI=	${PHP_DIR}/php.ini
PEARDIR=	${PHP_BASE}/${LPHP_LIB}
PLIST_SUB=	EXTDIR=${EXT_DIR} PEARDIR=${LPHP_LIB}

DOCSDIR=	${PEARDIR}/docs/${PORTNAME}
DOCS=		CREDITS README try.php
TESTDIR=	${PEARDIR}/tests/${PORTNAME}

post-patch:
	(cd ${WRKSRC} && ${LOCALBASE}/bin/phpize)

pre-configure:
	@if ! ${LOCALBASE}/bin/php -i | ${GREP} -q -e "--enable-mbstring"; then \
	    ${ECHO_MSG} "" ; \
	    ${ECHO_MSG} "Please configure PHP with mbstring support." ; \
	    ${ECHO_MSG} "" ; \
	    ${FALSE} ; \
	fi

post-install:
	@${STRIP_CMD} ${PHP_BASE}/${EXT_DIR}/mailparse.so
# Configure extension_dir
	@if [ ! -f ${PHP_INI} ]; then \
		${ECHO_MSG} "===>   Creating ${PHP_INI} for PHP" ; \
		${CP} -p ${PHP_INI}-dist ${PHP_INI} ; \
	fi
	@if ${GREP} -q -e '^extension_dir = ./' ${PHP_INI} ; then \
		${ECHO_MSG} "===>   Configuring ${PHP_INI}" ; \
		${REINPLACE_CMD} -e 's!^extension_dir = ./!extension_dir = ${PHP_BASE}/${EXT_DIR}!' \
			${PHP_INI} ; \
	fi
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
	@${MKDIR} ${TESTDIR}
	@${CP} -Rp ${WRKSRC}/tests ${TESTDIR}
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${TESTDIR}
	@${ECHO_MSG} "===> Examples installed in ${TESTDIR}."
.endif
# Register a new package
	@${PEAR} install -r -f ${WRKDIR}/package.xml

.include <bsd.port.post.mk>
