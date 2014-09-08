# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	libcsv
PORTVERSION=	3.0.3
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small, simple and fast CSV library

LICENSE=	LGPL21

OPTIONS_DEFINE=	PROFILE

MAKEFILE=	Makefile.lib
USES=		uidfix
USE_LDCONFIG=	yes

PLIST_SUB=	SHLIB_MAJOR="${SHLIB_MAJOR}"

SHLIB_MAJOR=	3

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPROFILE}
PLIST_SUB+=	PROFILE=""
.else
MAKE_ENV+=	NO_PROFILE=true
PLIST_SUB+=	PROFILE="@comment "
.endif

do-configure:
	@${SED} -e 's|%%SHLIB_MAJOR%%|${SHLIB_MAJOR}|' \
		< ${FILESDIR}/Makefile > ${WRKSRC}/${MAKEFILE}

.include <bsd.port.mk>
