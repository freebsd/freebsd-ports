# ex:ts=8
# New ports collection makefile for:	mboxstats
# Date created:			Oct 31 2003
# Whom:				clsung
#
# $FreeBSD$
#

PORTNAME=	mboxstats
PORTVERSION=	1.3
CATEGORIES=	mail
MASTER_SITES=	http://vanheusden.com/mboxstats/
EXTRACT_SUFX=	.tgz

MAINTAINER=	clsung@dragon2.net
COMMENT=	Creates top-10 lists of the messages in a mailbox

PLIST_FILES=	bin/mboxstats
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|ssize_t|size_t|g' ${WRKSRC}/io.h
	@${REINPLACE_CMD} -e 's|PATH_MAX|FILENAME_MAX|g' ${WRKSRC}/main.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mboxstats ${PREFIX}/bin

.include <bsd.port.mk>
