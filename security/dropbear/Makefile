# New ports collection makefile for:	dropbear
# Date created:				20 August 2003
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	dropbear
PORTVERSION=	2012.55
CATEGORIES=	security ipv6
MASTER_SITES=	http://matt.ucc.asn.au/dropbear/releases/

MAINTAINER=	ak@FreeBSD.org
COMMENT=	An SSH 2 server, designed to be usable in small memory environments

GNU_CONFIGURE=	YES
USE_BZIP2=	YES
USE_GMAKE=	YES

USE_RC_SUBR=	${PORTNAME}

PLIST_FILES=	bin/dbclient \
		bin/dropbearkey \
		bin/dropbearconvert \
		sbin/dropbear

PLIST_DIRSTRY=	etc/dropbear

OPTIONS_DEFINE=	STATIC

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSTATIC}
LDFLAGS+=	-static
.endif

post-patch:
	@${REINPLACE_CMD} -e "s,_PRIV_FILENAME \"/etc/,_PRIV_FILENAME \"${PREFIX}/etc/,g; \
		s,/usr/bin/X11/,${LOCALBASE}/,g" ${WRKSRC}/options.h
	@${REINPLACE_CMD} -e "s,sys/dir.h,dirent.h," ${WRKSRC}/*.[ch]
	@${REINPLACE_CMD} -e "s,make clean,\$${MAKE} clean," \
				${WRKSRC}/libtomcrypt/Makefile.in

post-install:
	@${MKDIR} ${PREFIX}/etc/dropbear

.include <bsd.port.mk>
