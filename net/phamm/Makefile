# Created by: Gustavo Fukao <gustavofukao@gmail.com>
# $FreeBSD$

PORTNAME=	phamm
PORTVERSION=	0.5.18
PORTREVISION=	1
CATEGORIES=	net www
MASTER_SITES=	http://open.rhx.it/phamm/

MAINTAINER=	gustavofukao@gmail.com
COMMENT=	Front-end written in PHP to manage virtual service

BROKEN=		unfetchable

NO_BUILD=	yes
USE_PHP=	gettext ldap openssl pcre session

USES=		gettext shebangfix
SHEBANG_FILES=	po/update-all-mo.sh \
		tools/*.sh tools/*.pl \
		tools/ldap-schema-manage
PHAMMDIR?=	www/${PORTNAME}
SCHEMADIR=	${WRKSRC}/schema

SUB_FILES=	pkg-message
SUB_LIST=	PHAMMDIR=${PHAMMDIR} PKGNAME=${PKGNAME}
PLIST_SUB=	PHAMMDIR=${PHAMMDIR}

PORTDOCS=	CHANGELOG INSTALL README LICENSE THANKS

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${PHAMMDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${CP} -Rv ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}
	@${CP} -Rv ${SCHEMADIR} ${STAGEDIR}${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/index.php ${STAGEDIR}${PREFIX}/${PHAMMDIR}
	@for d in `${FIND}  ${WRKSRC} -type d -depth 1 | ${SORT} -r | \
	${EGREP} -v '(examples|cfg|schema|debian|server)'` ; do \
		${CP} -Rv $$d ${STAGEDIR}${PREFIX}/${PHAMMDIR}; \
	done;
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
