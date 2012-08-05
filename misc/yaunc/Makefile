# New ports collection makefile for:	yaunc
# Date created:		5 March 2000
# Whom:			nsayer@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	yaunc
PORTVERSION=	1.02
CATEGORIES=	misc
MASTER_SITES=	http://www.redterror.net/code/yaunc/

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	Yet another uptimes.net client

ALL_TARGET=	bsd
CFLAGS+=	-DCONFFILE=\\\"${PREFIX}/etc/yaunc.conf\\\"

PLIST_FILES=	bin/yaunc \
		etc/yaunc.conf.sample

USE_RC_SUBR=	yaunc

MAN1=		yaunc.1

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/yaunc.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/yaunc ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/yaunc.1 ${MANPREFIX}/man/man1
	${INSTALL_DATA} -m 600 ${WRKSRC}/yaunc.conf ${PREFIX}/etc/yaunc.conf.sample

.include <bsd.port.mk>
