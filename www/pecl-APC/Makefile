# Ports collection makefile for:  pear-APC
# Date created:			  31 August 2003
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	APC
PORTVERSION=	2.0
CATEGORIES=	www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Alternative PHP Cache

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PHP=	yes
USE_PHPIZE=	yes

CONFIGURE_ARGS=	--enable-apc

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"

.if exists(${LOCALBASE}/bin/php-config)
EXT_DIR!=	${LOCALBASE}/bin/php-config --extension-dir | ${SED} -e \
			"s:${PHP_BASE}/::"
.endif
PHP_DIR?=	${LOCALBASE}/etc
PHP_INI=	${PHP_DIR}/php.ini
PLIST_SUB+=	EXTDIR=${EXT_DIR}
DOCS=		CHANGELOG INSTALL NOTICE

post-install-script:
	@${STRIP_CMD} ${PHP_BASE}/${EXT_DIR}/apc.so
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
.endif
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE} | \
		${SED} -e "s:/usr/local/etc/php.ini:${PHP_INI}:"
	@${ECHO_MSG}

.include <bsd.port.post.mk>
