# Ports collection makefile for:  pear-mailparse
# Date created:			  09 January 2003
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	mailparse
PORTVERSION=	0.9.4
CATEGORIES=	mail www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR classes to create and decode MIME messages

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR

IS_INTERACTIVE=	'need to build php4 with mbstring support.'

USE_PHP=	yes
USE_PHPIZE=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"

.if exists(${LOCALBASE}/bin/php-config)
EXT_DIR!=	${LOCALBASE}/bin/php-config --extension-dir | ${SED} -e \
			"s:${PHP_BASE}/::"
.endif
PHP_DIR?=	${LOCALBASE}/etc
PHP_INI=	${PHP_DIR}/php.ini
PLIST_SUB+=	EXTDIR=${EXT_DIR}

DOCSDIR=	${PEARDIR}/docs/${PORTNAME}
DOCS=		CREDITS README try.php
TESTDIR=	${PEARDIR}/tests/${PORTNAME}

pre-configure:
	@if ! ${LOCALBASE}/bin/php -i | ${GREP} -q -e "--enable-mbstring"; then \
	    ${ECHO_MSG} "" ; \
	    ${ECHO_MSG} "Please configure PHP with mbstring support." ; \
	    ${ECHO_MSG} "" ; \
	    ${FALSE} ; \
	fi

post-install-script:
	@${STRIP_CMD} ${PHP_BASE}/${EXT_DIR}/mailparse.so
# Configure extension_dir
	@if [ ! -f ${PHP_INI} ]; then \
		${ECHO_MSG} "===>   Creating ${PHP_INI} for PHP" ; \
		${CP} -p ${PHP_INI}-dist ${PHP_INI} ; \
	fi
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
	@${MKDIR} ${TESTDIR}
	@${CP} -Rp ${WRKSRC}/tests/* ${TESTDIR}
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${TESTDIR}
	@${ECHO_MSG} "===> Examples installed in ${TESTDIR}."
.endif
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE} | \
	${SED} -e "s:/usr/local/etc/php.ini:${PHP_INI}:"	\
		-e "s:/usr/local/lib/php/20020429:${PHP_BASE}/${EXT_DIR}:"
	@${ECHO_MSG}

.include <bsd.port.post.mk>
