PORTNAME=	itop
PORTVERSION=	2.6.1
CATEGORIES=	www
MASTER_SITES=	SF
DISTNAME=	iTop-${PORTVERSION}-4463

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple, web based IT Service Management tool

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKDIR}/LICENSE

RUN_DEPENDS=	${LOCALBASE}/bin/dot:graphics/graphviz

USES=		cpe shebangfix php zip
SHEBANG_FILES=	lib/tcpdf/tools/tcpdf_addfont.php setup/install/install.sh

CPE_VENDOR=	combodo
USE_PHP=	ctype gd iconv mbstring pcre session xml zlib readline \
		dom simplexml hash json soap mcrypt filter zip

WRKSRC=		${WRKDIR}/web
NO_BUILD=	yes

ITOPDIR=	${WWWDIR}/${PORTNAME}
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	MYSQL PGSQL LDAP
OPTIONS_DEFAULT=MYSQL

MYSQL_USES=	mysql
MYSQL_USE=	PHP=mysqli
PGSQL_USE=	PHP=pgsql
LDAP_USE=	PHP=ldap

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	${CP} -a ${WRKDIR}/web/ ${STAGEDIR}${WWWDIR}

post-install:
	@${ECHO_CMD} "@owner ${WWWOWN}" >> ${TMPPLIST}
	@${ECHO_CMD} "@group ${WWWGRP}" >> ${TMPPLIST}
	@${FIND} -s ${STAGEDIR}${WWWDIR} -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}
	@${ECHO} @dir ${WWWDIR} >> ${TMPPLIST}
	@${ECHO_CMD} "@group" >> ${TMPPLIST}
	@${ECHO_CMD} "@owner" >> ${TMPPLIST}

.include <bsd.port.mk>
