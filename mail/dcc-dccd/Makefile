# New ports collection makefile for:	mail/dcc-dccd
# Date created:		Wed Oct 9 19:30:00 WST 2002
# Whom:			Dean Hollister <dean@odyssey.apana.org.au>
#
# $FreeBSD$
#

PORTNAME=	dcc-dccd
PORTVERSION=	1.3.115
CATEGORIES=	mail
MASTER_SITES=	http://www.dcc-servers.net/dcc/source/old/ \
		http://www.rhyolite.com/anti-spam/dcc/source/old/ \
		ftp://ftp.dcc-servers.net/src/dcc/old/ \
		ftp://ftp.rhyolite.com/src/dcc/old/
DISTNAME=	dcc-${PORTVERSION}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	cgreen@sentex.net
COMMENT=	Distributed Checksum Clearinghouse bulk email detector

HAS_CONFIGURE=	yes
MANCOMPRESSED=	yes
MAN8=		cdcc.8 dbclean.8 dblist.8 dcc.8 dccd.8 dccifd.8 dccm.8 \
		dccproc.8 dccsight.8

PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall

USE_RC_SUBR=

#
# ALT_HOME -	DCC keeps its config files in its home directory but writes
#		status and database files there as well.  This latter point
#		means that the FreeBSD default home directory for DCC,
#		/usr/local/dcc, cannot be mounted read-only.
#
#		DCC's default home dir of /var/dcc breaks FreeBSD hierarchy
#		conventions, but allows for a read-only /usr.
#
#		Setting ALT_HOME on will set DCC's home to /var/dcc, but
#		keep its binaries in /usr/local/dcc/libexec.  Since this
#		also means DCC's config files will be in /var/dcc, for
#		convenience a soft link from /usr/local/etc/dcc to /var/dcc
#		may be created.
#
#		Note also that dccifd's default socket location is DCC's
#		home, so if /var/dcc is used for the home, then programs
#		like SpamAssassin may need to be explicitly told where
#		to find dccifd's socket.
#
OPTIONS=	DCCIFD	"DCC interface daemon (for SpamAssassin etc)"	on \
		DCCM	"DCC milter (for Sendmail only)"	on \
		DCCD	"DCC server"	on \
		DCCGREY	"DCC greylisting server"	on \
		IPV6	"IPv6 support"	on  \
		ALT_HOME	"DCC home in /var/dcc"	off \
		PORTS_SENDMAIL	"Use base Sendmail if off, ports if on"	off

## User for DCC files and SUID binaries
#
DCCUSER?=	dcc
DCCUID?=	112
DCCGROUP?=	dcc
DCCGID?=	112

PLIST_SUB+=	DCCUSER="${DCCUSER}"

## Use the configure script to explicitly set the locations of all files,
## in case the standard locations have been locally overridden
#
CONFIGURE_ARGS=	--with-uid=${DCCUSER} --bindir=${PREFIX}/bin --mandir=${MANPREFIX}/man --with-configsuffix=.sample

.include <bsd.port.pre.mk>

SUB_FILES=		pkg-message
SUB_LIST+=		WRKSRC=${WRKSRC}

## /var/dcc home support
#
.if defined(WITH_ALT_HOME)
CONFIGURE_ARGS+=	--libexecdir=${PREFIX}/dcc/libexec --with-cgibin=${PREFIX}/dcc/cgi-bin
DCCHOME=		/var/dcc
PLIST_SUB+=		WITH_ALT_HOME=""
.else
DCCHOME=		${PREFIX}/dcc
PLIST_SUB+=		WITH_ALT_HOME="@comment "
.endif

SUB_LIST+=		DCCHOME=${DCCHOME}
CONFIGURE_ARGS+=	--homedir=${DCCHOME}

## dccm milter support
#
.if defined(WITH_DCCM)

