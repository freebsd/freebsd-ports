# Ports collection makefile for:  foremost
# Date created:			  16 June 2004
# Whom:				  Yonatan <Yonatan@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	foremost
PORTVERSION=	0.69
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	yonatan@xpert.com
COMMENT=	Console program to recover files based on their headers and footers

USE_GMAKE=	yes
ALL_TARGET=	openbsd
MAN1=		foremost.1
USE_REINPLACE=	yes

PLIST_FILES=	bin/foremost etc/foremost.conf.sample

post-patch:
	@${REINPLACE_CMD} -e 's|PREFIX|${PREFIX}|' ${WRKSRC}/foremost.h

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/foremost
	@${INSTALL} -Cm 644 ${WRKSRC}/foremost.conf ${PREFIX}/etc/foremost.conf.sample

.include <bsd.port.mk>
