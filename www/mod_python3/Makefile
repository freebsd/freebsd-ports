# New ports collection makefile for:	mod_python
# Date created:				28 August 2000
# Whom:					Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	mod_python
PORTVERSION=	3.1.3
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_APACHE_HTTPD}
MASTER_SITE_SUBDIR=	modpython
EXTRACT_SUFX=	.tgz

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Apache module that embeds the Python interpreter within the server

WITH_APACHE2=	yes
USE_APACHE=	yes
USE_PYTHON=	yes

LATEST_LINK=	mod_python3
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
CONFIGURE_ARGS+=--with-apxs="${APXS}" --with-python="${PYTHON_CMD}"
MAKE_ENV=	EXPR_COMPAT=yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "amd64"
BROKEN=		"Does not compile on amd64 or ia64"
.endif

.if ${PYTHON_REL} >= 230
post-patch:
	${REINPLACE_CMD} -e 's,LONG_LONG,long long,g' ${WRKSRC}/src/requestobject.c
.endif

.if !exists(${PREFIX}/etc/apache2/envvars.d)
BROKEN=		"Please upgrade your www/apache2 installation."
.endif

post-build:
	THREAD_LIB=`ldd ${PYTHON_CMD} | ${EGREP} '(pthread|c_r)' | ${AWK} '{print $$3}'`; \
	${ECHO_CMD} "LD_PRELOAD=$${THREAD_LIB}" > ${WRKDIR}/mod_python3.env
	${ECHO_CMD} "export LD_PRELOAD" >> ${WRKDIR}/mod_python3.env

post-install:
	${INSTALL_DATA} ${WRKDIR}/mod_python3.env ${PREFIX}/etc/apache2/envvars.d
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