.if !exists(/usr/lib/libmilter.a) && !exists(${LOCALBASE}/lib/libmilter.a)
IGNORE=		neither base system nor Ports version of Sendmail installed, cannot build milter
.endif
.if defined(WITHOUT_PORTS_SENDMAIL) && !exists(/usr/lib/libmilter.a)
IGNORE=		base system Sendmail not found or too old, rebuild with WITH_PORTS_SENDMAIL=yes or WITHOUT_DCCM=yes
.endif
.if defined(WITH_PORTS_SENDMAIL) && !exists(${LOCALBASE}/lib/libmilter.a)
IGNORE=		ports Sendmail not found, rebuild with WITHOUT_PORTS_SENDMAIL=yes or WITHOUT_DCCM=yes
.endif

.if defined(WITHOUT_PORTS_SENDMAIL)
MILTERBASE=	/usr
.else
BUILD_DEPENDS+=	${LOCALBASE}/lib/libmilter.a:${PORTSDIR}/mail/sendmail
MILTERBASE?=	${LOCALBASE}
.endif

MILTERINC=	${MILTERBASE}/include
MILTERLIB=	${MILTERBASE}/lib

CPPFLAGS+=	-I${MILTERINC}
LDFLAGS+=	-L${MILTERLIB}

CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS+=	--with-sendmail=${MILTERBASE}

PLIST_SUB+=	WITH_DCCM=""

USE_RC_SUBR+=	dccm.sh

.else
CONFIGURE_ARGS+=	--disable-dccm
PLIST_SUB+=	WITH_DCCM="@comment "
.endif

## dccifd client interface daemon support
#
.if defined(WITHOUT_DCCIFD)
CONFIGURE_ARGS+=	--disable-dccifd
PLIST_SUB+=	WITH_DCCIFD="@comment "
.else
PLIST_SUB+=	WITH_DCCIFD=""
USE_RC_SUBR+=	dccifd.sh
.endif

## dccd server support
#
.if defined(WITHOUT_DCCD) && defined(WITHOUT_DCCGREY)
CONFIGURE_ARGS+=	--disable-server
PLIST_SUB+=	WITH_DCCD="@comment "
.else
PLIST_SUB+=	WITH_DCCD=""
.endif

## IPV6 support
#
.if defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--disable-IPv6
.endif

## Packing list and rcNG script fixups
#
.if defined(WITHOUT_DCCIFD) && defined(WITHOUT_DCCM)
PLIST_SUB+=	WITH_IFD_MILT="@comment "
.else
PLIST_SUB+=	WITH_IFD_MILT=""
.endif

.if defined(WITH_DCCD)
USE_RC_SUBR+=	dccd.sh
.endif

.if defined(WITH_DCCGREY)
USE_RC_SUBR+=	dccgrey.sh
PLIST_SUB+=	WITH_DCCGREY=""
.else
PLIST_SUB+=	WITH_DCCGREY="@comment "
.endif

## Substitutions in pkg-install and pkg-deinstall
#
SED_SCRIPT=	-e 's|%%PREFIX%%|${PREFIX}|g' \
		-e 's|%%DCCUSER%%|${DCCUSER}|g' -e 's|%%DCCUID%%|${DCCUID}|g' \
		-e 's|%%DCCGROUP%%|${DCCGROUP}|g' -e 's|%%DCCGID%%|${DCCGID}|g' \
		-e 's|%%DCCHOME%%|${DCCHOME}|g'

pre-everything::
	@${ECHO_MSG} ' '
	@${ECHO_MSG} 'A description of ALT_HOME may be found in the port's Makefile.'
	@${ECHO_MSG} ' '

post-build:
	@${SED} ${SED_SCRIPT} ${PKGDIR}/pkg-install >${PKGINSTALL}
	@${SED} ${SED_SCRIPT} ${PKGDIR}/pkg-deinstall >${PKGDEINSTALL}

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
	${SH} ${PKGINSTALL} ${PREFIX} PRE-INSTALL

post-install:

## Make certain DCC's config files are owned by DCC's user
#
	@${CHOWN} ${DCCUSER} ${DCCHOME}/*

## Print DCC installation notes and RESTRICTIONS file info
#
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
