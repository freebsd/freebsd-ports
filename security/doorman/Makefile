# New ports collection makefile for:	doorman
# Date created:				08 August 2004
# Whom:					Aaron Dalton <aaron@daltons.ca>
#
# $FreeBSD$
#

PORTNAME=	doorman
PORTVERSION=	0.8
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	doorman
EXTRACT_SUFX=	.tgz

MAINTAINER=	lupe@lupe-christoph.de
COMMENT=	A Port Knocking implementation, both daemon and client

BUILD_DEPENDS=	lsof:${PORTSDIR}/sysutils/lsof
RUN_DEPENDS=	${BUILD_DEPENDS}

PKGMESSAGE=	${WRKDIR}/pkg-message

# Default to db4
WITH_BDB_VER?=	4

.if ${WITH_BDB_VER} == 2
LIB_DEPENDS=	db2.0:${PORTSDIR}/databases/db2
.elif ${WITH_BDB_VER} == 3
LIB_DEPENDS=	db3.3:${PORTSDIR}/databases/db3
.elif ${WITH_BDB_VER} == 4
LIB_DEPENDS=	db4.0:${PORTSDIR}/databases/db4
.elif ${WITH_BDB_VER} == 41
LIB_DEPENDS=	db41.1:${PORTSDIR}/databases/db41
.elif ${WITH_BDB_VER} == 42
LIB_DEPENDS=	db-4.2.2:${PORTSDIR}/databases/db42
.else
.error WITH_BDB_VER must be one between 2, 3, 4, 41 and 42
.endif

MAN1=	knock.1
MAN5=	knockcf.5 doormand.cf.5 guestlist.5
MAN8=	doormand.8

GNU_CONFIGURE=	yes

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} " This port currently requires BerkeleyDB, has only been tested with the "
	@${ECHO_MSG} " db4.x releases, and builds with db4 by default.  If you wish to use a "
	@${ECHO_MSG} " specific version please use the WITH_BDB_VER=x argument using the "
	@${ECHO_MSG} " values 2, 3, 4, 41, or 42. "
	@${ECHO_MSG}
	@${ECHO_MSG} " CURRENTLY BUILDING WITH db${WITH_BDB_VER} "
	@${ECHO_MSG}

pre-install:
	@${SED} 's#%%PREFIX%%#${PREFIX}#' ${MASTERDIR}/pkg-message >${PKGMESSAGE}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
