# New ports collection makefile for:	enscript (letter)
# Date created:			24 Jul, 1997
# Whom:				kline
#
# $FreeBSD$
#

PORTNAME=	enscript-${PAPERSIZE}
PORTVERSION=	1.6.4
PORTREVISION=	1
CATEGORIES+=	print
MASTER_SITES=	http://people.ssh.com/mtr/genscript/
DISTNAME=	enscript-${PORTVERSION}

MAINTAINER?=	ports@FreeBSD.org
COMMENT=	ASCII to PostScript filter

# Work around configure issue
CC=

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--disable-nls --with-media=${PS}
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
MAKE_FLAGS=	WIDTH=${WIDTH} HEIGHT=${HEIGHT} A4_PAPERSIZE=${A4_PAPERSIZE} -f

INFO=		enscript
MAN1=		diffpp.1 enscript.1 sliceprint.1 states.1
STRIP=

# If you want to build a static binary, uncomment the following line
#LDFLAGS+=-static

PAPERSIZE?=	letter
PS!=		${ECHO} ${PAPERSIZE} | tr l L | tr a A

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
	@${ECHO} "Error: invalid value for PAPERSIZE: \"${PAPERSIZE}\""
	@${ECHO} "Possible values are:  a4 or letter or letterdj"
	@${FALSE}
.endif

post-install:
.for file in enscript mkafmmap states
	${STRIP_CMD} ${PREFIX}/bin/${file}
.endfor

.include <bsd.port.mk>
