# $FreeBSD$

PORTNAME=	mod_wsgi
PORTVERSION=	3.4
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}
PKGNAMESUFFIX=	3

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	Python WSGI adapter module for Apache

LICENSE=	AL2

CONFLICTS=	${PKGNAMEPREFIX}mod_wsgi2.* mod_wsgi2.* \
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

post-install:
	@${APXS} -e -a -n "${SHORTMODNAME}" "${APACHEMODDIR}/${MODULENAME}.so"

.include <bsd.port.mk>
