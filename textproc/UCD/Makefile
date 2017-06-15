# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	UCD
PORTVERSION=	9.0.0
CATEGORIES=	textproc
MASTER_SITES=	http://www.unicode.org/Public/zipped/${PORTVERSION}/:src\
		ftp://www.unicode.org/Public/zipped/${PORTVERSION}/:src	\
		http://www.unicode.org/:lic
DISTFILES=	${PORTNAME}.zip:src	\
		copyright.html:lic
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}
EXTRACT_ONLY=

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Unicode Character Database

LICENSE=	Unicode_License_Agreement
LICENSE_NAME=	Unicode License Agreement
LICENSE_FILE=	${_DISTDIR}/copyright.html
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

NO_ARCH=	yes
NO_BUILD=	yes

DATADIR=	${PREFIX}/share/unicode/ucd

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${STAGEDIR}${DATADIR} &&	\
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${PORTNAME}.zip ${EXTRACT_AFTER_ARGS})

.include <bsd.port.mk>
