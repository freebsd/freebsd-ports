# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	qpxtool
PORTVERSION=	0.7.2
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTVERSION:C/\.[^.]*$/.x/}/${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI for testing CD/DVD quality and transfer rate

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png

USES=		gmake tar:bzip2
USE_QT4=	qmake_build moc_build rcc_build linguisttools_build \
		corelib gui network sql
QT_NONSTANDARD=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	PREFIX=${PREFIX}
USE_LDCONFIG=	yes

OPTIONS_GROUP=		DB
OPTIONS_GROUP_DB=	SQLITE MYSQL PGSQL
OPTIONS_DEFAULT=	SQLITE

SQLITE_USE=	QT4=sql-sqlite3_run
MYSQL_USE=	QT4=sql-mysql_run
PGSQL_USE=	QT4=sql-pgsql_run

post-configure:
	@${REINPLACE_CMD} -e 's|$$(QMAKE4)|& ${QMAKE_AGRS}|' \
		${WRKSRC}/gui/Makefile
	@${REINPLACE_CMD} -e 's|S_ISBLK|S_ISCHR|' \
		${WRKSRC}/lib/qpxtransport/qpx_mmc.cpp

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/* \
		${STAGEDIR}${PREFIX}/sbin/pxfw

.include <bsd.port.mk>
