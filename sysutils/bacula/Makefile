# New ports collection makefile for:	bacula
# Date created:				24 February 2003
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bacula
PORTVERSION=	1.30a
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	bacula

MAINTAINER=	demon@FreeBSD.org
COMMENT=	The network backup solution

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-smartalloc \
		--with-working-dir=/var/db/bacula

.if defined(WITH_SQLITE)
CONFIGURE_ARGS+=	--with-sqlite=${LOCALBASE}
LIB_DEPENDS+=	sqlite.2:${PORTSDIR}/databases/sqlite
DBTYPE=		sqlite
.else
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}
LIB_DEPENDS+=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client
DBTYPE=		mysql
.endif

PLIST_SUB+=	DBTYPE=${DBTYPE}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/html-manual
	${INSTALL_DATA} ${WRKSRC}/doc/bacula.pdf ${DOCSDIR}
	cd ${WRKSRC}/doc && ${FIND} html-manual | \
		cpio -pdm -L -R root:wheel ${DOCSDIR}
.endif

.include <bsd.port.mk>
