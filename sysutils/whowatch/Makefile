# New ports collection makefile for:	whowatch
# Date created:		12 June 2000
# Whom:			Daniel Harris <dannyboy@subdimension.com>
#
# $FreeBSD$
#

PORTNAME=	whowatch
PORTVERSION=	1.4
CATEGORIES=	sysutils
MASTER_SITES=	http://wizard.ae.krakow.pl/~mike/download/ \
		${MASTER_SITE_PACKETSTORM}
MASTER_SITE_SUBDIR=	UNIX/IDS

MAINTAINER=	dannyboy@FreeBSD.org
COMMENT=	Displays information in real time about users currently logged on

USE_REINPLACE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500014
pre-patch:
	@${FIND} ${WRKSRC} -name 'proc????.c' | ${XARGS} ${REINPLACE_CMD} -E \
		-e 's/kp_.?proc\.._/ki_/ ; s/pcred\.p_//'
.endif

GNU_CONFIGURE=	yes

MAN1=		whowatch.1
PLIST_FILES=	bin/whowatch

.include <bsd.port.post.mk>
