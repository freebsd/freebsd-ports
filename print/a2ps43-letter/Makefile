# ex:ts=8
# New ports collection makefile for:    a2ps
# Date created:         6 November 1994
# Whom:                 jmz & David O'Brien (obrien@cs.ucdavis.edu)
#
# $FreeBSD$
#

PORTNAME=	a2ps-${PAPERSIZE}
PORTVERSION=	4.3
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.imag.fr/archive/postscript/format.translators/
DISTNAME=	a2ps.V4.3

MAINTAINER=	obrien@FreeBSD.org

NO_LATEST_LINK=	yes
MAKE_FLAGS?=	WIDTH=${WIDTH} HEIGHT=${HEIGHT} A4_PAPERSIZE=${A4_PAPERSIZE} -f
NO_WRKSUBDIR=	yes
MAN1=		a2ps.1

PAPERSIZE?=	letter

.if ${PAPERSIZE} == letter
WIDTH=8.5
HEIGHT=11.0
A4_PAPERSIZE=0
.elif ${PAPERSIZE} == a4
WIDTH=8.27
HEIGHT=11.64
A4_PAPERSIZE=1
.else
.BEGIN:
	@${ECHO} "Error: invalid value for PAPERSIZE: \"${PAPERSIZE}\""
	@${ECHO} "Possible values are:  a4 or letter"
	@${FALSE}
.endif

pre-install:
	@${MKDIR} ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/man/man1
	@(cd ${WRKSRC}; make install.man)

post-install:
	strip ${PREFIX}/bin/a2ps

.include <bsd.port.mk>
