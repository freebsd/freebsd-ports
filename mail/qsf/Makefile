# New ports collection makefile for: qsf
# Date created:		15 January 2004
# Whom:			liamfoy@sepulcrum.org
#
# $FreeBSD$
#

PORTNAME=	qsf
PORTVERSION=	1.1.0
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	qsf

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A small fast spam filter intended to be used with procmail

USE_BZIP2=	yes
USE_GETOPT_LONG=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		qsf.1
PLIST_FILES=	bin/qsf

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

OPTIONS=	GDBM "GDBM support" off \
		MYSQL "MySQL support" off \
		SQLITE2 "SQLite2 support" off

.include <bsd.port.pre.mk>

.if defined(WITH_GDBM)
LIB_DEPENDS+=	gdbm.3:${PORTSDIR}/databases/gdbm
.else
CONFIGURE_ARGS+=	--without-gdbm
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
.else
CONFIGURE_ARGS+=	--without-mysql
.endif

.if defined(WITH_SQLITE2)
LIB_DEPENDS+=	sqlite.2:${PORTSDIR}/databases/sqlite2
.else
CONFIGURE_ARGS+=	--without-sqlite
.endif

# not supported yet.
#.if defined(WITH_SQLITE3)
#.endif

post-patch:
	@${REINPLACE_CMD} -e 's/Linux/${OPSYS}/g' ${WRKSRC}/doc/quickref.1.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qsf ${PREFIX}/bin/qsf
	${INSTALL_MAN} ${WRKSRC}/doc/quickref.1 ${MANPREFIX}/man/man1/qsf.1

.include <bsd.port.post.mk>
