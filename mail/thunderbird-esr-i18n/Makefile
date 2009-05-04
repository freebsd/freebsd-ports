# New ports collection makefile for:	thunderbird-i18n
# Date created:		29 May 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	thunderbird-i18n
PORTVERSION=	2.0.0.21
CATEGORIES=	mail
MASTER_SITE_SUBDIR=	thunderbird/releases/${PORTVERSION}/linux-i686/xpi
PKGNAMEPREFIX=
DISTFILES=	${THUNDERBIRD_I18N_:S/$/.xpi/}
DIST_SUBDIR=	xpi/${DISTNAME}

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Localized interface for Thunderbird

.ifndef WITHOUT_SWITCHER
RUN_DEPENDS+=	xpi-quick-locale-switcher>=0:${PORTSDIR}/www/xpi-quick-locale-switcher
.endif

NO_BUILD=	yes
USE_XPI=	*thunderbird

THUNDERBIRD_I18N_ALL=	af be bg ca cs da de el en-GB es-AR es-ES eu fi fr ga-IE \
			he hu it ja ko lt mk nb-NO nl nn-NO pa-IN pl pt-BR \
			pt-PT ru sk sl sv-SE tr uk zh-CN zh-TW
.ifdef PACKAGE_BUILDING
THUNDERBIRD_I18N?=	all
.else
THUNDERBIRD_I18N?=	zh-CN es-ES pt-BR ru ja de fr pa-IN ko it
.endif

.if ${THUNDERBIRD_I18N} == all
THUNDERBIRD_I18N_=	${THUNDERBIRD_I18N_ALL}
.endif
THUNDERBIRD_I18N_?=	${THUNDERBIRD_I18N}

WDIR=	langpack-*@thunderbird.mozilla.org

XPI_DISTNAMES=	${THUNDERBIRD_I18N_}
.for dist in ${XPI_DISTNAMES}
XPI_ID_${dist}=		langpack-${dist}@thunderbird.mozilla.org
XPI_FILES_${dist}=	chrome.manifest install.rdf chrome/${dist}.jar chrome/chromelist.txt
XPI_DIRS_${dist}=	chrome
.endfor

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR} ${WRKSRC}
	@for lang in ${THUNDERBIRD_I18N_}; do \
		if ! (${EXTRACT_CMD} ${_DISTDIR}/$$lang.xpi -d ${WRKSRC}/langpack-$$lang@thunderbird.mozilla.org);\
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
	@${ECHO_CMD} '@unexec rmdir ${XPI_DIRS_TRY:S,^,%D/,} ${_Q}' ${_A}

post-patch:
	${FIND} ${WRKSRC} -name install.rdf -print0 | \
		${XARGS} -0L1 ${REINPLACE_CMD} -i '' '/<?xml/,$$!d'

list-langs:
	@fetch -o- "http://releases.mozilla.org/pub/mozilla.org/${MASTER_SITE_SUBDIR}"|\
		perl -ne 'if(/.*href="([a-zA-Z-]+).xpi.*/){print "$$1 "}'

.include "${.CURDIR}/../../www/xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
