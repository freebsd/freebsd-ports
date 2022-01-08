# Created by: Thierry Thomas <thierry@pompo.net>

PORTNAME=	UCD
PORTVERSION=	14.0.0
CATEGORIES=	textproc
MASTER_SITES=	https://www.unicode.org/Public/zipped/${DISTVERSION}/:src	\
		https://raw.githubusercontent.com/unicode-org/unihan-database/f1e8e08a138bc7e834958c8d50d26ec4bca305d3/:lic
DISTFILES=	${PORTNAME}.zip:src	\
		LICENSE.md:lic
DIST_SUBDIR=	unicode-${PORTNAME}/${DISTVERSION}
EXTRACT_ONLY=

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Unicode Character Database

LICENSE=	Unicode_License_Agreement
LICENSE_NAME=	Unicode License Agreement
LICENSE_FILE=	${_DISTDIR}/LICENSE.md
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

OPTIONS_DEFINE=	HAN
OPTIONS_DEFAULT=HAN
OPTIONS_SUB=	yes
HAN_DESC=	Unified Han database of Hanzi/Kanji/Hanja Chinese characters

NO_ARCH=	yes
NO_BUILD=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MHAN}
DISTFILES+=	Unihan.zip:src
.endif

DATADIR=	${PREFIX}/share/unicode/ucd

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${STAGEDIR}${DATADIR} &&	\
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${PORTNAME}.zip ${EXTRACT_AFTER_ARGS})
.if ${PORT_OPTIONS:MHAN}
	(cd ${STAGEDIR}${DATADIR} &&	\
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/Unihan.zip ${EXTRACT_AFTER_ARGS})
	# Gucharmap also needs this zipfile
	${INSTALL_DATA} ${_DISTDIR}/Unihan.zip ${STAGEDIR}${DATADIR}
.endif

.include <bsd.port.mk>
