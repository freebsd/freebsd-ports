# New ports collection makefile for:    plplot
# Date created:         03 Oct 1997
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	plplot
PORTVERSION=	4.99j
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.uniovi.es/pub6/graphics/plotting/ \
		ftp://dino.ph.utexas.edu/plplot/distrib/alpha/ \
		ftp://ftp.che.utexas.edu/pub/graphics/
DISTNAME=	${PORTNAME}4p99j

MAINTAINER=	ports@FreeBSD.org

USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gcc=yes --with-double=yes
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

post-patch:
	@${PERL} -pi -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/src/*.c

post-install:
.if ${PORTOBJFORMAT} == "elf"
	${LN} -sf libplplotdX.so.4 ${PREFIX}/lib/libplplotdX.so
.else
	${LN} -sf libplplotdX.so.4.99 ${PREFIX}/lib/libplplotdX.so
.endif

.include <bsd.port.post.mk>
