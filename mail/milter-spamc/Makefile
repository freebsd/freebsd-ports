# New ports collection makefile for:    milter-spamc
# Date created:                         5 Sep 2004
# Whom:                                 Mike Boev
#
# $FreeBSD$
#

PORTNAME=	milter-spamc
PORTVERSION=	0.25
CATEGORIES=	mail
MASTER_SITES=	http://www.snert.com/Software/download/
PKGNAMESUFFIX?=	${BERKELEYDB_SUFFIX}
DISTFILES=	libsnert-1.40.tgz milter-spamc-${PORTVERSION}.tgz

MAINTAINER=	mike@tric.tomsk.gov.ru
COMMENT=	Yet Another Sendmail-SpamAssassin Interface Milter

RESTRICTED=	No redistribution allowed

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/com/snert/src/milter-spamc
MAKEFILE=	makefile

# Options to define Features:
# WITH_DEBUG=yes
# SENDMAIL_WITH_BERKELEYDB_VER=2
# SENDMAIL_WITH_BERKELEYDB_VER=3
# SENDMAIL_WITH_BERKELEYDB_VER=4
# SENDMAIL_WITH_BERKELEYDB_VER=41
# SENDMAIL_WITH_BERKELEYDB_VER=42

.include <bsd.port.pre.mk>

.if ( ${OSVERSION} < 440000 )
BUILD_DEPENDS=	gxargs:${PORTSBASE}/misc/findutils
.endif

.if !exists(/usr/lib/libmilter.a) && !exists(${LOCALBASE}/lib/libmilter.a)
IGNORE=		requires Sendmail 8.12
.endif
.if exists(${LOCALBASE}/lib/libmilter.a)
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.endif
CFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}

DOCS=		CHANGES.TXT index.shtml style.css mailto.js \
		LICENSE.TXT

CONFIGURE_TARGET=--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS+=--localstatedir=/var/spool
.if !defined(WITH_DEBUG)
CONFIGURE_ARGS+=--disable-debug
.endif

.if defined(SENDMAIL_WITH_BERKELEYDB_VER)
.if ${SENDMAIL_WITH_BERKELEYDB_VER} == "2"
BERKELEYDB_SUFFIX=	+db2
BERKELEYDB_PORT?=	databases/db2
BERKELEYDB_LIB?=	db2
BERKELEYDB_INCLUDE?=	${LOCALBASE}/include/db2
.endif
.if ${SENDMAIL_WITH_BERKELEYDB_VER} == "3"
BERKELEYDB_SUFFIX=	+db3
BERKELEYDB_PORT?=	databases/db3
BERKELEYDB_LIB?=	db3
BERKELEYDB_INCLUDE?=	${LOCALBASE}/include/db3
.endif
.if ${SENDMAIL_WITH_BERKELEYDB_VER} == "4"
BERKELEYDB_SUFFIX=	+db4
BERKELEYDB_PORT?=	databases/db4
BERKELEYDB_LIB?=	db4
BERKELEYDB_INCLUDE?=	${LOCALBASE}/include/db4
.endif
.if ${SENDMAIL_WITH_BERKELEYDB_VER} == "41"
BERKELEYDB_SUFFIX=	+db41
BERKELEYDB_PORT?=	databases/db41
BERKELEYDB_LIB?=	db41
BERKELEYDB_INCLUDE?=	${LOCALBASE}/include/db41
.endif
.if ${SENDMAIL_WITH_BERKELEYDB_VER} == "42"
BERKELEYDB_SUFFIX=	+db42
BERKELEYDB_PORT?=	databases/db42
BERKELEYDB_LIB?=	db-4.2
BERKELEYDB_INCLUDE?=	${LOCALBASE}/include/db42
.endif
LIB_DEPENDS+=		${BERKELEYDB_LIB}:${PORTSDIR}/${BERKLEYDB_PORT}
RUN_DEPENDS+=		${LOCALBASE}/sbin/makemap:${PORTSDIR}/mail/sendmail
CONFIGURE_ARGS+=	--with-db=${BERKELEYDB_INCLUDE}
.else
CONFIGURE_ARGS+=	--with-db
.endif

USE_RC_SUBR=	yes
RC_SCRIPTS_SUB=	PREFIX=${PREFIX} RC_SUBR=${RC_SUBR} NAME=milter_spamc

post-extract:
	${SED}	${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/milter-spamc.sh > ${WRKSRC}/milter-spamc.sh.freebsd

post-patch:
.if ( ${OSVERSION} < 440000 ) # please contact vs@ if in doubt
	${REINPLACE_CMD} 's/xargs -J{}/gxargs -i{}/' ${WRKSRC}/../lib/configure
.endif
	${REINPLACE_CMD} "s,-fvolatile,," ${WRKSRC}/configure

pre-configure:
	@cd ${WRKSRC}/../lib && \
	${SETENV} CC="${CC}" CXX="${CXX}" \
	CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" \
	INSTALL="/usr/bin/install -c ${_BINOWNGRP}" \
	INSTALL_DATA="${INSTALL_DATA}" \
	INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
	INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
	${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}
	@cd ${WRKSRC}/../lib && \
	${SETENV} ${MAKE_ENV} ${MAKE} \
	${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/Img
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
	@cd ${WRKSRC}/Img && \
	${INSTALL_DATA} *.gif *.png ${DOCSDIR}/Img
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
