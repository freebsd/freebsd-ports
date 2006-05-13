# New ports collection makefile for:	mod_python
# Date created:				28 August 2000
# Whom:					Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	mod_python
PORTVERSION=	3.2.8
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_APACHE_HTTPD}
MASTER_SITE_SUBDIR=	modpython
EXTRACT_SUFX=	.tgz

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Apache module that embeds the Python interpreter within the server

USE_APACHE=	2.0+
USE_PYTHON=	2.3+

LATEST_LINK=	mod_python3
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-apxs="${APXS}" --with-python="${PYTHON_CMD}" \
		--without-flex
MAKE_ENV=	EXPR_COMPAT=yes

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
