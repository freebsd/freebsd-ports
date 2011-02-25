# New ports collection makefile for:	mod_wsgi
# Date created:				07 April 2008
# Whom:					Douglas Thrift
#
# $FreeBSD$
#

PORTNAME=	mod_wsgi
PORTVERSION=	2.8
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE} \
		http://apt.douglasthrift.net/files/${PORTNAME}/ \
		http://code.douglasthrift.net/files/${PORTNAME}/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	Python WSGI adapter module for Apache

LICENSE=	ASL

MAKE_JOBS_SAFE=	yes

LATEST_LINK=	mod_wsgi2
CONFLICTS=	${PKGNAMEPREFIX}mod_wsgi-3.* mod_wsgi-3.*

PROJECTHOST=	modwsgi

USE_APACHE=	1.3+
USE_PYTHON=	2.5-2.7

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-apxs="${APXS}" --with-python="${PYTHON_CMD}"

SUB_FILES=	pkg-message

PORTSCOUT=	limit:^2\.

pre-everything::
	@${ECHO_MSG} "======================= ATTENTION! ======================"
	@${ECHO_MSG}
	@${ECHO_MSG} "If you want to use daemon mode you will need to make sure"
	@${ECHO_MSG} "Apache and APR include thread support."
	@${ECHO_MSG}
	@${ECHO_MSG} "========================================================="

post-install:
	@${APXS} -e -a -n "${SHORTMODNAME}" "${APACHEMODDIR}/${MODULENAME}.so"
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
