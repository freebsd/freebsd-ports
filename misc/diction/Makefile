# New ports collection makefile for:	diction
# Date created:		2 August 1998
# Whom:			J Han <hjh@best.com>
#
# $FreeBSD$
#

PORTNAME=	diction
PORTVERSION=	1.02
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU diction and style

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/diction bin/style share/diction/C share/diction/de \
		share/diction/en
PLIST_DIRS=	share/diction

MAN1=		diction.1 style.1

post-patch:
	${REINPLACE_CMD} -e "s,-pedantic,," ${WRKSRC}/configure

.include <bsd.port.mk>
