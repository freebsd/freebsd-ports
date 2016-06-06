# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	thunderbird-i18n
PORTVERSION=	45.1.1
CATEGORIES=	mail news net-im
MASTER_SITES=	MOZILLA/${PORTNAME:S|-i18n||}/releases/${DISTVERSION}/linux-i686/xpi \
		MOZILLA/${PORTNAME:S|-i18n||}/candidates/${DISTVERSION}-candidates/build1/linux-i686/xpi
PKGNAMEPREFIX=
DISTFILES=	${THUNDERBIRD_I18N_:S/$/.xpi/}
DIST_SUBDIR=	xpi/${DISTNAME}

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Localized interface for Thunderbird

USES=		gecko:thunderbird,build zip
USE_XPI=	thunderbird

NO_BUILD=	yes
NO_ARCH=	yes
USE_SUBMAKE=	yes

WDIR=	langpack-*@thunderbird.mozilla.org

XPI_DISTNAMES=	${THUNDERBIRD_I18N_}

PLIST?=		${WRKDIR}/plist
PLISTF?=	${WRKDIR}/plist_files

.include "${.CURDIR}/Makefile.option"
.include <bsd.port.pre.mk>

.ifndef WITHOUT_SWITCHER
RUN_DEPENDS+=	xpi-quick-locale-switcher>=0:www/xpi-quick-locale-switcher
.endif

.include "${.CURDIR}/Makefile.lang"

THUNDERBIRD_I18N_?=	${THUNDERBIRD_I18N}

.for dist in ${XPI_DISTNAMES}
XPI_ID_${dist}=		langpack-${dist}@thunderbird.mozilla.org
.endfor

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR} ${WRKSRC}
	@for lang in ${THUNDERBIRD_I18N_}; do \
		if ! (${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/$$lang.xpi -d ${WRKSRC}/langpack-$$lang@thunderbird.mozilla.org);\
		then \
			exit 1; \
		fi; \
		cd ${WRKSRC}/langpack-$$lang@thunderbird.mozilla.org/; \
		${FIND} -H -s * ! -type d | \
		${SED} -e "s|^|lib/xpi/langpack-$$lang@thunderbird.mozilla.org/|" >> ${PLISTF}; \
	done
	${CAT} ${PLISTF} | ${SORT} >> ${PLIST}


do-install:
	@${MKDIR} ${STAGEDIR}${XPI_LIBDIR} ${XPI_SLDIRS_ALL:S,^,${STAGEDIR},}
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
	@${ECHO_CMD} '@unexec for _dir in ${XPI_LINKFARMS} ${XPI_LIBDIR}; { ${RM} -f $$_dir/${WDIR} ; }' ${_A}

post-patch:
	${FIND} ${WRKSRC} -name install.rdf -print0 | \
		${XARGS} -0L1 ${REINPLACE_CMD} -i '' -e '/<?xml/,$$!d'

list-langs:
	@fetch -qo- "https://ftp.mozilla.org/pub/mozilla.org/${PORTNAME:S|-i18n||}/releases/${PORTVERSION}/linux-i686/xpi"|\
		${PERL} -ne 'if(/.*href="([a-zA-Z-]+).xpi.*/){print "$$1\n"}' |\
		${AWK} 'BEGIN{ORS=" "}{print $$1}END{printf "\nNumber of languages: %d\n",NR}'

.include "${.CURDIR}/../../www/xpi-adblock/Makefile.xpi"

.include <bsd.port.post.mk>
