# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	seamonkey-i18n
PORTVERSION=	2.21
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	MOZILLA/${PORTNAME:S|-i18n||}/releases/${PORTVERSION}/langpack
PKGNAMEPREFIX=
DISTFILES=	${SEAMONKEY_I18N_:S/$/.langpack.xpi/:S/^/seamonkey-${PORTVERSION}./}
DIST_SUBDIR=	xpi/${DISTNAME}

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Localized interface for SeaMonkey

EXTRACT_DEPENDS=	zip:${PORTSDIR}/archivers/zip

PLIST?=		${WRKDIR}/plist
PLISTD?=	${WRKDIR}/plist_dirs
PLISTF?=	${WRKDIR}/plist_files

USE_SEAMONKEY=	yes
USE_XPI=	seamonkey linux-seamonkey

USE_SUBMAKE=	yes

WDIR=	langpack-*@seamonkey.mozilla.org

XPI_DISTNAMES=	${SEAMONKEY_I18N_}

.ifndef WITHOUT_SWITCHER
RUN_DEPENDS+=	xpi-quick-locale-switcher>=0:${PORTSDIR}/www/xpi-quick-locale-switcher
.endif

NO_STAGE=	yes
.include "${.CURDIR}/Makefile.option"
.include <bsd.port.options.mk>
.include "${.CURDIR}/Makefile.lang"

SEAMONKEY_I18N_?=	${SEAMONKEY_I18N}

.for dist in ${XPI_DISTNAMES}
XPI_ID_${dist}=		langpack-${dist}@seamonkey.mozilla.org
.endfor

pre-everything::
	@${ECHO_CMD}
	@${ECHO_CMD} "Please define SEAMONKEY_I18N_ALL to install all languages."
	@${ECHO_CMD}

do-extract:
	@${MKDIR} ${WRKSRC}
	@for lang in ${SEAMONKEY_I18N_}; do \
		if ! (${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/seamonkey-${PORTVERSION}.$$lang.langpack.xpi -d ${WRKSRC}/langpack-$$lang@seamonkey.mozilla.org);\
		then \
			exit 1; \
		fi; \
		cd ${WRKSRC}/langpack-$$lang@seamonkey.mozilla.org/; \
		${FIND} -H -s * ! -type d | \
		${SED} -e "s|^|lib/xpi/langpack-$$lang@seamonkey.mozilla.org/|" >> ${PLISTF} && \
		${FIND} -d * -type d | \
		${SED} -e "s|^|@dirrm lib/xpi/langpack-$$lang@seamonkey.mozilla.org/|" >> ${PLISTD}; \
	done
	${CAT} ${PLISTF} | ${SORT} >> ${PLIST}
	${CAT} ${PLISTD} | ${SORT} -r >> ${PLIST}

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

post-patch:
	${FIND} ${WRKSRC} -name install.rdf -print0 | \
		${XARGS} -0L1 ${REINPLACE_CMD} -i '' -e '/<?xml/,$$!d'

list-langs:
	@fetch -qo- "https://ftp.mozilla.org/pub/mozilla.org/${PORTNAME:S|-i18n||}/releases/${PORTVERSION}/langpack"|\
		${PERL} -ne 'if(/.*href="${DISTNAME:S|-i18n||}.([a-zA-Z-]+).langpack.xpi.*/){print "$$1\n"}' |\
		${AWK} 'BEGIN{ORS=" "}{print $$1}END{printf "\nNumber of languages: %d\n",NR}'

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"

.include <bsd.port.mk>
