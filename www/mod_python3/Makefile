# New ports collection makefile for:	mod_python
# Date created:				28 August 2000
# Whom:					Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	mod_python
PORTVERSION=	3.3.1
PORTREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_APACHE_HTTPD}
MASTER_SITE_SUBDIR=	modpython
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}
EXTRACT_SUFX=	.tgz

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache module that embeds the Python interpreter within the server

MAKE_JOBS_SAFE=  yes

USE_APACHE=	2.0+
USE_PYTHON=	yes

INSTALLS_EGGINFO=	yes
LATEST_LINK=	mod_python3
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-apxs="${APXS}" --with-python="${PYTHON_CMD}" \
		--without-flex
MAKE_ENV=	EXPR_COMPAT=yes

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
