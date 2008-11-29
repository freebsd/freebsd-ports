# New ports collection makefile for:	firefox3-i18n
# Date created:		28 May 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	firefox3-i18n
PORTVERSION=	3.0.4
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITE_SUBDIR=	firefox/releases/${PORTVERSION}/linux-i686/xpi
PKGNAMEPREFIX=
DISTFILES=	${FIREFOX_I18N_:S/$/.xpi/}
DIST_SUBDIR=	xpi/${DISTNAME}

MAINTAINER=	yokota@res.otaru-uc.ac.jp
COMMENT=	Localized interface for Firefox3

.ifndef WITHOUT_SWITCHER
RUN_DEPENDS+=	xpi-quick-locale-switcher>=0:${PORTSDIR}/www/xpi-quick-locale-switcher
.endif

NO_BUILD=	yes
USE_XPI=	*firefox3

FIREFOX_I18N_ALL=	af ar be bg bn-IN ca cs cy da de el en-GB es-AR es-ES et eu fi \
			fr fy-NL ga-IE gl gu-IN he hi-IN hu id is it ja ka kn \
			ko ku lt lv mk mn mr nb-NO nl nn-NO pa-IN pl pt-BR pt-PT \
			ro ru si sk sl sq sr sv-SE te th tr uk zh-CN zh-TW
.ifdef PACKAGE_BUILDING
FIREFOX_I18N?=	all
.else
FIREFOX_I18N?=	zh-CN zh-TW es-ES ar pt-BR ru ja de fr pa-IN ko it
.endif
# http://en.wikipedia.org/wiki/List_of_languages_by_number_of_native_speakers

.if ${FIREFOX_I18N} == all
FIREFOX_I18N_=	${FIREFOX_I18N_ALL}
.endif
FIREFOX_I18N_?=	${FIREFOX_I18N}

WDIR=	langpack3-*@firefox.mozilla.org

XPI_DISTNAMES=	${FIREFOX_I18N_}
.for dist in ${XPI_DISTNAMES}
XPI_ID_${dist}=		langpack3-${dist}@firefox.mozilla.org
XPI_FILES_${dist}=	chrome.manifest install.rdf chrome/${dist}.jar
XPI_DIRS_${dist}=	chrome
.endfor

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR} ${WRKSRC}
	@for lang in ${FIREFOX_I18N_}; do \
		if ! (${EXTRACT_CMD} ${_DISTDIR}/$$lang.xpi -d ${WRKSRC}/langpack3-$$lang@firefox.mozilla.org);\
		then \
			exit 1; \
		fi \
	done

do-install:
	@${INSTALL} -d ${XPI_LIBDIR} ${XPI_SLDIRS_ALL}
	@${CP} -R ${WRKSRC}/ ${XPI_LIBDIR}/
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${XPI_LIBDIR}/${WDIR}/
	@${CHMOD} -R a+rX,go-w ${XPI_LIBDIR}/${WDIR}/
	@for _dir in ${XPI_LINKFARMS} ; { ${LN} -sf ${XPI_LIBDIR}/${WDIR} $$_dir/ ${_Q} ; }
	@${ECHO_CMD} '@exec ${INSTALL} -d ${XPI_SLDIRS_ALL:S,^${PREFIX},%D,}' ${_A}
	@${ECHO_CMD} '@exec for _dir in ${XPI_LINKFARMS} ; { \
		${LN} -sf ${XPI_LIBDIR}/${WDIR} $$_dir/ ${_Q}; }' ${_A}
	@${ECHO_CMD} '@unexec for _dir in ${XPI_LINKFARMS} ; { ${RM} -f $$_dir/${WDIR} ; }' ${_A}
	@${ECHO_CMD} '@unexec ${RMDIR} ${XPI_DIRS_TRY:S,^,%D/,} ${_Q}' ${_A}

post-patch:
	${FIND} ${WRKSRC} -name install.rdf -print0 | \
		${XARGS} -0L1 ${REINPLACE_CMD} -i '' -e '/<?xml/,$$!d' \
			-e 's/\(langpack\)/\13/'

List-Langs:
	@fetch -o- "http://releases.mozilla.org/pub/mozilla.org/firefox/releases/${PORTVERSION}/linux-i686/xpi"|\
		${PERL} -ne 'if(/.*href="([a-zA-Z-]+).xpi.*/){print "$$1 "}'

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
