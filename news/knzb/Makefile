# New ports collection makefile for:   knzb
# Date created:        15 January 2005
# Whom: Tim Welch <twelch@thepentagon.org>
#
# $FreeBSD$
#

PORTNAME=	knzb
PORTVERSION=	0.5
CATEGORIES=	news
MASTER_SITES=	http://dmp.org.uk/linux/knzb/download/

MAINTAINER=	twelch@thepentagon.org
COMMENT=	KDE binary newsgroup download tool

RUN_DEPENDS=	${LOCALBASE}/bin/uudeview:${PORTSDIR}/converters/uudeview

USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/knzb
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_QT_VER=	3
USE_KDELIBS_VER=	3

pre-configure:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${TOUCH} -f

.include <bsd.port.mk>
