# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	CLDR
PORTVERSION=	36.0
CATEGORIES=	textproc
MASTER_SITES=	https://unicode.org/Public/cldr/${PORTVERSION:R}/:src	\
		http://www.unicode.org/:lic
DISTFILES=	${SRCFILE}:src	\
		copyright.html:lic
EXTRACT_ONLY=

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Unicode Common Locale Data Repository

LICENSE=	Unicode_License_Agreement
LICENSE_NAME=	Unicode License Agreement
LICENSE_FILE=	${_DISTDIR}/copyright.html
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

SRCFILE=	${PORTNAME:tl}-common-${PORTVERSION}.zip

NO_ARCH=	yes
NO_BUILD=	yes

DATADIR=	${PREFIX}/share/unicode/cldr

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${STAGEDIR}${DATADIR} &&	\
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${SRCFILE} ${EXTRACT_AFTER_ARGS})

.include <bsd.port.mk>
