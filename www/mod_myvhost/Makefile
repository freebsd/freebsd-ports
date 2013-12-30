# Created by: Olli Hauer <ohauer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mod_myvhost
PORTVERSION=	0.21
CATEGORIES=	www
MASTER_SITES=	http://mod-myvhost.googlecode.com/files/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache module for dynamically configured mass virtual hosting with php

LICENSE=	APACHE20

MANUAL_PACKAGE_BUILD=	needs apr and apache with DBD options enabled


USE_APACHE=	22+
UNIQUENAME=	${PORTNAME}

PORTDOCS=	changelog.html documentation.html download.html \
		index.html my.css
PORTEXAMPLES=	vhosts.sql httpd.conf.add

OPTIONS_DEFINE=		PHP_MODULE DEBUG_MODULE PHP DEBUG
OPTIONS_DEFAULT=	PHP_MODULE

PHP_MODULE_DESC=	Enable PHP
DEBUG_MODULE_DESC=	Enable debugging

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG_MODULE}
MAKE_ENV+=	WITH_DEBUG=true
STRIP=		# keep debug information
.endif

.if ${PORT_OPTIONS:MPHP_MODULE}
MAKE_ENV+=	WITH_PHP=true
USE_PHP=	yes
USE_PHP_MOD=	yes
.endif

.include <bsd.port.pre.mk>

pre-patch:
	@${REINPLACE_CMD} -e "s|= apxs|= ${APXS}|" \
		-e "s|= rm|= ${RM}|" -e "s|= ln|= ${LN}|" \
		-e "s|= cp|= ${CP}|" ${WRKSRC}/Makefile

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTEXAMPLES} ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
