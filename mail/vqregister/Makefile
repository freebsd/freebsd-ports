# Created by: Dan Caescu <daniel@freebsd.ro>
# $FreeBSD$

PORTNAME=	vqregister
PORTVERSION=	2.6
PORTREVISION=	3
CATEGORIES=	mail www
MASTER_SITES=	http://www.inter7.com/vqregister/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An extremely admin-configurable email user signup CGI

BUILD_DEPENDS=	${VPOPMAIL_DIR}:${PORTSDIR}/mail/vpopmail
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_APACHE_RUN=	22+
VPOPMAIL_DIR?=	${LOCALBASE}/vpopmail

USE_MYSQL=	yes
NO_STAGE=	yes
MAKE_ENV=	VDIR=${VPOPMAIL_DIR} WWWDIR=${WWWDIR}

DOCS=		CONFIG CONTRIBUTORS FORM HISTORY TEMPLATE

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
