# Created by: pfg
# $FreeBSD$

PORTNAME=	fortune-mod-psalms
PORTVERSION=	1.0
CATEGORIES=	misc
MASTER_SITES=	LOCAL/pfg/catholic
DISTNAME=	${PORTNAME}

MAINTAINER=	pfg@FreeBSD.org
COMMENT=	Psalms from the Douai Bible in fortune file format

LICENSE=	CC0-1.0		# AKA Public Domain

NO_ARCH=	yes
NO_WRKSUBDIR=	yes

SUB_FILES=	pkg-message
PLIST_FILES=	share/games/fortune/psalms share/games/fortune/psalms.dat

.if exists(/usr/games/strfile)
_STRFILE=	/usr/games/strfile
.elif exists(/usr/bin/strfile)
_STRFILE=	/usr/bin/strfile
.endif

.if !defined(_STRFILE)
NO_BUILD=	yes
.else
do-build:
	${RM} ${WRKSRC}/psalms.dat
	(cd ${WRKSRC} && ${_STRFILE} -C psalms)
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/games/fortune
	${INSTALL_DATA} ${WRKSRC}/psalms*	\
	   ${STAGEDIR}${PREFIX}/share/games/fortune

.include <bsd.port.mk>
