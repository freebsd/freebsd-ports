# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	qpxtool
PORTVERSION=	0.7.2
PORTREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTVERSION:C/\.[^.]*$/.x/}/${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI for testing CD/DVD quality and transfer rate

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

BROKEN_aarch64=		fails to compile: qpx_mmc_defs.h:608:4: constant expression evaluates to -1 which cannot be narrowed to type 'char'
BROKEN_armv6=		fails to compile: qpx_mmc_defs.h:608:4: constant expression evaluates to -1 which cannot be narrowed to type 'char'
BROKEN_armv7=		fails to compile: qpx_mmc_defs.h:608:4: constant expression evaluates to -1 which cannot be narrowed to type 'char'

LIB_DEPENDS=	libpng.so:graphics/png

USES=		gmake qmake:no_env qt:4 tar:bzip2
USE_QT=		qmake_build moc_build rcc_build linguisttools_build \
		corelib gui network sql
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	PREFIX=${PREFIX}
USE_LDCONFIG=	yes

OPTIONS_GROUP=		DB
OPTIONS_GROUP_DB=	SQLITE MYSQL PGSQL
OPTIONS_DEFAULT=	SQLITE

SQLITE_USES=	qt:4
SQLITE_USE=	QT=sql-sqlite3_run
MYSQL_USES=	qt:4
MYSQL_USE=	QT=sql-mysql_run
PGSQL_USES=	qt:4
PGSQL_USE=	QT=sql-pgsql_run

post-configure:
	@${REINPLACE_CMD} -e 's|$$(QMAKE4)|& ${QMAKE_AGRS}|' \
		${WRKSRC}/gui/Makefile
	@${REINPLACE_CMD} -e 's|S_ISBLK|S_ISCHR|' \
		${WRKSRC}/lib/qpxtransport/qpx_mmc.cpp

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/* \
		${STAGEDIR}${PREFIX}/sbin/pxfw

.include <bsd.port.mk>
