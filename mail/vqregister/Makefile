# New ports collection makefile for:  vqregister
# Date created:        2003-11-15
# Whom:                Dan Caescu <daniel@freebsd.ro>
#
# $FreeBSD$
#

PORTNAME=	vqregister
PORTVERSION=	2.6
CATEGORIES=	mail www
MASTER_SITES=	http://www.inter7.com/vqregister/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An extremely admin-configurable email user signup CGI

BUILD_DEPENDS=	${VPOPMAIL_DIR}:${PORTSDIR}/mail/vpopmail
RUN_DEPENDS=	${VPOPMAIL_DIR}:${PORTSDIR}/mail/vpopmail \
		${WWW_DIR}:${PORTSDIR}/www/apache13

VPOPMAIL_DIR?=	${LOCALBASE}/vpopmail
WWW_DIR?=	${LOCALBASE}/www

USE_MYSQL=	yes
MAKE_ENV=	VDIR=${VPOPMAIL_DIR} WWW_DIR=${WWW_DIR}
PLIST_SUB=	WWW_DIR=${WWW_DIR}

DOCS=		CONFIG CONTRIBUTORS FORM HISTORY TEMPLATE

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
