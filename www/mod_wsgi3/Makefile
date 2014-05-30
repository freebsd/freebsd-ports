# $FreeBSD$

PORTNAME=	mod_wsgi
PORTVERSION=	3.5
CATEGORIES=	www python
MASTER_SITES=	http://github.com/GrahamDumpleton/${PORTNAME}/archive/${PORTVERSION}.tar.gz?dummy=/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}
PKGNAMESUFFIX=	3

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	Python WSGI adapter module for Apache

LICENSE=	APACHE20

CONFLICTS_INSTALL=${PKGNAMEPREFIX}mod_wsgi2.* mod_wsgi2.* \
		${PKGNAMEPREFIX}mod_wsgi-2.* mod_wsgi-2.*

PROJECTHOST=	modwsgi

USE_APACHE=	22+
USE_PYTHON=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-apxs="${APXS}" --with-python="${PYTHON_CMD}"

SUB_FILES=	pkg-message

pre-everything::
	@${ECHO_MSG} "======================= ATTENTION! ======================"
	@${ECHO_MSG}
	@${ECHO_MSG} "If you want to use daemon mode you will need to make sure"
	@${ECHO_MSG} "Apache and APR include thread support."
	@${ECHO_MSG}
	@${ECHO_MSG} "========================================================="

.include <bsd.port.mk>
