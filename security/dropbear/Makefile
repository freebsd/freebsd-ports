# Created by: Clement Laforet <sheepkiller@cultdeadsheep.org>
# $FreeBSD$

PORTNAME=	dropbear
PORTVERSION=	2013.58
CATEGORIES=	security ipv6
MASTER_SITES=	http://matt.ucc.asn.au/dropbear/releases/

MAINTAINER=	ak@FreeBSD.org
COMMENT=	SSH 2 server, designed to be usable in small memory environments

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USES=	gmake

USE_RC_SUBR=	${PORTNAME}

PLIST_FILES=	bin/dbclient \
		bin/dropbearkey \
		bin/dropbearconvert \
		sbin/dropbear \
		man/man1/dbclient.1.gz \
		man/man8/dropbear.8.gz \
		man/man8/dropbearkey.8.gz

PLIST_DIRSTRY=	etc/dropbear

OPTIONS_DEFINE=	STATIC

STATIC_LDFLAGS=	-static

post-patch:
	@${REINPLACE_CMD} -e "s,_PRIV_FILENAME \"/etc/,_PRIV_FILENAME \"${PREFIX}/etc/,g; \
		s,/usr/bin/X11/,${LOCALBASE}/,g" ${WRKSRC}/options.h
	@${REINPLACE_CMD} -e "s,sys/dir.h,dirent.h," ${WRKSRC}/*.[ch]
	@${REINPLACE_CMD} -e "s,make clean,\$${MAKE} clean," \
				${WRKSRC}/libtomcrypt/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/dropbear
	${INSTALL_MAN} ${WRKSRC}/dbclient.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/dropbear.8 ${STAGEDIR}${MAN1PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/dropbearkey.8 ${STAGEDIR}${MAN1PREFIX}/man/man8

.include <bsd.port.mk>
