# New ports collection makefile for:	firefox3-i18n
# Date created:		28 May 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	seamonkey2-i18n
PORTVERSION=	2.0.5
CATEGORIES=	www
MASTER_SITE_SUBDIR=	seamonkey/releases/${PORTVERSION}/langpack
PKGNAMEPREFIX=
DISTFILES=	${SEAMONKEY_I18N_:S/$/.langpack.xpi/:S/^/seamonkey-${PORTVERSION}./}
DIST_SUBDIR=	xpi/${DISTNAME}

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Localized interface for SeaMonkey 2

USE_XPI=	*seamonkey

USE_SUBMAKE=	yes

WDIR=	langpack-*@seamonkey.mozilla.org

XPI_DISTNAMES=	${SEAMONKEY_I18N_}

.include "${.CURDIR}/Makefile.option"
.include <bsd.port.pre.mk>

.ifndef WITHOUT_SWITCHER
RUN_DEPENDS+=	xpi-quick-locale-switcher>=0:${PORTSDIR}/www/xpi-quick-locale-switcher
.endif

.include "${.CURDIR}/Makefile.lang"

SEAMONKEY_I18N_?=	${SEAMONKEY_I18N}

.for dist in ${XPI_DISTNAMES}
XPI_ID_${dist}=		langpack-${dist}@seamonkey.mozilla.org
XPI_FILES_${dist}=	chrome.manifest install.rdf chrome/${dist}.jar
XPI_DIRS_${dist}=	chrome
.endfor

pre-everything::
	@${ECHO_CMD}
	@${ECHO_CMD} "Please define SEAMONKEY_I18N_ALL to install all languages."
	@${ECHO_CMD}
	@${MKDIR} ${WRKSRC}

do-extract:
	@for lang in ${SEAMONKEY_I18N_}; do \
		if ! (${EXTRACT_CMD} ${_DISTDIR}/seamonkey-${PORTVERSION}.$$lang.langpack.xpi -d ${WRKSRC}/langpack-$$lang@seamonkey.mozilla.org);\
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
		${XARGS} -0L1 ${REINPLACE_CMD} -i '' -e '/<?xml/,$$!d'

List-Langs:
	@fetch -o- "http://releases.mozilla.org/pub/mozilla.org/seamonkey/releases/${PORTVERSION}/langpack"|\
		${PERL} -ne 'if(/.*href="seamonkey-2.0.([a-zA-Z-]+).langpack.xpi"/){print "$$1\n"}' |\
		${AWK} 'BEGIN{ORS=" "}{print $1}END{printf "\nNumber of languages: %d\n",NR}'

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"

.include <bsd.port.post.mk>
