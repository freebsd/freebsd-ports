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
USE_GMAKE=	yes

USE_RC_SUBR=	${PORTNAME}

PLIST_FILES=	bin/dbclient \
		bin/dropbearkey \
		bin/dropbearconvert \
		sbin/dropbear

PLIST_DIRSTRY=	etc/dropbear

MAN1=	dbclient.1
MAN8=	dropbear.8 dropbearkey.8

OPTIONS_DEFINE=	STATIC

NO_STAGE=	yes
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
	${INSTALL_MAN} ${MAN1:S|^|${WRKSRC}/|} ${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${MAN8:S|^|${WRKSRC}/|} ${MAN8PREFIX}/man/man8

.include <bsd.port.mk>
