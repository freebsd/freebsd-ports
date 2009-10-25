# New ports collection makefile for:	minised
# Date created:		2 September 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	minised
PORTVERSION=	1.13
CATEGORIES=	textproc
MASTER_SITES=	http://dl.exactcode.de/oss/minised/ CENKES \
		http://people.freebsd.org/~wen/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Smaller, cheaper, faster sed implementation

ALL_TARGET=	${PORTNAME}
PLIST_FILES=	bin/${PORTNAME}
MAN1=		${PORTNAME}.1

post-patch:
	@${REINPLACE_CMD} -e 's/LFLAGS/LDFLAGS/' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
