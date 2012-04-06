# New ports collection makefile for:	mod_myvhost
# Date created:				2012-03-26
# Whom:					Olli Hauer <ohauer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mod_myvhost
PORTVERSION=	0.21
CATEGORIES=	www
MASTER_SITES=	http://mod-myvhost.googlecode.com/files/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache module for dynamically configured mass virtual hosting with php

LICENSE=	AL2

MANUAL_PACKAGE_BUILD=	needs apr and apache with DBD options enabled

MAKE_JOBS_SAFE=	yes

USE_APACHE=	22+
UNIQUENAME=	${PORTNAME}

PORTDOCS=	changelog.html documentation.html download.html \
		index.html my.css
PORTEXAMPLES=	vhosts.sql httpd.conf.add

OPTIONS=	PHP_MODULE	"Enable PHP"	on \
		DEBUG_MODULE	"Enable debigging"	off

.include <bsd.port.options.mk>

.if defined(WITH_DEBUG_MODULE)
MAKE_ENV+=	WITH_DEBUG=true
STRIP=		# keep debug information
.endif

.if defined(WITH_PHP_MODULE)
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
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTEXAMPLES} ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
