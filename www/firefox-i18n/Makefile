# New ports collection makefile for:	firefox-i18n
# Date created:		28 May 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	firefox-i18n
PORTVERSION=	2.0.0.1
CATEGORIES=	www
MASTER_SITES=	MOZILLA_EXTENDED/firefox/releases/${PORTVERSION}/linux-i686/xpi \
		CSME/myports/xpi/firefox-i18n-2.0:alt
PKGNAMEPREFIX=
DISTFILES=	${FIREFOX_I18N_:S/$/.xpi/:C/.*uk-UA.*/&:alt/}
DIST_SUBDIR=	xpi/${DISTNAME}

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Localized interface for Firefox

.ifndef WITHOUT_SWITCHER
RUN_DEPENDS+=	xpi-quick-locale-switcher>=0:${PORTSDIR}/www/xpi-quick-locale-switcher
.endif

NO_BUILD=	yes
USE_XPI=	*firefox

FIREFOX_I18N_ALL=	ar bg ca cs da de el en-GB es-AR es-ES eu fi fr fy-NL ga-IE gu-IN he hu it \
			ja ka ko ku lt mk mn nb-NO nl nn-NO pa-IN pl pt-BR pt-PT ru sk sl sv-SE tr \
			uk-UA zh-CN zh-TW
.ifdef PACKAGE_BUILDING
FIREFOX_I18N?=	all
.else
FIREFOX_I18N?=	zh-CN de fr ja ru it es-ES
.endif

.if ${FIREFOX_I18N} == all
FIREFOX_I18N_=	${FIREFOX_I18N_ALL}
.endif
FIREFOX_I18N_?=	${FIREFOX_I18N}

WDIR=	langpack-*@firefox.mozilla.org

XPI_DISTNAMES=	${FIREFOX_I18N_}
.for dist in ${XPI_DISTNAMES}
XPI_ID_${dist}=		langpack-${dist}@firefox.mozilla.org
XPI_FILES_${dist}=	chrome.manifest install.rdf chrome/${dist}.jar chrome/chromelist.txt
XPI_DIRS_${dist}=	chrome
.endfor

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR} ${WRKSRC}
	@for lang in ${FIREFOX_I18N_}; do \
		if ! (${EXTRACT_CMD} ${_DISTDIR}/$$lang.xpi -d ${WRKSRC}/langpack-$$lang@firefox.mozilla.org);\
		then \
			exit 1; \
		fi \
	done
	@${RM} -rf ${WRKSRC}/langpack-uk-UA@firefox.mozilla.org/defaults

do-install:
	@${INSTALL} -d ${XPI_LIBDIR} ${XPI_SLDIRS_ALL}
	@${CP} -Rp ${WRKSRC}/ ${XPI_LIBDIR}/
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${XPI_LIBDIR}/${WDIR}/
	@${CHMOD} -R a+rX,go-w ${XPI_LIBDIR}/${WDIR}/
	@for _dir in ${XPI_LINKFARMS} ; { ${LN} -sf ${XPI_LIBDIR}/${WDIR} $$_dir/ ${_Q} ; }
	@${ECHO_CMD} '@exec ${INSTALL} -d ${XPI_SLDIRS_ALL:S,^${PREFIX},%D,}' ${_A}
	@${ECHO_CMD} '@exec for _dir in ${XPI_LINKFARMS} ; { \
		${LN} -sf ${XPI_LIBDIR}/${WDIR} $$_dir/ ${_Q}; }' ${_A}
	@${ECHO_CMD} '@unexec for _dir in ${XPI_LINKFARMS} ; { ${RM} -f $$_dir/${WDIR} ; }' ${_A}
	@${ECHO_CMD} '@unexec rmdir ${XPI_DIRS_TRY:S,^,%D/,} ${_Q}' ${_A}

post-patch:
	${FIND} ${WRKSRC} -name install.rdf -print0 | \
		${XARGS} -0L1 ${REINPLACE_CMD} -i '' '/<?xml/,$$!d'

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
