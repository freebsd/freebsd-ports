# New ports collection makefile for: sword-modules
# Date created:   28 may 2001
# Whom:           Willem van Engen <wvengen@stack.nl>
#
# $FreeBSD$
#

PORTNAME=	sword-modules
PORTVERSION=	1.0
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.crosswire.org/pub/sword/modules/raw/ \
		http://www.crosswire.org/sword/download/ftpmirror/pub/sword/modules/raw/
DISTFILES=	${MODULE_FILES}
DIST_SUBDIR=	sword_modules
EXTRACT_ONLY=	# empty

MAINTAINER=	wvengen@stack.nl

LIB_DEPENDS=	sword.1:${PORTSDIR}/misc/sword

NO_BUILD=	yes
USE_ZIP=	yes

# Modules may change, but it has no effect on their functionality. I think
# it's best not to use checksum. Besides, there is no version number on modules.
NO_CHECKSUM=	yes

SETDIR=	${WRKDIRPREFIX}${.CURDIR}
MODFILE=	${SETDIR}/selected.mods
MODFILE_WITHDIR=${SETDIR}/selected.mods.withdir
SCRIPTS_ENV=	SETDIR="${SETDIR}" \
	TOUCH="${TOUCH}" \
	MKDIR="${MKDIR}" \
	CAT="${CAT}" \
	MKTEMP="${MKTEMP}"\
	SED="${SED}"\
	BASENAME="${BASENAME}"\
	WC="${WC}"\
	SCRIPTDIR="${SCRIPTDIR}" \
	BUILD="${PACKAGE_BUILDING}" \
	DIST_SUBDIR="${DIST_SUBDIR}" \
	MODFILE="${MODFILE}" \
	MODFILE_WITHDIR="${MODFILE_WITHDIR}" \
	BATCH="${BATCH}"
MODULE_FILES=	`${CAT} ${MODFILE}`
# XXX The regex for _CKSUMFILES in bsd.port.mk can't handle the backquotes
#     in MODULE_FILES. It substitutes the command instead of it's result.
_CKSUMFILES=	`${CAT} ${MODFILE_WITHDIR}`

DIRNAME?=	${BASENAME:S/basename/dirname/}
SORT?=		sort

.if !exists(${MODFILE})
pre-fetch:	select
.endif

select:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure.swmods

post-clean:
	@${RM} -f ${MODFILE} ${MODFILE_WITHDIR}

do-install:
	@for i in ${MODULE_FILES}; do \
		${EXTRACT_CMD} -qo ${DISTDIR}/${DIST_SUBDIR}/$${i} -d ${PREFIX}/share/sword; \
	 done

post-install:
	@tdirs=""; \
	 for i in ${MODULE_FILES}; do \
		tfiles=`${EXTRACT_CMD} -Z -1 ${DISTDIR}/${DIST_SUBDIR}/$${i}`; \
		for j in $${tfiles}; do \
			${ECHO} "share/sword/$${j}" >>${TMPPLIST}; \
			if [ "`${ECHO} $${j} | ${GREP} -v mods.d`" ]; then \
				dirn=`${DIRNAME} $${j}`; \
				while [ "$${dirn}" -a "$${dirn}" != "." -a \
					"$${dirn}" != "/" ]; do \
					if [ ! "`${ECHO} \"$${tdirs}\" | ${GREP} \"$${dirn} \"`" ]; then \
						tdirs="$${tdirs}$${dirn} "; \
					fi; \
					dirn=`${DIRNAME} $${dirn}`; \
				done; \
			fi; \
		done; \
	 done; \
	 ksorted=`for k in $${tdirs}; do printf "%s\n" $${k}; done | ${SORT} -r -t" "`;\
	 for j in $${ksorted}; do \
		${ECHO} "@dirrm share/sword/$${j}" >>${TMPPLIST}; \
	 done; \
	 ${ECHO} "@dirrm share/sword/mods.d" >>${TMPPLIST};

.include <bsd.port.mk>
