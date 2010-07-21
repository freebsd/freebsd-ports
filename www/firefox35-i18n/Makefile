# New ports collection makefile for:	firefox3-i18n
# Date created:		28 May 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	firefox35-i18n
PORTVERSION=	3.5.11
CATEGORIES=	www
MASTER_SITE_SUBDIR=	firefox/releases/${PORTVERSION}/linux-i686/xpi
PKGNAMEPREFIX=
DISTFILES=	${FIREFOX_I18N_:S/$/.xpi/}
DIST_SUBDIR=	xpi/${DISTNAME}

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Localized interface for Firefox3.5

USE_XPI=	*firefox3

USE_SUBMAKE=	yes

WDIR=	langpack3-*@firefox.mozilla.org

XPI_DISTNAMES=	${FIREFOX_I18N_}

.include "${.CURDIR}/Makefile.option"
.include <bsd.port.pre.mk>

.ifndef WITHOUT_SWITCHER
RUN_DEPENDS+=	xpi-quick-locale-switcher>=0:${PORTSDIR}/www/xpi-quick-locale-switcher
.endif

.include "${.CURDIR}/Makefile.lang"

FIREFOX_I18N_?=	${FIREFOX_I18N}

.for dist in ${XPI_DISTNAMES}
XPI_ID_${dist}=		langpack3-${dist}@firefox.mozilla.org
XPI_FILES_${dist}=	chrome.manifest install.rdf chrome/${dist}.jar
XPI_DIRS_${dist}=	chrome
.endfor

pre-everything::
	@${ECHO_CMD}
	@${ECHO_CMD} "Please define FIREFOX_I18N_ALL to install all languages."
	@${ECHO_CMD}
	@${MKDIR} ${WRKSRC}

do-extract:
	@for lang in ${FIREFOX_I18N_}; do \
		if ! (${EXTRACT_CMD} ${_DISTDIR}/$$lang.xpi -d ${WRKSRC}/langpack3-$$lang@firefox.mozilla.org);\
		then \
			exit 1; \
		fi \
	done

.if !exists(${OPTIONSFILE}) && !defined(PACKAGE_BUILDING)
pre-configure: config
.endif

do-install:
	@${INSTALL} -d ${XPI_LIBDIR} ${XPI_SLDIRS_ALL}
	@${CP} -R ${WRKSRC}/ ${XPI_LIBDIR}/
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${XPI_LIBDIR}/${WDIR}/
	@${CHMOD} -R a+rX,go-w ${XPI_LIBDIR}/${WDIR}/
	@for _dir in ${XPI_LINKFARMS} ; { ${LN} -sf ${XPI_LIBDIR}/${WDIR} $$_dir/ ${_Q} ; }
	@${ECHO_CMD} '@exec ${INSTALL} -d ${XPI_SLDIRS_ALL:S,^${PREFIX},%D,}' ${_A}
	@${ECHO_CMD} '@exec for _dir in ${XPI_LINKFARMS} ; { \
		${LN} -sf ${XPI_LIBDIR}/${WDIR} $$_dir/ ${_Q}; }' ${_A}
	@${ECHO_CMD} '@unexec for _dir in ${XPI_LINKFARMS} ${XPI_LIBDIR}; { ${RM} -fR $$_dir/${WDIR} ; }' ${_A}

	@${ECHO_CMD} '@unexec ${RMDIR} ${XPI_DIRS_TRY:S,^,%D/,} ${_Q}' ${_A}

post-patch:
	${FIND} ${WRKSRC} -name install.rdf -print0 | \
		${XARGS} -0L1 ${REINPLACE_CMD} -i '' -e '/<?xml/,$$!d' \
			-e 's/\(langpack\)/\13/'

List-Langs:
	@fetch -o- "http://releases.mozilla.org/pub/mozilla.org/firefox/releases/${PORTVERSION}/linux-i686/xpi"|\
		${PERL} -ne 'if(/.*href="([a-zA-Z-]+).xpi.*/){print "$$1\n"}' |\
		${AWK} 'BEGIN{ORS=" "}{print $1}END{printf "\nNumber of languages: %d\n",NR}'

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"

.include <bsd.port.post.mk>
