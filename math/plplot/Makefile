# New ports collection makefile for:    plplot
# Version required:     4p99j
# Date created:         03 Oct 1997
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=       plplot4p99j
PKGNAME=	plplot-4.99j
CATEGORIES=	math
MASTER_SITES=	ftp://dino.ph.utexas.edu/plplot/distrib/alpha/ \
		ftp://ftp.u-aizu.ac.jp/pub/misc/tools/plot/plplot/distrib/alpha/ \
		ftp://ftp.che.utexas.edu/pub/graphics/ \
		ftp://ftp.uniovi.es/pub6/graphics/plotting/

MAINTAINER=	ports@FreeBSD.org

USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --with-gcc=yes --with-double=yes

.include <bsd.port.pre.mk>

post-patch:
	@perl -pi.bak -e "s|/usr/local/plplot/lib|${PREFIX}/lib/plplot|g;" \
		${WRKSRC}/src/plctrl.c

post-install:
.if ${PORTOBJFORMAT} == "elf"
	${LN} -sf libplplotdX.so.4 ${PREFIX}/lib/libplplotdX.so
.else
	${LN} -sf libplplotdX.so.4.99 ${PREFIX}/lib/libplplotdX.so
.endif

.include <bsd.port.post.mk>
