# New ports collection makefile for:	siag (Scheme In A Grid)
# Version required:	2.80
# Date created:		27 Jan 1998
# Whom:			ports@freebsd.org
#
# $Id: Makefile,v 1.12 1998/12/10 17:24:33 vanilla Exp $
#

DISTNAME=	siag-3.1.9
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.edu.stockholm.se/pub/siag/ \
		ftp://ftp.icm.edu.pl/site/siag/
#DISTFILES=	${DISTNAME}${EXTRACT_SUFX} tsiag-3.0.7.tar.gz

MAINTAINER=	ports@freebsd.org

LIB_DEPENDS=	Xaw3d.6:${PORTSDIR}/x11-toolkits/Xaw3d \
		Xpm.4:${PORTSDIR}/graphics/xpm \
		guile.4:${PORTSDIR}/lang/guile

BROKEN=	'installs into doc, not share/doc and needs more testing (probably simple)'
GNU_CONFIGURE=	yes
CONFIGURE_ENV+= LOCALBASE=${LOCALBASE}
USE_X_PREFIX=	yes

post-install:
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
