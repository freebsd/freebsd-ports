# Created by: Dan Caescu <daniel@freebsd.ro>
# $FreeBSD$

PORTNAME=	vqregister
PORTVERSION=	2.6
PORTREVISION=	3
CATEGORIES=	mail www
MASTER_SITES=	http://www.inter7.com/vqregister/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Admin-configurable email user signup CGI

BUILD_DEPENDS=	vpopmail>0:${PORTSDIR}/mail/vpopmail
RUN_DEPENDS=	vpopmail>0:${PORTSDIR}/mail/vpopmail

USE_APACHE_RUN=	22+
VPOPMAIL_DIR?=	${LOCALBASE}/vpopmail

USE_MYSQL=	yes
MAKE_ENV=	VDIR=${VPOPMAIL_DIR} WWWDIR=${STAGEDIR}${WWWDIR}

NEED_ROOT=	yes

DOCS=		CONFIG CONTRIBUTORS FORM HISTORY TEMPLATE

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
