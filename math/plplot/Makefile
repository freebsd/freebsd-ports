# New ports collection makefile for:    plplot
# Version required:     4p99j
# Date created:         03 Oct 1997
# Whom:                 Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id: Makefile,v 1.4 1997/12/24 01:21:31 alex Exp $
#

DISTNAME=       plplot4p99j
PKGNAME=	plplot-4.99j
CATEGORIES=	math
MASTER_SITES=	ftp://dino.ph.utexas.edu/plplot/distrib/alpha/

MAINTAINER=	tg@FreeBSD.ORG

GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --with-gcc=yes --with-double=yes

post-patch:
	@perl -pi.bak -e "s|/usr/local/plplot/lib|${PREFIX}/lib/plplot|g;" \
		${WRKSRC}/src/plctrl.c

post-install:
	if [ "${PORTOBJFORMAT}" = "elf" ]; then \
		${LN} -sf libplplotdX.so.4 ${PREFIX}/lib/libplplotdX.so; \
	else \
		${LN} -sf libplplotdX.so.4.99 ${PREFIX}/lib/libplplotdX.so; \
	fi

.include <bsd.port.mk>
