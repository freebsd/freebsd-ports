# Created by: clsung
# $FreeBSD$

PORTNAME=	lifetype
PORTVERSION=	1.2.11
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
DISTFILES=	${DISTNAME}.zip \
		${CONTRIBE_VERSION}__all_plugins.zip \
		${CONTRIBE_VERSION}__all_templates.zip
EXTRACT_ONLY=	${DISTNAME}.zip

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	PHP and MySQL based blogging platform

LICENSE=	GPLv2

IGNOREFILES=	${CONTRIBE_VERSION}__all_plugins.zip \
		${CONTRIBE_VERSION}__all_templates.zip

CONTRIBE_VERSION=1.2
NO_BUILD=	YES
NO_MTREE=	YES
PLOGDIR?=	${WWWDOCROOT}/${PLOGURL}
PLOGURL?=	lifetype
USE_PHP=	ctype mysql pcre session xml tokenizer
USES=		zip
WANT_PHP_WEB=	YES
WWWDOCROOT?=	www
SUB_FILES=	pkg-message
SUB_LIST=	PLOGURL=${PLOGURL}

OPTIONS_DEFINE=	GD BIG5
OPTIONS_DEFAULT=GD
BIG5_DESC=	Big5 chinese template fix

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGD}
USE_PHP+=	gd
RUN_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/gd.so:${PORTSDIR}/${gd_DEPENDS}
.endif

.if ! ${PORT_OPTIONS:MGD}
pre-patch:
	@${ECHO_CMD} "Without GD support, no thumbnails will be generated."
.endif

post-extract:
.for x in plugins templates
	cd ${WRKSRC}/${x} && ${TAR} -xf ${DISTDIR}/${CONTRIBE_VERSION}__all_${x}.zip
.endfor

.if ${PORT_OPTIONS:MBIG5}
post-patch:
	${FIND} ${WRKSRC}/templates -name "*.template" | \
		${XARGS} ${REINPLACE_CMD} -e 's/|capitalize//g' -e 's/%b/%B/g'
	${FIND} ${WRKSRC}/templates -name "*.template.bak" -delete
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${PLOGDIR}
	@${CP} -R ${WRKSRC}/ ${STAGEDIR}${PREFIX}/${PLOGDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${STAGEDIR}${PREFIX}/${PLOGDIR}

post-install:
	@cd ${STAGEDIR}${PREFIX}; ${FIND} * \( -type f -or -type l \) | \
	   ${SORT} >> ${TMPPLIST}
	@cd ${STAGEDIR}${PREFIX}; ${FIND} * -type d | ${AWK} '/\//' | ${SORT} -r | \
	   ${SED} -e 's/^/@dirrm /g' >> ${TMPPLIST}

.include <bsd.port.mk>
