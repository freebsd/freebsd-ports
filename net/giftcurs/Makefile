# New ports collection makefile for:	giFTcurs
# Date created:		2003-09-04
# Whom:			Stefan Ehmann <shoesoft@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	giFTcurs
PORTVERSION=	0.6.2
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	giftcurs

MAINTAINER=	shoesoft@gmx.net
COMMENT=	A cursed frontend to the giFT daemon

RUN_DEPENDS=	${LOCALBASE}/bin/giftd:${PORTSDIR}/net/gift

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20

MAN1=	giFTcurs.1
MAN5=	giFTcurs.conf.5

DOC_FILES=	AUTHORS COPYING ChangeLog \
		INSTALL NEWS README TODO

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
