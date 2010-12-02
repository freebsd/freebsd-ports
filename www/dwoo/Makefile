# New ports collection makefile for:	dwoo
# Date created:		2010-10-26
# Whom:			Joe Horn <joehorn@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	dwoo
PORTVERSION=	1.1.1
CATEGORIES=	www
MASTER_SITES=	http://dwoo.org/upload/code/
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.gz
.if !defined(NOPORTDOCS)
DISTFILES+=	${PORTNAME}-${PORTVERSION}-docs.tar.gz
.endif

MAINTAINER=	joehorn@gmail.com
COMMENT=	Dwoo is a PHP5 template engine

WRKSRC=		${WRKDIR}/${PORTNAME}

NO_BUILD=	yes
USE_PHP=	pcre
WANT_PHP_WEB=	yes

DEFAULT_PHP_VER=5
IGNORE_WITH_PHP=4

SUB_FILES=	pkg-message

do-install:
	@${MKDIR} ${DATADIR}
	@cd ${WRKSRC}; ${FIND} . -type d \
		-exec ${MKDIR} ${DATADIR}/{} \;
	@cd ${WRKSRC}; ${FIND} . -type f \
		-exec ${INSTALL_DATA} ${WRKSRC}/{} ${DATADIR}/{} \;
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKDIR}/docs; ${FIND} . -type d \
		-exec ${MKDIR} ${DOCSDIR}/{} \;
	@cd ${WRKDIR}/docs; ${FIND} . -type f \
		-exec ${INSTALL_DATA} ${WRKDIR}/docs/{} ${DOCSDIR}/{} \;
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
