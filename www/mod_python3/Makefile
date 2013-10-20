# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	mod_python
PORTVERSION=	3.3.1
PORTREVISION=	4
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_APACHE_HTTPD}
MASTER_SITE_SUBDIR=	modpython
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}
EXTRACT_SUFX=	.tgz

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache module that embeds the Python interpreter within the server

USE_APACHE=	22
USE_PYTHON=	yes

INSTALLS_EGGINFO=	yes
LATEST_LINK=		mod_python3

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-apxs="${APXS}"		\
			--with-python="${PYTHON_CMD}"	\
			--without-flex

LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ARGS+=	APXS=${APXS}
MAKE_ENV=	EXPR_COMPAT=yes

NO_STAGE=	yes
post-install:
	@${CAT} ${PKGMESSAGE}

# You need to install apache & mod_python before you run this
regression-test: build
	@cd ${WRKSRC} && ${MAKE} check

.include <bsd.port.mk>
