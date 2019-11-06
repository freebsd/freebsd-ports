# Created by: nsayer@FreeBSD.org
# $FreeBSD$

PORTNAME=	yaunc
PORTVERSION=	1.02
CATEGORIES=	misc
MASTER_SITES=	http://www.redterror.net/code/yaunc/

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	Yet another uptimes.net client

BROKEN=		unfetchable

ALL_TARGET=	bsd
CFLAGS+=	-DCONFFILE=\\\"${STAGEDIR}${PREFIX}/etc/yaunc.conf\\\"

PLIST_FILES=	bin/yaunc \
		etc/yaunc.conf.sample \
		man/man1/yaunc.1.gz

USE_RC_SUBR=	yaunc

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${STAGEDIR}${PREFIX}|g" ${WRKSRC}/yaunc.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/yaunc ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/yaunc.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_DATA} -m 600 ${WRKSRC}/yaunc.conf ${STAGEDIR}${PREFIX}/etc/yaunc.conf.sample

.include <bsd.port.mk>
