# New ports collection makefile for:	instiki
# Date created:				4 January 2005
# Whom:					Kelley Reynolds <kelley@insidesystems.net>
#
# $FreeBSD$
#

PORTNAME=	instiki
PORTVERSION=	0.18.1
CATEGORIES=	www ruby
MASTER_SITES=	LOCAL/wen
DISTNAME=	parasew-instiki-0.18.1-0-g6a5b0e1

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Easy to set up wiki clone implemented in ruby

LIB_DEPENDS=	sqlite3:${PORTSDIR}/databases/sqlite3
RUN_DEPENDS=	${RUBY_PKGNAMEPREFIX}iconv>=0:${PORTSDIR}/converters/ruby-iconv

USE_RUBY=	yes
USE_RAKE=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/parasew-instiki-6a5b0e1
INSTIKIPORT?=	2500
INSTIKIDIR?=	www/instiki
INSTIKILOGDIR=	${INSTIKIDIR}/log
INSTIKI_DB=	db/production.db.sqlite3
INSTIKI_DB_FILE=	${INSTIKIDIR}/${INSTIKI_DB}

.include <bsd.port.pre.mk>

USE_RC_SUBR=	${PORTNAME}
PLIST=		${WRKDIR}/plist
SUB_LIST=	INSTIKIPORT=${INSTIKIPORT}
SUB_FILES+=	pkg-message

post-extract:
	${MV} ${WRKSRC}/${INSTIKI_DB} ${WRKSRC}/${INSTIKI_DB}.sample

pre-install:
	${FIND} -s -d ${WRKSRC} -type l | ${SED} "s?${WRKSRC}?${INSTIKIDIR}?g" >>${PLIST}
	${FIND} -s -d ${WRKSRC} -type f | ${SED} "s?${WRKSRC}?${INSTIKIDIR}?g" >>${PLIST}

	@if [ ! -f ${PREFIX}/${INSTIKI_DB_FILE} ]; then \
		${MKDIR} ${PREFIX}/${INSTIKIDIR}/db ; \
		${CP} ${WRKSRC}/${INSTIKI_DB}.sample ${PREFIX}/${INSTIKI_DB_FILE} ; \
		${ECHO_CMD} "${INSTIKI_DB_FILE}" >> ${PLIST} ; \
	fi

	@${ECHO} @dirrm ${INSTIKILOGDIR} >> ${PLIST}
	@${FIND} -s -d ${WRKSRC} -type d  | ${SED} "s?${WRKSRC}?@dirrm ${INSTIKIDIR}?g" >> ${PLIST}

do-install:
	@${INSTALL} -d ${WWWDIR}
	@${CP} -pR ${WRKSRC}/ ${WWWDIR}/

	@${INSTALL} -d ${WWWDIR}/log

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
