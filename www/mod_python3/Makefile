# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	mod_python
PORTVERSION=	3.3.1
PORTREVISION=	3
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_APACHE_HTTPD}
MASTER_SITE_SUBDIR=	modpython
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}
EXTRACT_SUFX=	.tgz

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache module that embeds the Python interpreter within the server


USE_APACHE=	22
USE_PYTHON=	yes

MAKE_ARGS+=	APXS=${APXS}

INSTALLS_EGGINFO=	yes
LATEST_LINK=	mod_python3
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-apxs="${APXS}" --with-python="${PYTHON_CMD}" \
		--without-flex
MAKE_ENV=	EXPR_COMPAT=yes

NO_STAGE=	yes
post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
