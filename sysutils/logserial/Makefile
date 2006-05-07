# New ports collection makefile for:	logserial
# Date created:				25 November 2005
# Whom:					nastya
#
# $FreeBSD$
#

PORTNAME=	logserial
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.rsu.ru/pub/sysutils/unix/

MAINTAINER=	nastya@rsu.ru
COMMENT=	Daemon logging data from serial port

USE_RC_SUBR=	yes

MAN8=		logserial.8
MANCOMPRESSED=	yes

PLIST_FILES=	bin/logserial \
		etc/rc.d/logserial.sh \

post-patch:
	@${REINPLACE_CMD} ${SUB_LIST:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} ${WRKSRC}/logserial.sh

.include <bsd.port.mk>
