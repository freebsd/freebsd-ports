# Created by: Clement Laforet <sheepkiller@cultdeadsheep.org>
# $FreeBSD$

PORTNAME=	dropbear
PORTVERSION=	2015.68
CATEGORIES=	security ipv6
MASTER_SITES=	http://matt.ucc.asn.au/dropbear/releases/

MAINTAINER=	pkubaj@riseup.net
COMMENT=	SSH 2 server, designed to be usable in small memory environments

GNU_CONFIGURE=	yes
USES=	gmake tar:bzip2

USE_RC_SUBR=	${PORTNAME}

OPTIONS_DEFINE=	STATIC

STATIC_LDFLAGS=	-static

post-patch:
	@${REINPLACE_CMD} -e "s,_PRIV_FILENAME \"/etc/,_PRIV_FILENAME \"${PREFIX}/etc/,g; \
		s,/usr/bin/X11/,${LOCALBASE}/,g" ${WRKSRC}/options.h
	@${REINPLACE_CMD} -e "s,sys/dir.h,dirent.h," ${WRKSRC}/*.[ch]
	@${REINPLACE_CMD} -e "s,make clean,\$${MAKE} clean," \
				${WRKSRC}/libtomcrypt/Makefile.in

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/dropbear
	${INSTALL_PROGRAM} ${WRKSRC}/dbclient ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/dropbearconvert ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/dropbearkey ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/dropbear ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/dropbearconvert.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/dropbearkey.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/dbclient.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/dropbear.8 ${STAGEDIR}${MAN8PREFIX}/man/man8

.include <bsd.port.mk>
