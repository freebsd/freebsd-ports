# New ports collection makefile for:	enscript (letter)
# Date created:			24 Jul, 1997
# Whom:				kline
#
# $FreeBSD$
#

PORTNAME=	enscript-${PAPERSIZE}
PORTVERSION=	1.6.1
PORTREVISION=	2
CATEGORIES+=	print
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	enscript
DISTNAME=	enscript-${PORTVERSION}

MAINTAINER=	kline@thought.org
COMMENT=	ASCII-to-PostScript filter

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--disable-nls --with-media=${PS}
MAKE_FLAGS=	WIDTH=${WIDTH} HEIGHT=${HEIGHT} A4_PAPERSIZE=${A4_PAPERSIZE} -f

MAN1=		diffpp.1 enscript.1 sliceprint.1 states.1
STRIP=

# If you want to build a static binary, uncomment the following line
#LDFLAGS+=-static

PAPERSIZE?=	letter
PS!=		echo ${PAPERSIZE} | tr l L | tr a A

.if ${PAPERSIZE} == a4
WIDTH=8.27
HEIGHT=11.64
A4_PAPERSIZE=1
.elif ${PAPERSIZE} == letter
WIDTH=8.5
HEIGHT=11.0
A4_PAPERSIZE=0
.elif ${PAPERSIZE} != letterdj
.BEGIN:
	@${EHCO} "Error: invalid value for PAPERSIZE: \"${PAPERSIZE}\""
	@${EHCO} "Possible values are:  a4 or letter or letterdj"
	@${FALSE}
.endif

post-install:
.for file in enscript mkafmmap states
	${STRIP_CMD} ${PREFIX}/bin/${file}
.endfor

.include <bsd.port.mk>
