# New ports collection makefile for:	Webware
# Date created:		9 July 2002
# Whom:			Stefan Schwarzer <sschwarzer@sschwarzer.net>
#
# $FreeBSD$
#

PORTNAME=	webware
PORTVERSION=	0.8.1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR= webware
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Webware-${PORTVERSION}

MAINTAINER=	sschwarzer@sschwarzer.net
COMMENT=	A versatile web application server written in Python

BUILD_DEPENDS=	${PYTHON_CMD}:${PORTSDIR}/lang/python
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/mx/DateTime:${PORTSDIR}/lang/py-mx-base

USE_PYTHON=	yes
NO_BUILD=	yes

WEBWARE_USER?=	webkit
WEBWARE_GROUP?=	${WEBWARE_USER}
WEBWARE_MASTER_DIR?=${PREFIX}/share/webware
WEBKIT_HOME_DIR?=${PREFIX}/www/webkit
INSTALL_ENV=	PKG_PREFIX=${PREFIX} \
		LOCALBASE=${LOCALBASE} \
		WEBWARE_USER=${WEBWARE_USER} \
		WEBWARE_GROUP=${WEBWARE_GROUP} \
		WEBWARE_MASTER_DIR=${WEBWARE_MASTER_DIR} \
		WEBKIT_HOME_DIR=${WEBKIT_HOME_DIR}

pre-install:
	@ ${ECHO} '---> Making webware default user and its group'
	${SETENV} ${INSTALL_ENV} ${SH} ${PKGINSTALL} ${PORTNAME} PRE-INSTALL

do-install:
	@ ${ECHO} '---> Installing in Webware master dir'
	# ensure the target directory isn't there
	${RM} -rf ${WEBWARE_MASTER_DIR}
	${CP} -R ${WRKSRC} ${WEBWARE_MASTER_DIR}

	@ ${ECHO} '---> Deleting native files (not used by this port)'
	${RM} -rf ${WEBWARE_MASTER_DIR}/WebKit/Native

	@ ${ECHO} '---> Installing start/stop script'
	${SED} -e "s|%%WEBKIT_HOME_DIR%%|${WEBKIT_HOME_DIR}|g" \
		< ${FILESDIR}/webkit.sh.tmpl \
		> ${PREFIX}/etc/rc.d/webkit.sh-dist
	${CHMOD} 755 ${PREFIX}/etc/rc.d/webkit.sh-dist && \
	${CHOWN} root:wheel ${PREFIX}/etc/rc.d/webkit.sh-dist

post-install:
	@ ${ECHO} '---> Compiling Python files and making webkit home directory'
	${SETENV} ${INSTALL_ENV} ${SH} ${PKGINSTALL} ${PORTNAME} POST-INSTALL

.include <bsd.port.mk>
