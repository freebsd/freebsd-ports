# New ports collection makefile for:	mod_python
# Date created:				28 August 2000
# Whom:					Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	mod_python
PORTVERSION=	3.0.3
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_APACHE_HTTPD}
MASTER_SITE_SUBDIR=	modpython
EXTRACT_SUFX=	.tgz

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Apache module that embeds the Python interpreter within the server

BUILD_DEPENDS=	${LOCALBASE}/include/apache2/httpd.h:${PORTSDIR}/www/apache2
RUN_DEPENDS=	${LOCALBASE}/include/apache2/httpd.h:${PORTSDIR}/www/apache2

USE_PYTHON=	yes

APXS?=		${LOCALBASE}/sbin/apxs

GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
CONFIGURE_ARGS+=--with-apxs="${APXS}" --with-python="${PYTHON_CMD}"
MAKE_ENV=	EXPR_COMPAT=yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 230
post-patch:
	${REINPLACE_CMD} -e 's,LONG_LONG,long long,g' ${WRKSRC}/src/requestobject.c
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
