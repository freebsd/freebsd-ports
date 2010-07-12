# New ports collection makefile for:	enscript (letter)
# Date created:			24 Jul, 1997
# Whom:				kline
#
# $FreeBSD$
#

PORTNAME=	enscript
PORTVERSION=	1.6.4
PORTREVISION=	3
CATEGORIES+=	print
MASTER_SITES=	http://www.codento.com/people/mtr/genscript/
PKGNAMESUFFIX=	-${PAPERSIZE}
DISTNAME=	enscript-${PORTVERSION}

MAINTAINER?=	rafan@FreeBSD.org
COMMENT=	ASCII to PostScript filter

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-nls --with-media=${PS}

INFO=		enscript
MAN1=		diffpp.1 enscript.1 sliceprint.1 states.1

PAPERSIZE?=	letter

.if ${PAPERSIZE} == a4
PS=A4
CONFLICTS=	enscript-letter-* enscript-letterdj-*
.elif ${PAPERSIZE} == letter
PS=Letter
CONFLICTS=	enscript-a4-* enscript-letterdj-*
.elif ${PAPERSIZE} == letterdj
PS=Letterdj
CONFLICTS=	enscript-a4-* enscript-letter-*
.else
.BEGIN:
	@${ECHO} "Error: invalid value for PAPERSIZE: \"${PAPERSIZE}\""
	@${ECHO} "Possible values are:  a4, letter, or letterdj"
	@${FALSE}
.endif

.include <bsd.port.mk>
