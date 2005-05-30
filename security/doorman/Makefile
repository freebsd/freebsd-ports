# New ports collection makefile for:	doorman
# Date created:				08 August 2004
# Whom:					Aaron Dalton <aaron@daltons.ca>
#
# $FreeBSD$
#

PORTNAME=	doorman
PORTVERSION=	0.8
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	doorman
EXTRACT_SUFX=	.tgz

MAINTAINER=	lupe@lupe-christoph.de
COMMENT=	A Port Knocking implementation, both daemon and client

BUILD_DEPENDS=	lsof:${PORTSDIR}/sysutils/lsof
RUN_DEPENDS=	${BUILD_DEPENDS}

PKGMESSAGE=	${WRKDIR}/pkg-message
PATCH_STRIP=	-p1

# Default to db4
WITH_BDB_VER?=	4

.include <bsd.port.pre.mk>

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

# doormand does not work with the FreeBSD 4.x version of libpcap.
# Require the ports version.
.if ${OSVERSION} < 500000
BUILD_DEPENDS+=	${LOCALBASE}/lib/libpcap.a:${PORTSDIR}/net/libpcap
.endif

INSTALL_TARGET=	installdirs install-exec install-data

MAN1=	knock.1
MAN5=	knockcf.5 doormand.cf.5 guestlist.5
MAN8=	doormand.8

GNU_CONFIGURE=	yes
SUB_FILES=	pkg-message
USE_RC_SUBR=	doorman.sh

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} " This port currently requires BerkeleyDB, has only been tested with the "
	@${ECHO_MSG} " db4.x releases, and builds with db4 by default.  If you wish to use a "
	@${ECHO_MSG} " specific version please use the WITH_BDB_VER=x argument using the "
	@${ECHO_MSG} " values 2, 3, 4, 41, or 42. "
	@${ECHO_MSG}
	@${ECHO_MSG} " CURRENTLY BUILDING WITH db${WITH_BDB_VER} "
	@${ECHO_MSG}

post-install:
	${RM} -f ${PREFIX}/etc/doormand/ipf_add
	${INSTALL_SCRIPT} ${FILESDIR}/ipf_add.atend ${PREFIX}/etc/doormand/ipf_add.atend
	${INSTALL_SCRIPT} ${FILESDIR}/ipf_add.before_block ${PREFIX}/etc/doormand/ipf_add.before_block
	${INSTALL_SCRIPT} ${FILESDIR}/ipf_delete ${PREFIX}/etc/doormand/ipf_delete
	@for man in ${MAN1}; do \
		${INSTALL_MAN} -C ${WRKSRC}/$$man ${PREFIX}/man/man1; \
	done
	@for man in ${MAN5}; do \
		${INSTALL_MAN} -C ${WRKSRC}/$$man ${PREFIX}/man/man5; \
	done
	@for man in ${MAN8}; do \
		${INSTALL_MAN} -C ${WRKSRC}/$$man ${PREFIX}/man/man8; \
	done
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
