# Created by: Bartlomiej Rutkowski <r@robakdesign.com>
# $FreeBSD$

PORTNAME=	hastymail2
PORTVERSION=	1.1
PORTREVISION=	5
PORTEPOCH=	1
CATEGORIES=	www mail
MASTER_SITES=	SF/hastymail/Hastymail2%20Stable%20Releases/Hastymail2%201.1/
DISTNAME=	hastymail2_${WIKEDVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small, fast and secure yet powerful IMAP webmail

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

NO_BUILD=	yes
SUB_FILES=	pkg-message

CONFLICTS_INSTALL=	hastymail2-devel-[0-9]*

USES=		php:web
USE_PHP=	ctype pcre session xml

WIKEDVERSION=	1_1
WRKSRC=		${WRKDIR}/${PORTNAME}_${WIKEDVERSION}
NO_BUILD=	yes
FIND_SKIP_OPTS=	-not -name hastymail2.conf.example -not -name '*.orig'
PLIST_SUB=	WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"

OPTIONS_DEFINE=	PGSQL MYSQL DB ICONV MBSTRING

DB_DESC=	Use older pear DB (instead of MDB2)
MBSTRING_DESC=	Support multi-byte character sets

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
.if ! ${PORT_OPTIONS:MDB}
RUN_DEPENDS+=	${LOCALBASE}/share/pear/MDB2/Driver/mysql.php:databases/pear-MDB2_Driver_mysql
.endif
.endif

.if ${PORT_OPTIONS:MPGSQL}
USES+=	pgsql
.if ! ${PORT_OPTIONS:MDB}
RUN_DEPENDS+=	${LOCALBASE}/share/pear/MDB2/Driver/pgsql.php:databases/pear-MDB2_Driver_pgsql
.endif
.endif

.if ${PORT_OPTIONS:MDB} && (${PORT_OPTIONS:MMYSQL} || ${PORT_OPTIONS:MPGSQL})
RUN_DEPENDS+=	${LOCALBASE}/share/pear/DB.php:databases/pear-DB
.endif

.if ${PORT_OPTIONS:MICONV}
USE_PHP+=	iconv
.endif

.if ${PORT_OPTIONS:MMBSTRING}
USE_PHP+=	mbstring
.endif

post-patch:
	@${REINPLACE_CMD} -E "s#/etc/hastymail[2]*/hasty[ma][ma]il2.rc#${PREFIX}/etc/hastymail2/hastymail2.rc#" \
		${WRKSRC}/index.php ${WRKSRC}/hastymail2.conf.example
	@${FIND} ${WRKSRC}/plugins -name config.php | ${XARGS} -I % ${MV} % %.sample

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC} && ${FIND} . ${FIND_SKIP_OPTS} \
		| ${PAX} -rwd ${STAGEDIR}${WWWDIR}
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/hastymail2.conf.example \
		${STAGEDIR}${ETCDIR}/hastymail2.conf.sample

.include <bsd.port.mk>
