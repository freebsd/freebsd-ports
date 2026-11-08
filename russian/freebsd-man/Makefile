PORTNAME=	freebsd-man
PORTVERSION=	20261008
CATEGORIES=	russian docs

MAINTAINER=	vladlen@FreeBSD.org
COMMENT=	Russian translations of FreeBSD manual pages
WWW=		https://github.com/freebsd-doc-ru/freebsd-man-ru

LICENSE=	BSD2CLAUSE

FLAVORS=	current 15_0 15_1 15_2 stable15
FLAVOR?=	${FLAVORS:[1]}

.for f in ${FLAVORS}
${f}_PKGNAMESUFFIX=	-${f}
.endfor

USE_GITHUB=	nodefault
GH_TUPLE=	freebsd-doc-ru:freebsd-man-ru:${${FLAVOR}_GH_TAGNAME}:${FLAVOR}/

WRKSRC=		${WRKDIR}/${PORTNAME}-ru-${${FLAVOR}_GH_TAGNAME:S/\//-/}

NO_BUILD=	yes
NO_ARCH=	yes
SUB_FILES=	pkg-message
SUB_LIST=	MANPREFIX=${MANPREFIX}

MANPREFIX=	${PREFIX}/share/man/${MANLANG}
MANLANG=	ru.UTF-8
MANCATS=	man1 man8

current_GH_TAGNAME=	ru_main-3
15_0_GH_TAGNAME=	ru_releng/15.0-3
15_1_GH_TAGNAME=	ru_releng/15.1-3
15_2_GH_TAGNAME=	ru_releng/15.2-3
stable15_GH_TAGNAME=	ru_stable/15-3

.ifmake makesum
.for f in ${FLAVORS}
USE_GITHUB=	nodefault
GH_TUPLE+=	freebsd-doc-ru:freebsd-man-ru:${${f}_GH_TAGNAME}:${f}/
.endfor
.endif

do-install:
.for cat in ${MANCATS}
	${MKDIR} ${STAGEDIR}${MANPREFIX}/${cat}
	cd ${WRKSRC}/man/${cat} && \
	    ${INSTALL_MAN} * ${STAGEDIR}${MANPREFIX}/${cat}
.endfor

post-install:
	@${FIND} -P ${STAGEDIR}${MANPREFIX} -type f ! -name '*.gz' 2>/dev/null | \
		${SED} -ne 's,^${STAGEDIR},,' -ne 's,$$,&.gz,p' >> ${TMPPLIST}

.include <bsd.port.mk>
