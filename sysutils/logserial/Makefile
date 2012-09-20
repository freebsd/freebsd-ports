# Created by: nastya <nastya@rsu.ru>
# $FreeBSD$

PORTNAME=	logserial
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.rsu.ru/pub/sysutils/unix/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Daemon logging data from serial port

DEPRECATED=	No more public distfiles
EXPIRATION_DATE=	2012-10-20

USE_RC_SUBR=	yes

MAN8=		logserial.8
MANCOMPRESSED=	yes

PLIST_FILES=	bin/logserial \
		etc/rc.d/logserial.sh \

post-patch:
	@${REINPLACE_CMD} ${SUB_LIST:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} ${WRKSRC}/logserial.sh

.include <bsd.port.mk>
