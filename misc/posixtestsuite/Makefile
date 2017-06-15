# Created by: Alexey Zelkin <phantom@FreeBSD.org>
# $FreeBSD$

PORTNAME=	posixtestsuite
PORTVERSION=	1.5.2
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	SF/posixtest/posixtest/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open POSIX Test Suite

WRKSRC=		${WRKDIR}/posixtestsuite

NO_ARCH=	yes
NO_BUILD=	yes
NO_INSTALL=	yes
NO_PACKAGE=	"Nothing to package"

USES=		gmake

REGR_LOG=	log.run-5current

RUN_RESULT=	${WRKSRC}/run.result
LOCAL_REGR_LOG=	${WRKSRC}/regression.result

.if defined(QUIET)
THEPIPE=	>
.else
THEPIPE=	| tee 2>&1
.endif

.if defined(WITH_THRLIB)
THRLIB=		${WITH_THRLIB}
.else
THRLIB=		-lpthread
.endif

pre-everything::
	@${ECHO} "Following make commands are available:"
	@${ECHO} ""
	@${ECHO} "  * help - this message"
	@${ECHO} "  * run - run whole testsuite"
	@${ECHO} "  * rerun - re-run broken tests"
	@${ECHO} "  * regression - show differences between original and current results"
	@${ECHO} ""
	@${ECHO} "Following options are available:"
	@${ECHO} ""
	@${ECHO} "  * QUIET - don't print progress messages while running"
	@${ECHO} "  * WITH_THRLIB - choose thread library to run test against"
	@${ECHO} "    (NB: by default '"-lpthread"' is used)"
	@${ECHO} ""
	@${ECHO} "Examples:"
	@${ECHO} ""
	@${ECHO} "  make WITH_THRLIB=libthr run"
	@${ECHO} "    - run tests against libthr"
	@${ECHO} ""
	@${ECHO} "  make QUIET=YES WITH_THRLIB= regression"
	@${ECHO} "    - be quiet, run tests against libpthread (default"
	@${ECHO} "      threading library), compare tests results"
	@${ECHO} ""

help:	pre-everything

aclean:	all
	@${ECHO} "Cleaning tests tree..."
	-@(cd ${WRKSRC} && ${RM} ${RUN_RESULT} && ${MAKE_CMD} clean)

rerun:	all
.if defined(WITH_THRLIB)
	@${ECHO} ${THRLIB} > ${WRKSRC}/LDFLAGS
.endif
.if empty(THRLIB)
	@${ECHO} "Running tests (against -lc) ..."
.else
	@${ECHO} "Running tests (against ${THRLIB}) ..."
.endif
	@(cd ${WRKSRC} && ${MAKE_CMD} all) ${THEPIPE} ${RUN_RESULT}
	@${ECHO} ""
	@${ECHO} "Run output is stored into following files:"
	@${ECHO} "  * short version: ${RUN_RESULT}"
	@${ECHO} "  * extended version: ${WRKSRC}/logfile"

run:	aclean rerun

regression:	run
	@${ECHO} "Show regression log..."
	@(cd ${WRKSRC} && diff -u ${FILESDIR}/${REGR_LOG} ${RUN_RESULT}) > ${LOCAL_REGR_LOG}
	@[ -z ${LOCAL_REGR_LOG} ] || ( ${ECHO} "No regression detected"; exit 0 )
	@${ECHO} "Regression log stored at ${LOCAL_REGR_LOG}"

.include <bsd.port.mk>
