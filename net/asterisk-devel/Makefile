# New ports collection makefile for:	asterisk-current
# Date created:				15 January 2006
# Whom:					Luigi Rizzo
#
# $FreeBSD$
#

PORTNAME=	asterisk-devel
PORTVERSION=	1.4	# the head branch
CATEGORIES=	net
MASTER_SITES=	# none, we fetch directly from svn (or cvs)
DISTFILES=	# none

MAINTAINER=	luigi@FreeBSD.org
COMMENT=	An Open Source PBX and telephony toolkit - head branch

# --- BUILD OPTIONS ---
#
# If you run "make -DPLAIN" you will only run the svn distribution
# without any local change. Otherwise, you will use whatever
# patch-* and src*.tgz that is in the files directory.
# If you run "make -DNO_FETCH" you will not update the sources from
# the latest version in the svn repository.
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
# DEVELBSD	use the bsd-specific modifications that are not
#		integrated yet in the trunk.
#		If unset, use trunk, but it is not guaranteed to
#		compile cleanly on FreeBSD
#
# ZAPTEL	support for the ZAPTEL drivers. Strictly speaking,
#		you would need that only with analog or ISDN telephony
#		cards, but a lot of functionality in asterisk relies on
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
#		this is not tested, at the moment.
#
# Database support at the moment includes odbc, pgsql, sqlite and tds
# but there is no option to configure them.

OPTIONS=	\
		DEVELBSD	"BSD development version" off \
		ZAPTEL	"Zaptel (you probably want it)" on \
		PRI	"PRI support (normally off)" off \
		H323	"OpenH323 support (default off)" off \
		NEWT	"newt library, required for astman" off \
		SPEEX	"speex library, optional codec" off \

# Do not try on other architectures, no idea how it works.
ONLY_FOR_ARCHS=	i386	# maybe more but it is untested.

# We are working against -current, so it is not meant to be
# installed or packaged automatically.

RESTRICTED=	experimental version
NO_INSTALL=	"not meant to install"
NO_PACKAGE=	not meant to build a package

EXTRA_SOUNDS = \
	ftp://213.156.62.146/pub/linux/asterisk/sounds/it/it_mm_sounds_20041110.tar.gz

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

FETCH_DEPENDS+= svn:${PORTSDIR}/devel/subversion
.if defined(WITH_DEVELBSD)
# use the FreeBSD-specific version
LOCAL_REPO= ${PORTSDIR}/distfiles/ast-svn/bsd
REMOTE_REPO= http://svn.digium.com/svn/asterisk/team/rizzo/base
.else
# use the main version.
LOCAL_REPO= ${PORTSDIR}/distfiles/ast-svn/asterisk
REMOTE_REPO= http://svn.digium.com/svn/asterisk/trunk/asterisk
.endif
REPO_CMD=  \
	if [ -f asterisk ] ; then \
		svn update ${REMOTE_REPO} . ; else \
	svn checkout ${REMOTE_REPO} . ; fi

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
	${CP} -Rp ${LOCAL_REPO} ${WRKSRC}
.if defined(PLAIN)
	@echo "Not extracting local distributions"
.else
	@echo "Extracting local distributions"
	(cd ${WRKSRC}; \
	for fn in ${FILESDIR}/src*.tgz ; do [ ! -f $${fn} ] || tar xvzf $${fn} ; done )
.endif

.if defined(WITH_H323)
# this is untested.
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
