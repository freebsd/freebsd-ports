# Created by: Fumiyuki Shimizu <fumifumi@abacustech.jp>
# $FreeBSD$

PORTNAME=	pivotx
PORTVERSION=	2.3.11
CATEGORIES=	www
MASTER_SITES=	http://pivotx.net/files/ \
		http://pivotx.net/files/archived/
DISTNAME=	pivotx_${PORTVERSION}

MAINTAINER=	fumifumi@abacustech.jp
COMMENT=	Software to help you maintain dynamic sites such as weblogs

LICENSE=	GPLv2

BROKEN_powerpc64=	Does not build

PORTDOCS=	LICENSE.txt README.txt
PORTEXAMPLES=	example.htaccess example.web.config

# Requirements:
# http://book.pivotx.net/index.php?page=app-e#anchor-determining-if-your-server-meets-pivotxs-requirements

OPTIONS_DEFINE=	MYSQL PHPDOM DOCS EXAMPLES
MYSQL_DESC=	Use MySQL instead of flat files
PHPDOM_DESC=	Use PHP:DOM instead of SimpleXML

.include <bsd.port.options.mk>

WANT_PHP_WEB=	yes
USE_PHP=	session gettext xml tokenizer gd pcre
USES+=		cpe tar:tgz

.if ${PORT_OPTIONS:MPHPDOM}
USE_PHP+=	dom
.else
USE_PHP+=	simplexml
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	client
USE_PHP+=	mysql
.endif

NO_BUILD=	YES

TEMP_WRKSRC=	${WRKDIR}/.temp-${PORTNAME}-${PORTVERSION}-${PORTREVISION}
TEMP_DIFF=	${WRKDIR}/.temp-diff-${PORTNAME}-${PORTVERSION}-${PORTREVISION}

BLOGURL=	${PORTNAME}
.if defined(BLOGDIR)
# Relative to ${PREFIX}
WWWDIR=		${PREFIX}/${BLOGDIR}
.endif

SUB_FILES=	pkg-message
SUB_LIST=	BLOGURL=${BLOGURL}

# http://book.pivotx.net/page/1-2#anchor-setting-the-file-rights
WRITABLEDIRS=		images pivotx/templates pivotx/db
USEREDITABLEDIRS=	pivotx/templates

post-extract:
	@if ${TEST} -e '${TEMP_WRKSRC}'; then ${RM} -r '${TEMP_WRKSRC}'; fi
	@${MKDIR} '${TEMP_WRKSRC}'
	@${MV} '${WRKDIR}/'* '${TEMP_WRKSRC}'
	@${MV} '${TEMP_WRKSRC}' '${WRKSRC}'
	@${MKDIR} '${TEMP_WRKSRC}'
.for FILES in ${PORTDOCS}
	@${MV} '${WRKSRC}/${FILES}' '${TEMP_WRKSRC}'
.endfor

post-patch:
.for FILES in ${PORTEXAMPLES}
	@${SED} -e 's#%%BLOGURL%%#${BLOGURL}#g' '${WRKSRC}/${FILES}' >'${TEMP_WRKSRC}/${FILES}'
	@${RM} -f '${WRKSRC}/${FILES}'
.endfor
	@cd '${WRKSRC}' && ${FIND} . -type f -name '*.orig' -delete

do-install:
	@${MKDIR} '${STAGEDIR}${DOCSDIR}'
.for FILES in ${PORTDOCS}
	${INSTALL_DATA} '${TEMP_WRKSRC}/${FILES}' '${STAGEDIR}${DOCSDIR}'
.endfor
	@${MKDIR} '${STAGEDIR}${EXAMPLESDIR}'
.for FILES in ${PORTEXAMPLES}
	${INSTALL_DATA} '${TEMP_WRKSRC}/${FILES}' '${STAGEDIR}${EXAMPLESDIR}'
.endfor
	@${MKDIR} '${STAGEDIR}${WWWDIR}'
	@cd '${WRKSRC}' && ${COPYTREE_SHARE} . '${STAGEDIR}${WWWDIR}'
.for DIR in ${WRITABLEDIRS}
	@${FIND} '${STAGEDIR}${WWWDIR}/${DIR}' -type d -print0 | ${XARGS} -0 ${CHMOD} u=rwx,go=rx
	@${FIND} '${STAGEDIR}${WWWDIR}/${DIR}' -type f -print0 | ${XARGS} -0 ${CHMOD} u=rw,go=r
.endfor

.include <bsd.port.mk>
