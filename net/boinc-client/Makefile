# New ports collection makefile for:   boinc
# Date created:        01 October 2004
# Whom:                J.R. Oldroyd <fbsd@opal.com>
#
# $FreeBSD$
#

PORTNAME=	boinc-client
PORTVERSION=	4.13
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://boinc.berkeley.edu/source/nightly/
DISTNAME=	boinc_public-cvs-2004-10-14

MAINTAINER=	fbsd@opal.com
COMMENT=	Berkeley Open Infrastructure for Network Computing client

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-server
CONFIGURE_ENV=	CPPFLAGS=-I${X11BASE}/include CXXFLAGS=-I${X11BASE}/include

WRKSRC=		${WRKDIR}/boinc_public
PKGINSTALL=	${WRKDIR}/pkg-install
PKGPLIST=	${WRKDIR}/pkg-plist

MAN1=		boinc-client.1

FIND_BOINC_BINARY=(cd ${WRKDIR}/boinc_public/client; make -V CLIENT_BIN_FILENAME)

BOINC_USER=	boinc
BOINC_GROUP=	nobody
BOINC_HOME=	/var/db/boinc
BOINC_DATADIR=	${PREFIX}/boinc

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-api::boinc_api.C
.endif

post-patch:
	${CHMOD} +x ${WRKDIR}/boinc_public/configure

do-build:
	@(cd ${WRKDIR}/boinc_public/client; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})
	@(cd ${WRKDIR}/boinc_public/api; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})
	@(cd ${WRKDIR}/boinc_public/lib; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})

post-build:
	BBIN=`${FIND_BOINC_BINARY}`; \
	${SED}  -e "s:%%BOINC_BINARY%%:$$BBIN:g" \
		-e "s:%%BOINC_DATADIR%%:${BOINC_DATADIR}:g" \
		-e "s:%%BOINC_HOME%%:${BOINC_HOME}:g" \
		-e "s:%%BOINC_USER%%:${BOINC_USER}:g" \
		-e "s:%%BOINC_GROUP%%:${BOINC_GROUP}:g" \
		< ${FILESDIR}/boinc-client > ${WRKDIR}/boinc-client; \
	${SED}  -e "s:%%BOINC_BINARY%%:$$BBIN:g" \
		-e "s:%%BOINC_DATADIR%%:${BOINC_DATADIR}:g" \
		-e "s:%%BOINC_HOME%%:${BOINC_HOME}:g" \
		-e "s:%%BOINC_USER%%:${BOINC_USER}:g" \
		-e "s:%%BOINC_GROUP%%:${BOINC_GROUP}:g" \
		< ${FILESDIR}/boinc-client.1 > ${WRKDIR}/boinc-client.1; \
	${SED}  -e "s:%%BOINC_BINARY%%:$$BBIN:g" \
		-e "s:%%BOINC_DATADIR%%:${PREFIX}/boinc:g" \
		-e "s:%%BOINC_HOME%%:${BOINC_HOME}:g" \
		-e "s:%%BOINC_USER%%:${BOINC_USER}:g" \
		-e "s:%%BOINC_GROUP%%:${BOINC_GROUP}:g" \
		< ${PKGDIR}/pkg-install > ${WRKDIR}/pkg-install
.if ${OSVERSION} >= 500000
	BBIN=`${FIND_BOINC_BINARY}`; \
	${SED}  -e "s:%%BOINC_BINARY%%:$$BBIN:g" \
		-e "s:%%BOINC_DATADIR%%:${BOINC_DATADIR}:g" \
		-e "s:%%BOINC_HOME%%:${BOINC_HOME}:g" \
		-e "s:%%BOINC_USER%%:${BOINC_USER}:g" \
		-e "s:%%BOINC_GROUP%%:${BOINC_GROUP}:g" \
		< ${FILESDIR}/boinc.sh > ${WRKDIR}/boinc.sh
.else
	BBIN=`${FIND_BOINC_BINARY}`; \
	${SED}  -e "s:%%BOINC_BINARY%%:$$BBIN:g" \
		-e "s:%%BOINC_DATADIR%%:${BOINC_DATADIR}:g" \
		-e "s:%%BOINC_HOME%%:${BOINC_HOME}:g" \
		-e "s:%%BOINC_USER%%:${BOINC_USER}:g" \
		-e "s:%%BOINC_GROUP%%:${BOINC_GROUP}:g" \
		< ${FILESDIR}/boinc.sh-4.x > ${WRKDIR}/boinc.sh
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/boinc-client ${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/boinc-client.1 ${PREFIX}/man/man1
	${MKDIR} ${PREFIX}/boinc/client
	${INSTALL_PROGRAM} ${WRKDIR}/boinc_public/client/`${FIND_BOINC_BINARY}` ${PREFIX}/boinc/client
	${MKDIR} ${PREFIX}/boinc/lib
	${INSTALL} ${WRKDIR}/boinc_public/lib/*.h ${PREFIX}/boinc/lib
	${INSTALL} ${WRKDIR}/boinc_public/lib/libboinc.a ${PREFIX}/boinc/lib
	${INSTALL} ${WRKDIR}/boinc_public/RSAEuro/source/librsaeuro.a ${PREFIX}/boinc/lib
	${MKDIR} ${PREFIX}/boinc/api
	${INSTALL} ${WRKDIR}/boinc_public/api/*.h ${PREFIX}/boinc/api
	${TOUCH} ${PREFIX}/boinc/api/Makefile.am
	${TOUCH} ${PREFIX}/boinc/lib/Makefile.am
	${TOUCH} ${PREFIX}/boinc/Makefile.am
	${MKDIR} ${PREFIX}/boinc/projects
	${MKDIR} ${PREFIX}/etc/rc.d
	${INSTALL_SCRIPT} ${WRKDIR}/boinc.sh ${PREFIX}/etc/rc.d
	${CAT} ${PKGMESSAGE}

post-install:
	${REINPLACE_CMD} \
	    -e "s:%%BOINC_BINARY%%:`${FIND_BOINC_BINARY}`:g" \
	    -e "s:%%BOINC_HOME%%:${BOINC_HOME}:g" \
	    -e "s:%%BOINC_USER%%:${BOINC_USER}:g" \
	    ${TMPPLIST}
	@${SETENV} ${SCRIPTS_ENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
