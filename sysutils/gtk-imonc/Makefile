# New ports collection makefile for:	gtk-imonc
# Date Created:				26. October 2002
# Whom:					Steffen Vogelreuter
#
# $FreeBSD$
#

PORTNAME=	gtk-imonc
PORTVERSION=	0.3a
CATEGORIES=	sysutils
MASTER_SITES=	http://userpage.fu-berlin.de/~zeank/gtk-imonc/download/

MAINTAINER=	steffen@vogelreuter.de

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}
ALL_TARGET=	#empty
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12 gnomehier
USE_GNOMENG=	yes
USE_REINPLACE=	yes
USE_X_PREFIX=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|gtk-config|gtk12-config|g ; \
			      s|/usr/local|${X11BASE}|g' \
				${WRKSRC}/configure

.include <bsd.port.mk>
