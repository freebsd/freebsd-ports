# New ports collection makefile for:   knzb
# Date created:        15 January 2005
# Whom: Tim Welch <twelch@thepentagon.org>
#
# $FreeBSD$
#

PORTNAME=	knzb
PORTVERSION=	0.3
CATEGORIES=	news
MASTER_SITES=	http://dmp.org.uk/linux/knzb/download/

MAINTAINER=	ports@freebsd.org
COMMENT=	KDE binary newsgroup download tool

USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/knzb
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_QT_VER=	3
USE_KDELIBS_VER=	3
NO_INSTALL_MANPAGES=	yes

pre-configure:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${TOUCH} -f

.include <bsd.port.mk>
