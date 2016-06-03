# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	firefox
PORTVERSION=	45.2.0
CATEGORIES=	www
MASTER_SITES=	MOZILLA/${PORTNAME:S|-i18n||}/releases/${DISTVERSION}esr/linux-i686/xpi \
		MOZILLA/${PORTNAME:S|-i18n||}/candidates/${DISTVERSION}esr-candidates/build2/linux-i686/xpi
PKGNAMEPREFIX=
PKGNAMESUFFIX=	-esr-i18n
DISTFILES=	${FIREFOX_I18N_:S/$/.xpi/}
DIST_SUBDIR=	xpi/${DISTNAME}

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Localized interface for Firefox

EXTRACT_DEPENDS=	zip:archivers/zip

USES=		zip:infozip gecko:firefox,build
USE_XPI=	firefox linux-firefox

NO_ARCH=	yes
USE_SUBMAKE=	yes

WDIR=	langpack-*@firefox.mozilla.org

XPI_DISTNAMES=	${FIREFOX_I18N_}

PLIST?=		${WRKDIR}/plist
PLISTF?=	${WRKDIR}/plist_files

.include "${.CURDIR}/Makefile.option"
.include <bsd.port.pre.mk>

.ifndef WITHOUT_SWITCHER
RUN_DEPENDS+=	xpi-quick-locale-switcher>=0:www/xpi-quick-locale-switcher
.endif

.include "${.CURDIR}/Makefile.lang"

FIREFOX_I18N_?=	${FIREFOX_I18N}

.for dist in ${XPI_DISTNAMES}
XPI_ID_${dist}=		langpack-${dist}@firefox.mozilla.org
.endfor

pre-everything::
	@${ECHO_CMD}
	@${ECHO_CMD} "Please define FIREFOX_I18N_ALL to install all languages."
	@${ECHO_CMD}

do-extract:
	@${MKDIR} ${WRKSRC}
	@for lang in ${FIREFOX_I18N_}; do \
		if ! (${UNZIP_CMD} -qo ${_DISTDIR}/$$lang.xpi -d ${WRKSRC}/langpack-$$lang@firefox.mozilla.org);\
		then \
			exit 1; \
		fi; \
		cd ${WRKSRC}/langpack-$$lang@firefox.mozilla.org/; \
		${FIND} -H -s * ! -type d | \
		${SED} -e "s|^|lib/xpi/langpack-$$lang@firefox.mozilla.org/|" >> ${PLISTF}; \
	done
	${CAT} ${PLISTF} | ${SORT} >> ${PLIST}

do-install:
	@${MKDIR} ${STAGEDIR}${XPI_LIBDIR}
	cd ${WRKSRC}; ${PAX} -rw . ${STAGEDIR}${XPI_LIBDIR}
	${CHMOD} -R a+rX,go-w ${STAGEDIR}${XPI_LIBDIR}/${WDIR}/
	@for e in ${STAGEDIR}${XPI_LIBDIR}/${WDIR}; do \
		for _dir in ${XPI_LINKFARMS} ; do \
		${LN} -sf $${_e##*/} ${STAGEDIR}$$_dir/ ${_Q} ; \
		done \
	done
	@${ECHO_CMD} '@exec ${INSTALL} -d ${XPI_SLDIRS_ALL:S,^${PREFIX},%D,}' ${_A}
	@${ECHO_CMD} '@exec for _dir in ${XPI_LINKFARMS} ; { \
		${LN} -sf ${XPI_LIBDIR}/${WDIR} $$_dir/ ${_Q}; }' ${_A}
	@${ECHO_CMD} '@unexec for _dir in ${XPI_LINKFARMS}; { ${RM} -f $$_dir/${WDIR} ; }' ${_A}

post-patch:
	${FIND} ${WRKSRC} -name install.rdf -print0 | \
		${XARGS} -0L1 ${REINPLACE_CMD} -i '' -e '/<?xml/,$$!d'

list-langs:
	@fetch -qo- "https://ftp.mozilla.org/pub/mozilla.org/${PORTNAME:S|-i18n||}/releases/${PORTVERSION}esr/linux-i686/xpi"|\
		${PERL} -ne 'if(/.*href="([a-zA-Z-]+).xpi.*/){print "$$1\n"}' |\
		${AWK} 'BEGIN{ORS=" "}{print $$1}END{printf "\nNumber of languages: %d\n",NR}'

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"

.include <bsd.port.post.mk>
