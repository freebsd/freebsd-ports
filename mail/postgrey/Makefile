# New ports collection makefile for:    postgrey
# Date created:				24 August 2004
# Whom:					Will Andrews <will@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	postgrey
PORTVERSION=	1.18
CATEGORIES=	mail
MASTER_SITES=	http://isg.ee.ethz.ch/tools/postgrey/pub/

MAINTAINER=	haroldp@internal.org
COMMENT=	Greylisting policy server for Postfix

RUN_DEPENDS=	${SITE_PERL}/Net/Server.pm:${PORTSDIR}/net/p5-Net-Server \
		${SITE_PERL}/IO/Multiplex.pm:${PORTSDIR}/devel/p5-IO-Multiplex \
		${SITE_PERL}/${PERL_ARCH}/BerkeleyDB.pm:${PORTSDIR}/databases/p5-BerkeleyDB

USE_PERL5=	yes
USE_RC_SUBR=	yes
NO_BUILD=	yes

ETCFILES=	whitelist_clients whitelist_recipients
PGY_USERNAME?=	postgrey
PGY_USERID?=	225
PGY_GROUPNAME?=	${PGY_USERNAME}
PGY_GROUPID?=	${PGY_USERID}
PGY_DIR?=	/var/db/postgrey

PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall

pre-extract:
.if !defined(SKIP_BDB_CHECK) && !defined(PACKAGE_BUILDING)
.if !defined(WITH_BDB_VER)
	@${ECHO} "This port requires databases/p5-BerkeleyDB to be built with"
	@${ECHO} "WITH_BDB_VER=41 or later."
	exit 1
.else
.if ${WITH_BDB_VER} < 41
	@${ECHO} "This port requires databases/p5-BerkeleyDB to be built with"
	@${ECHO} "WITH_BDB_VER=41 or later."
	exit 1
.endif
.endif
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	Needs perl 5.6.1 or higher, install lang/perl5.8 and try again
.endif

pre-install:
	${SED}	-e 's#%%PREFIX%%#${PREFIX}#g' -e 's#%%RC_SUBR%%#${RC_SUBR}#g' \
		${FILESDIR}/postgrey.sh > ${WRKDIR}/postgrey.sh
	${SED}	-e 's#%%USER%%#${PGY_USERNAME}#g' -e 's#%%UID%%#${PGY_USERID}#g' \
		-e 's#%%GROUP%%#${PGY_GROUPNAME}#g' -e 's#%%GID%%#${PGY_GROUPID}#g' \
		-e 's#%%PREFIX%%#${PREFIX}#g' -e 's#%%ETCFILES%%#${ETCFILES}#g' \
		-e 's#%%POSTGREYDIR%%#${PGY_DIR}#g' ${MASTERDIR}/pkg-install > \
		${PKGINSTALL}
.if !defined(SKIP_BDB_CHECK) && !defined(PACKAGE_BUILDING)
	${SH} ${PKGREQ} INSTALL
.endif
	${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/postgrey ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKDIR}/postgrey.sh ${PREFIX}/etc/rc.d
	${MKDIR} ${PREFIX}/etc/postfix
.for i in ${ETCFILES}
	${INSTALL_DATA} ${WRKSRC}/postgrey_${i} ${PREFIX}/etc/postfix/dist-postgrey_${i}
.endfor

post-install:
	${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
