# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	thunderbird-i18n
PORTVERSION=	17.0.2
CATEGORIES=	mail
MASTER_SITE_SUBDIR=	thunderbird/releases/${PORTVERSION}/linux-i686/xpi
PKGNAMEPREFIX=
DISTFILES=	${THUNDERBIRD_I18N_:S/$/.xpi/}
DIST_SUBDIR=	xpi/${DISTNAME}

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Localized interface for Thunderbird

EXTRACT_DEPENDS=	zip:${PORTSDIR}/archivers/zip

PLIST?=		${WRKDIR}/plist
PLISTD?=	${WRKDIR}/plist_dirs
PLISTF?=	${WRKDIR}/plist_files

.ifndef WITHOUT_SWITCHER
RUN_DEPENDS+=	xpi-quick-locale-switcher>=0:${PORTSDIR}/www/xpi-quick-locale-switcher
.endif

NO_BUILD=	yes
USE_THUNDERBIRD=	17
USE_XPI=	thunderbird linux-thunderbird

THUNDERBIRD_I18N_ALL=	ar br ca cs da de en-GB en-US es-AR es-ES et eu fi fr \
			fy-NL ga-IE gd gl he hu is it ja ko lt nb-NO nl nn-NO \
			pl pt-BR pt-PT rm ru si sk sl sq sv-SE ta-LK tr uk zh-TW

.ifdef PACKAGE_BUILDING
THUNDERBIRD_I18N?=	all
.else
THUNDERBIRD_I18N?=	es-ES pt-BR ru ja de fr ko it
.endif

.if ${THUNDERBIRD_I18N} == all
THUNDERBIRD_I18N_=	${THUNDERBIRD_I18N_ALL}
.endif
THUNDERBIRD_I18N_?=	${THUNDERBIRD_I18N}

WDIR=	langpack-*@thunderbird.mozilla.org

XPI_DISTNAMES=	${THUNDERBIRD_I18N_}
.for dist in ${XPI_DISTNAMES}
XPI_ID_${dist}=		langpack-${dist}@thunderbird.mozilla.org
.endfor

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR} ${WRKSRC}
	@for lang in ${THUNDERBIRD_I18N_}; do \
		if ! (${EXTRACT_CMD} ${_DISTDIR}/$$lang.xpi -d ${WRKSRC}/langpack-$$lang@thunderbird.mozilla.org);\
		then \
			exit 1; \
		fi; \
		cd ${WRKSRC}/langpack-$$lang@thunderbird.mozilla.org/; \
		${FIND} -H -s * ! -type d | \
		${SED} -e "s|^|lib/xpi/langpack-$$lang@thunderbird.mozilla.org/|" >> ${PLISTF} && \
		${FIND} -d * -type d | \
		${SED} -e "s|^|@dirrm lib/xpi/langpack-$$lang@thunderbird.mozilla.org/|" >> ${PLISTD}; \
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
	@${ECHO_CMD} '@unexec for _dir in ${XPI_LINKFARMS} ${XPI_LIBDIR}; { ${RM} -fR $$_dir/${WDIR} ; }' ${_A}
	@${ECHO_CMD} '@unexec ${RMDIR} ${XPI_DIRS_TRY:S,^,%D/,} ${_Q}' ${_A}

post-patch:
	${FIND} ${WRKSRC} -name install.rdf -print0 | \
		${XARGS} -0L1 ${REINPLACE_CMD} -i '' '/<?xml/,$$!d'

list-langs:
	@fetch -o- "http://releases.mozilla.org/pub/mozilla.org/${MASTER_SITE_SUBDIR}"|\
		perl -ne 'if(/.*href="([a-zA-Z-]+).xpi.*/){print "$$1 "}'

.include "${.CURDIR}/../../www/xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
