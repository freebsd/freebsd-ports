# New ports collection makefile for:	asterisk-current
# Date created:				15 January 2006
# Whom:					Luigi Rizzo
#
# $FreeBSD$
#

PORTNAME=	asterisk
PORTVERSION=	1.4	# the head branch
CATEGORIES=	net
MASTER_SITES=	# none, we fetch directly from svn (or cvs)
DISTFILES=	# none

MAINTAINER=	luigi@FreeBSD.org
COMMENT=	An Open Source PBX and telephony toolkit - head branch

# --- BUILD OPTIONS ---
# If you run "make -DPLAIN" you will only run the svn distribution
# without any local change. Otherwise, you will use whatever
# patch-* and src*.tgz that is in the files directory.
#
# Other options are available with "make config", below.
#
# In general, the original asterisk code has some tests in the Makefiles
# to check whether certain packages are installed, and use them in case,
# without giving the user a chance to override the decision.
# Only in a limited number of cases (zaptel, libpri...) there are
# WITHOUT_FOO Makefile variables to disable the use of a given package.
# The options below are designed with the above in mind.
#
# SVN		fetch sources through svn. At the moment this is the
#		only supported distribution of -head sources.
#
# ZAPTEL	support for the ZAPTEL drivers. Strictly speaking,
#		you would need that only with analog or ISDN telephony
#		cards, but a lot of functionality in asterisk rely on
#		this driver, so you might have a hard time without it.
#
# PRI		support for ISDN PRI channels. Not necessary unless you
#		have this cards.
#
# NEWT		make sure newt is installed, if you want to compile astman.
#
# SPEEX		make sure it has speex, additional codec.
#
# H323		make sure the openh323 packages are installed.
#
# Database support at the moment includes odbc, pgsql, sqlite and tds
# but there is no option to configure them.

OPTIONS=	\
		SVN	"Fetch from svn (you must!)" on \
		ZAPTEL	"Zaptel (you probably want it)" on \
		PRI	"PRI support (normally off)" off \
		H323	"OpenH323 support (default off)" off \
		NEWT	"newt library, required for astman" off \
		SPEEX	"speex library, optional codec" off \

# Do not try on other architectures, no idea how it works.
ONLY_FOR_ARCHS=	i386	# maybe more but it is untested.

# We are working against -current, so it is not meant to be
# installed or packaged automatically.

RESTRICTED=	"experimental version"
NO_INSTALL=	"not meant to install"

# local components
# The code uses gmake and flex/bison.
USE_GMAKE=	yes
USE_BISON=	yes

# Editline use autoconf, but the configure is there already,
# so these are just reminders.
# GNU_CONFIGURE=	yes
# CONFIGURE_WRKSRC=	${WRKSRC}/editline

.include <bsd.port.pre.mk>	# need to include this before testing options.

# Targets for the fetch command.
#
.if defined(WITH_SVN)	# fetch from svn
LOCAL_REPO= ${PORTSDIR}/distfiles/ast-svn
REMOTE_REPO= http://svn.digium.com/svn/asterisk/trunk
FETCH_DEPENDS+= svn:${PORTSDIR}/devel/subversion
REPO_CMD=  \
	if [ -f asterisk ] ; then \
		svn update ${REMOTE_REPO} asterisk ; else \
	svn checkout ${REMOTE_REPO} asterisk ; fi
.else
# fetch from cvs - but the server is severely outdated.
LOCAL_REPO=	${PORTSDIR}/distfiles/ast-curr
REMOTE_REPO= :pserver:anoncvs:anoncvs@cvs.digium.com:/usr/cvsroot
REPO_CMD= \
	cvs -d ${REMOTE_REPO} -z5 -R update asterisk || \
	cvs -d ${REMOTE_REPO} -z5 -R co asterisk
.endif

do-fetch:
	${MKDIR} ${LOCAL_REPO}
	[ "x${NO_FETCH}" != "x" ] || (cd ${LOCAL_REPO}; ${REPO_CMD} )

.if defined(PLAIN)	# disable any local patches
do-patch:
	@echo "Local patches disabled, to check the FreeBSD compliance"
	@echo "of the standard asterisk distribution."
.endif

do-extract:
	${MKDIR} ${WRKDIR}
	@echo "Copying main repository"
	${CP} -Rp ${LOCAL_REPO}/asterisk ${WRKSRC}
.if defined(PLAIN)
	@echo "Not extracting local distributions"
.else
	@echo "Extracting local distributions"
	(cd ${WRKSRC}; \
	for fn in ${FILESDIR}/src*.tgz ; do [ ! -f $${fn} ] || tar xvzf $${fn} ; done )
.endif

.if defined(WITH_H323)
# put in the prerequisites
BUILD_DEPENDS+=	${NONEXISTENT}:${PORTSDIR}/devel/pwlib152:build \
		${NONEXISTENT}:${PORTSDIR}/net/openh323-112:build
.endif

.if defined(WITH_ZAPTEL)
# first, put in the prerequisites.
BUILD_DEPENDS+=	${LOCALBASE}/include/zaptel.h:${PORTSDIR}/misc/zaptel
RUN_DEPENDS+=	${LOCALBASE}/include/zaptel.h:${PORTSDIR}/misc/zaptel
# now look at pri (no pri if no zaptel)
.if defined(WITH_PRI)
LIB_DEPENDS+=	pri.1:${PORTSDIR}/misc/libpri
.else
MAKE_ENV+=	WITHOUT_PRI=1
.endif
.else
MAKE_ENV+=	WITHOUT_ZAPTEL=1
.endif

.if defined(WITH_NEWT)
# newt is required for astmon
LIB_DEPENDS+=	newt.51:${PORTSDIR}/devel/newt
.endif

.if defined(WITH_SPEEX)
# support for additional codecs
LIB_DEPENDS+=	speex.3:${PORTSDIR}/audio/speex
.endif

.include <bsd.port.post.mk>
