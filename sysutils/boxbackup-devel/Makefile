# New ports collection makefile for: boxbackup
# Date created:		19 December 2004
# Whom:			James O'Gorman <james@netinertia.co.uk>
#
# $FreeBSD$
#

PORTNAME=	boxbackup
PORTVERSION=	0.10
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	james@netinertia.co.uk
COMMENT=	An open source, completely automatic on-line backup system for UNIX

USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
USE_PERL5=	yes
USE_GCC=	3.2+
USE_AUTOTOOLS=	autoconf:259 aclocal:19 autoheader:259
ACLOCAL_ARGS+=	-I ${WRKSRC}/infrastructure/m4

PKGMESSAGE=	${WRKDIR}/pkg-message

OPTIONS=	CLIENT "Install the bbackupd client" On \
		SERVER "Install the bbstored server" On \
		GNUREADLINE "Enable the use of GNU readline" Off \
		TESTS  "Allows use of a 'test' target to run tests" Off

.include <bsd.port.pre.mk>

TARGETOS!=	${ECHO_CMD} `${UNAME} -s``${UNAME} -r | ${SED} -e 's/[-(].*//'` | ${TR} A-Z a-z

.if defined(WITH_GNUREADLINE)
CONFIGURE_ARGS+=--enable-gnu-readline
NO_PACKAGE=	GNU GPL prevents distributing binaries linked against GNU readline
.endif

.if defined(WITHOUT_CLIENT) && defined(WITHOUT_SERVER)
IGNORE=		requires at least CLIENT or SERVER to be defined.\
		Please 'make config' again
.endif

.if defined(WITHOUT_CLIENT)
PLIST_SUB+=	CLIENT="@comment "
.else
USE_RC_SUBR+=	bbackupd.sh
PLIST_SUB+=	CLIENT=""
ALL_TARGET+=	parcels/${DISTNAME}-backup-client-${TARGETOS}.tgz
INSTALL_TARGET+=install-backup-client
.endif

.if defined(WITHOUT_SERVER)
PLIST_SUB+=	SERVER="@comment "
.else
USE_RC_SUBR+=	bbstored.sh
PLIST_SUB+=	SERVER=""
ALL_TARGET+=	parcels/${DISTNAME}-backup-server-${TARGETOS}.tgz
INSTALL_TARGET+=install-backup-server
.endif

CONFLICTS=	boxbackup-server-[0-9]* boxbackup-client-[0-9]*
.if defined(WITHOUT_CLIENT)
CONFLICTS=	boxbackup-client-[0-9]*
PKGNAMESUFFIX=	-server
.elif defined(WITHOUT_SERVER)
CONFLICTS=	boxbackup-server-[0-9]*
PKGNAMESUFFIX=	-client
.endif

post-patch:
# Replace hard-coded /etc/box with $PREFIX/etc/box
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' \
		${WRKSRC}/lib/common/BoxPortsAndFiles.h
# Fix path to perl
	@${FIND} ${WRKSRC} -name "*.pl" -exec \
		${REINPLACE_CMD} -e 's,/usr/bin/perl,${PERL},g' {} \;
	@${REINPLACE_CMD} -e 's,/usr/bin/perl,${PERL},g' \
		${WRKSRC}/bin/bbackupd/bbackupd-config \
		${WRKSRC}/bin/bbstored/bbstored-certs \
		${WRKSRC}/bin/bbstored/bbstored-config \
		${WRKSRC}/lib/raidfile/raidfile-config
	@${FIND} ${WRKSRC} -name "Makefile.extra" -exec \
		${REINPLACE_CMD} -e 's,perl,${PERL},g' {} \;
	@${REINPLACE_CMD} -e 's,perl ,${PERL} ,g' \
		${WRKSRC}/test/bbackupd/testfiles/bbackupd.conf \
		${WRKSRC}/infrastructure/makebuildenv.pl
	@${REINPLACE_CMD} -e 's,"perl ,PERL_EXECUTABLE " ,g' \
		${WRKSRC}/test/backupstorefix/testbackupstorefix.cpp
# Fix hard-coded g++
	@${REINPLACE_CMD} -e 's,g++,${CXX},' \
		 ${WRKSRC}/infrastructure/makebuildenv.pl
.if !defined(WITHOUT_CLIENT)
	@${CAT} ${FILESDIR}/pkg-message.client >> ${PKGMESSAGE}
.endif
.if !defined(WITHOUT_SERVER)
	@${CAT} ${FILESDIR}/pkg-message.server >> ${PKGMESSAGE}
.endif

.if !defined(WITHOUT_SERVER)
pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
.endif

post-install:
.if !defined(WITHOUT_CLIENT)
	@${MKDIR} -m 0700 ${PREFIX}/etc/box/bbackupd
.endif
.if !defined(WITHOUT_SERVER)
	@${MKDIR} -m 0700 ${PREFIX}/etc/box/bbstored
.endif
	@${CAT} ${PKGMESSAGE}

.if defined(WITH_TESTS)
test:
	 @${ECHO_CMD} "===> Running tests"
	 @${MAKE} -C ${WRKSRC} test
.endif

.include <bsd.port.post.mk>
