# New ports collection makefile for:   mkfontalias
# Date created:        26 September 2001
# Whom:                Stijn Hoop <stijn@win.tue.nl>
#
# $FreeBSD$
#

PORTNAME=	mkfontalias
PORTVERSION=	0.3
CATEGORIES=	x11-fonts
MASTER_SITES=   http://home.c2i.net/dark/
DISTNAME=	mkfontalias.py
EXTRACT_SUFX=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python script to make fonts.alias files for X

DEPRECATED=	"No longer useful, master-site disappeared"
EXPIRATION_DATE="2004-10-01"

PLIST_FILES=	bin/mkfontalias
USE_PYTHON=	yes
USE_X_PREFIX=	yes

EXTRACT_CMD=		${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	${WRKSRC}

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

.ifndef WITH_DPI
DPI=		75
.else
DPI=		${WITH_DPI}
.endif

post-patch:
	${MV} ${WRKSRC}/mkfontalias.py ${WRKSRC}/mkfontalias.py.tmp
	${SED} -e "s,/usr/bin/python,${LOCALBASE}/bin/python," \
		-e "s#'75', '75'#'${DPI}', '${DPI}'#" \
		${WRKSRC}/mkfontalias.py.tmp > ${WRKSRC}/mkfontalias.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mkfontalias.py ${PREFIX}/bin/mkfontalias

.include <bsd.port.mk>
