# New ports collection makefile for: qsf
# Date created:		15 January 2004
# Whom:			liamfoy@sepulcrum.org
#
# $FreeBSD$
#

PORTNAME=	qsf
PORTVERSION=	1.0.18
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	qsf

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A small fast spam filter intended to be used with procmail

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_REINPLACE=	yes

MAN1=		qsf.1
MANCOMPRESSED=	yes
PLIST_FILES=	bin/qsf

OPTIONS=	GDBM "GDBM support" off \
		MYSQL "MySQL support" off \
		SQLITE2 "SQLite2 support" off

.include <bsd.port.pre.mk>

.if defined(WITH_GDBM)
LIB_DEPENDS+=	gdbm.3:${PORTSDIR}/databases/gdbm
CONFIGURE_ARGS+=	--with-gdbm=${LOCALBASE}
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}
.endif

.if defined(WITH_SQLITE2)
LIB_DEPENDS+=	sqlite.2:${PORTSDIR}/databases/sqlite2
CONFIGURE_ARGS+=	--with-sqlite=${LOCALBASE}
.endif

# not supported yet.
#.if defined(WITH_SQLITE3)
#.endif

post-patch:
	@${REINPLACE_CMD} -e 's/Linux/${OPSYS}/g' ${WRKSRC}/doc/quickref.1.in

.include <bsd.port.post.mk>
