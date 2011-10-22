# New ports collection makefile for:	phamm
# Date created:		2006-02-15
# Whom:			Gustavo Fukao <gustavofukao@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	phamm
PORTVERSION=	0.5.18
CATEGORIES=	net www
MASTER_SITES=	http://open.rhx.it/phamm/

MAINTAINER=	gustavofukao@gmail.com
COMMENT=	Front-end written in PHP to manage virtual service

NO_BUILD=	yes
USE_PHP=	gettext ldap openssl pcre session

USE_GETTEXT=	yes

PHAMMDIR?=	www/${PORTNAME}
SCHEMADIR=	${WRKSRC}/schema

SUB_FILES=	pkg-message
SUB_LIST=	PHAMMDIR=${PHAMMDIR} PKGNAME=${PKGNAME}
PLIST_SUB=	PHAMMDIR=${PHAMMDIR}

PORTDOCS=	CHANGELOG INSTALL README LICENSE THANKS

.include <bsd.port.pre.mk>

do-install:
	@${MKDIR} ${PREFIX}/${PHAMMDIR}
	@${MKDIR} ${EXAMPLESDIR}
	@${CP} -Rv ${WRKSRC}/examples/* ${EXAMPLESDIR}
	@${CP} -Rv ${SCHEMADIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/index.php ${PREFIX}/${PHAMMDIR}
	@for d in `${FIND}  ${WRKSRC} -type d -depth 1 | ${SORT} -r | \
	${EGREP} -v '(examples|cfg|schema|debian|server)'` ; do \
		${CP} -Rv $$d ${PREFIX}/${PHAMMDIR}; \
	done;
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
