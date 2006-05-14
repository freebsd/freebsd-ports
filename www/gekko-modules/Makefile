# New ports collection makefile for:	gekko-modules
# Date created:		2005-12-27
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	gekko-modules
PORTVERSION=	0.6.4
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gekkoware
DISTFILES=	#
DIST_SUBDIR=	gekkoware

MAINTAINER=	acardenas@bsd.org.pe
COMMENT=	Gekko's modules

RUN_DEPENDS=	${LOCALBASE}/www/gekko/conf.php:${PORTSDIR}/www/gekko

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
GEKKODIR?=	www/gekko
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
		MEMOS	"Memos module"	on \
		MESSAGES	"Messages module"	on \
		NEWS	"News module"	on \
		PAGES	"Pages module"	on \
		POLLS	"Polls module"	on \
		SEARCH	"Search module"	on \
		STATISTICS	"Statistics module"	on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_BACKUP)
DISTFILES+=	backup-0.6.module.tgz
PLIST_SUB+=	BACKUP=""
FLAG_MODULE=	true
.else
PLIST_SUB+=	BACKUP="@comment "
.endif

.if !defined(WITHOUT_BLOG)
DISTFILES+=	blog-0.6.3.module.tgz
PLIST_SUB+=	BLOG=""
FLAG_MODULE=	true
.else
PLIST_SUB+=	BLOG="@comment "
.endif

.if !defined(WITHOUT_CATEGORIES)
DISTFILES+=	categories-0.6.2.module.tgz
PLIST_SUB+=	CATEGORIES=""
FLAG_MODULE=	true
.else
PLIST_SUB+=	CATEGORIES="@comment "
.endif

.if !defined(WITHOUT_COMMENTS)
DISTFILES+=	comments-0.6.3.module.tgz
PLIST_SUB+=	COMMENTS=""
FLAG_MODULE=	true
.else
PLIST_SUB+=	COMMENTS="@comment "
.endif

.if !defined(WITHOUT_CONTACT)
DISTFILES+=	contact-0.6.module.tgz
PLIST_SUB+=	CONTACT=""
FLAG_MODULE=	true
.else
PLIST_SUB+=	CONTACT="@comment "
.endif

.if !defined(WITHOUT_DOWNLOADS)
DISTFILES+=	downloads-0.6.2.module.tgz
PLIST_SUB+=	DOWNLOADS=""
FLAG_MODULE=	true
.else
PLIST_SUB+=	DOWNLOADS="@comment "
.endif

.if !defined(WITHOUT_EXTENSIONS)
DISTFILES+=	extensions-0.6.2.module.tgz
PLIST_SUB+=	EXTENSIONS=""
FLAG_MODULE=	true
.else
PLIST_SUB+=	EXTENSIONS="@comment "
.endif

.if !defined(WITHOUT_FILES)
DISTFILES+=	files-0.6.1.module.tgz
PLIST_SUB+=	FILES=""
FLAG_MODULE=	true
.else
PLIST_SUB+=	FILES="@comment "
.endif

.if !defined(WITHOUT_FORUMS)
DISTFILES+=	forums-0.6.3.module.tgz
PLIST_SUB+=	FORUMS=""
FLAG_MODULE=	true
.else
PLIST_SUB+=	FORUMS="@comment "
.endif

.if !defined(WITHOUT_GALLERY)
DISTFILES+=	gallery-0.6.3.module.tgz
PLIST_SUB+=	GALLERY=""
FLAG_MODULE=	true
.else
PLIST_SUB+=	GALLERY="@comment "
.endif

.if !defined(WITHOUT_MEMOS)
DISTFILES+=	memos-0.6.2.module.tgz
PLIST_SUB+=	MEMOS=""
FLAG_MODULE=	true
.else
PLIST_SUB+=	MEMOS="@comment "
.endif

.if !defined(WITHOUT_MESSAGES)
DISTFILES+=	messages-0.6.2.module.tgz
PLIST_SUB+=	MESSAGES=""
FLAG_MODULE=	true
.else
PLIST_SUB+=	MESSAGES="@comment "
.endif

.if !defined(WITHOUT_NEWS)
DISTFILES+=	news-0.6.2.module.tgz
PLIST_SUB+=	NEWS=""
FLAG_MODULE=	true
.else
PLIST_SUB+=	NEWS="@comment "
.endif

.if !defined(WITHOUT_PAGES)
DISTFILES+=	pages-0.6.2.module.tgz
PLIST_SUB+=	PAGES=""
FLAG_MODULE=	true
.else
PLIST_SUB+=	PAGES="@comment "
.endif

.if !defined(WITHOUT_POLLS)
DISTFILES+=	polls-0.6.2.1.module.tgz
PLIST_SUB+=	POLLS=""
FLAG_MODULE=	true
.else
PLIST_SUB+=	POLLS="@comment "
.endif

.if !defined(WITHOUT_SEARCH)
DISTFILES+=	search-0.6.module.tgz
PLIST_SUB+=	SEARCH=""
FLAG_MODULE=	true
.else
PLIST_SUB+=	SEARCH="@comment "
.endif

.if !defined(WITHOUT_STATISTICS)
DISTFILES+=	statistics-0.6.1.module.tgz
PLIST_SUB+=	STATISTICS=""
FLAG_MODULE=	true
.else
PLIST_SUB+=	STATISTICS="@comment "
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

do-install:
.for DIRE in modules templates media
	cd ${WRKSRC}/${DIRE} && \
		${FIND} * -type d -exec ${MKDIR} "${PREFIX}/${GEKKODIR}/${DIRE}/{}" \; && \
		${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${PREFIX}/${GEKKODIR}/${DIRE}/{}" \;
.endfor
.include <bsd.port.post.mk>
