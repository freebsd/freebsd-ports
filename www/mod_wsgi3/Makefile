# New ports collection makefile for:	mod_wsgi
# Date created:				07 April 2008
# Whom:					Douglas Thrift
#
# $FreeBSD$
#

PORTNAME=	mod_wsgi
PORTVERSION=	3.1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE} \
		http://apt.douglasthrift.net/files/${PORTNAME}/ \
		http://code.douglasthrift.net/files/${PORTNAME}/

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	Python WSGI adapter module for Apache

MAKE_JOBS_SAFE=	yes

#LATEST_LINK=	mod_wsgi
CONFLICTS=	mod_wsgi-2.*

PROJECTHOST=	modwsgi

USE_APACHE=	1.3+
USE_PYTHON=	2.3+

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-apxs="${APXS}" --with-python="${PYTHON_CMD}"

SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 300 && ${PYTHON_REL} < 310
IGNORE=		is unsupported with Python 3.0
.endif

post-install:
	@${APXS} -e -a -n "${SHORTMODNAME}" "${APACHEMODDIR}/${MODULENAME}.so"
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
