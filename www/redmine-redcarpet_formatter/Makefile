# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	redcarpet_formatter
PORTVERSION=	2.0.1
DISTVERSIONPREFIX=v
CATEGORIES=	www
PKGNAMEPREFIX=	redmine-

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Redmine plugin to support Markdown

LICENSE=	GPLv2

NO_ARCH=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	alminium
GH_PROJECT=	redmine_redcarpet_formatter

RUN_DEPENDS+=	redmine>=2.0:www/redmine
RUN_DEPENDS+=	rubygem-redcarpet>0:textproc/rubygem-redcarpet

REDMINE_PLUGIN_NAME=	redmine_${PORTNAME}

USE_RUBY=	yes
.if !defined(PLIST)
PLIST=		${WRKDIR}/PLIST
_GEN_PLIST=	YesPlease
.endif

WWWDIR?=	${PREFIX}/www/redmine
WWWDIR_REL=	${WWWDIR:S|^${PREFIX}/||}

.if ${WWWDIR_REL} == ${WWWDIR}
IGNORE=		WWWDIR is not a child of PREFIX (${PREFIX})
.endif

.if !defined(do-build)
do-build: redmine-plugin-plist
	@${DO_NADA}
.endif

redmine-plugin-plist:
.if defined(_GEN_PLIST)
	cd ${WRKSRC} && ${FIND} . -type f | ${GREP} -v '\.orig$$' | ${SED} -e's|^\.|${WWWDIR_REL}/plugins/${REDMINE_PLUGIN_NAME}|' >> ${PLIST}
	cd ${WRKSRC} && ${FIND} -d . -empty -type d | ${SED} -e's|^\.|@dir ${WWWDIR_REL}/plugins/${REDMINE_PLUGIN_NAME}|' >> ${PLIST}
.else
	@${DO_NADA}
.endif

post-patch:
	(cd ${WRKSRC}/lib/redmine/wiki_formatting && ${MV} markdown redcarpet_markdown)

do-install:
	${MKDIR} "${STAGEDIR}${WWWDIR}/plugins/${REDMINE_PLUGIN_NAME}"
	${TAR} -C "${WRKSRC}" -cf - --exclude '*.orig' . | ${TAR} -C "${STAGEDIR}${WWWDIR}/plugins/${REDMINE_PLUGIN_NAME}" -xf -

.include <bsd.port.mk>
