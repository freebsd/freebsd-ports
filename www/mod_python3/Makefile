# New ports collection makefile for:	mod_python
# Date created:				28 August 2000
# Whom:					Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	mod_python
PORTVERSION=	3.1.4
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_APACHE_HTTPD}
MASTER_SITE_SUBDIR=	modpython
EXTRACT_SUFX=	.tgz

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Apache module that embeds the Python interpreter within the server

WITH_APACHE2=	yes
USE_APACHE=	yes
USE_PYTHON=	2.3+

LATEST_LINK=	mod_python3
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
CONFIGURE_ARGS+=--with-apxs="${APXS}" --with-python="${PYTHON_CMD}"
MAKE_ENV=	EXPR_COMPAT=yes

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e 's,LONG_LONG,long long,g' ${WRKSRC}/src/requestobject.c

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
