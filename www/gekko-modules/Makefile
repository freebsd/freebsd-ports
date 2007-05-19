# New ports collection makefile for:	gekko-modules
# Date created:		2005-12-27
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	gekko-modules
PORTVERSION=	0.7
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gekkoware
DISTFILES=	#
DIST_SUBDIR=	gekkoware

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Gekko's modules

RUN_DEPENDS=	${LOCALBASE}/www/gekko/conf.php:${PORTSDIR}/www/gekko

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
GEKKODIR=	www/gekko
PLIST=		${WRKDIR}/pkg-plist
PLIST_SUB=	GEKKODIR=${GEKKODIR}

OPTIONS=	BACKUP	"Backup module"	on \
		BLOG	"Blog module"	on \
		CATEGORIES	"Categories module"	on \
		COMMENTS	"Comments module"	on \
		CONTACT	"Contact module"	on \
		DOWNLOADS	"Downlodas module"	on \
		EXTENSIONS	"Extensions module"	on \
		FILES	"Files module"	on \
		FORUMS	"Forums module"	on \
		GALLERY	"Gallery module"	on \
		GLOSSARY	"Glossary module"	on \
		MEMOS	"Memos module"	on \
		MESSAGES	"Messages module"	on \
		NEWS	"News module"	on \
		PAGES	"Pages module"	on \
		POLLS	"Polls module"	on \
		SEARCH	"Search module"	on \
		STATISTICS	"Statistics module"	on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_BACKUP)
DISTFILES+=	backup-0.7.module.tgz
FLAG_MODULE=	true
.endif

.if !defined(WITHOUT_BLOG)
DISTFILES+=	blog-0.7.module.tgz
FLAG_MODULE=	true
.endif

.if !defined(WITHOUT_CATEGORIES)
DISTFILES+=	categories-0.7.module.tgz
FLAG_MODULE=	true
.endif

.if !defined(WITHOUT_COMMENTS)
DISTFILES+=	comments-0.7.module.tgz
FLAG_MODULE=	true
.endif

.if !defined(WITHOUT_CONTACT)
DISTFILES+=	contact-0.7.module.tgz
FLAG_MODULE=	true
.endif

.if !defined(WITHOUT_DOWNLOADS)
DISTFILES+=	downloads-0.7.module.tgz
FLAG_MODULE=	true
.endif

.if !defined(WITHOUT_EXTENSIONS)
DISTFILES+=	extensions-0.7.module.tgz
FLAG_MODULE=	true
.endif

.if !defined(WITHOUT_FILES)
DISTFILES+=	files-0.7.module.tgz
FLAG_MODULE=	true
.endif

.if !defined(WITHOUT_FORUMS)
DISTFILES+=	forums-0.7.module.tgz
FLAG_MODULE=	true
.endif

.if !defined(WITHOUT_GALLERY)
DISTFILES+=	gallery-0.7.module.tgz
FLAG_MODULE=	true
.endif

.if !defined(WITHOUT_GLOSSARY)
DISTFILES+=	glossary-0.7.module.tgz
FLAG_MODULE=	true
.endif

.if !defined(WITHOUT_MEMOS)
DISTFILES+=	memos-0.7.module.tgz
FLAG_MODULE=	true
.endif

.if !defined(WITHOUT_MESSAGES)
DISTFILES+=	messages-0.7.module.tgz
FLAG_MODULE=	true
.endif

.if !defined(WITHOUT_NEWS)
DISTFILES+=	news-0.7.module.tgz
FLAG_MODULE=	true
.endif

.if !defined(WITHOUT_PAGES)
DISTFILES+=	pages-0.7.module.tgz
FLAG_MODULE=	true
.endif

.if !defined(WITHOUT_POLLS)
DISTFILES+=	polls-0.7.module.tgz
FLAG_MODULE=	true
.endif

.if !defined(WITHOUT_SEARCH)
DISTFILES+=	search-0.7.module.tgz
FLAG_MODULE=	true
.endif

.if !defined(WITHOUT_STATISTICS)
DISTFILES+=	statistics-0.7.module.tgz
FLAG_MODULE=	true
.endif

pre-fetch:
.if defined(FLAG_MODULE)
	@${TRUE}
.else
	@${ECHO} "######################"
	@${ECHO} "# No module selected #"
	@${ECHO} "######################"
	@${FALSE}
.endif

pre-install:
	@${RM} -f ${PLIST}
.for DIRE in modules templates media
	@cd ${WRKDIR}/${DIRE} && \
		${FIND} * -type f | ${SORT} | ${SED} -e 's|^|%%GEKKODIR%%/${DIRE}/|' >> ${PLIST} && \
			${FIND} * -type d | ${SORT} -r | ${SED} -e 's|^|@dirrmtry %%GEKKODIR%%/${DIRE}/|' >> ${PLIST}
.endfor
	@${ECHO_CMD} "@dirrmtry %%GEKKODIR%%/templates" >> ${PLIST}
	@${ECHO_CMD} "@dirrmtry %%GEKKODIR%%/modules" >> ${PLIST}
	@${ECHO_CMD} "@dirrmtry %%GEKKODIR%%/media" >> ${PLIST}
	@${ECHO_CMD} "@dirrmtry %%GEKKODIR%%" >> ${PLIST}

do-install:
.for DIRE in modules templates media
	cd ${WRKSRC}/${DIRE} && \
		${FIND} * -type d -exec ${MKDIR} "${PREFIX}/${GEKKODIR}/${DIRE}/{}" \; && \
		${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${PREFIX}/${GEKKODIR}/${DIRE}/{}" \;
.endfor

.include <bsd.port.post.mk>
