# New ports collection makefile for:	dropbear
# Date created:				20 August 2003
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	dropbear
PORTVERSION=	0.37
CATEGORIES=	security ipv6
MASTER_SITES=	http://matt.ucc.asn.au/dropbear/releases/

MAINTAINER=	sheepkiller@cultdeadsheep.org
COMMENT=	An SSH 2 server, designed to be usable in small memory environments

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_REINPLACE=	YES

.if defined(IS_STATIC)
CONFIGURE_ENV=	LDFLAGS=-static
.endif

BIN=		dropbear dropbearkey dropbearconvert

post-configure:
	@${REINPLACE_CMD} -e "s,/etc/,${PREFIX}/etc/,g" ${WRKSRC}/options.h
	@${REINPLACE_CMD} -e "s,/usr/bin/X11/,${X11BASE}/,g" ${WRKSRC}/options.h
	@${REINPLACE_CMD} -e "s,^typedef int socklen_t,//typedef int socklen_t," \
		${WRKSRC}/includes.h

do-install:
.for bin in ${BIN}
	@${INSTALL_PROGRAM} ${WRKSRC}/${bin} ${PREFIX}/bin
.endfor
.if !defined(NOPORTDOC)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
