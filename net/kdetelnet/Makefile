# New ports collection makefile for:   ktelnet
# Version required:	0.61
# Date created:		14 May 1998
# Whom:			Hans Petter Bieker <hanspb@persbraten.vgs.no>
#
# $FreeBSD$
#

DISTNAME=	ktelnet-0.61
CATEGORIES=	net kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/1.1/apps/network
EXTRACT_SUFX=	.tgz

MAINTAINER=	hanspb@persbraten.vgs.no

LIB_DEPENDS=	kdecore.2:${PORTSDIR}/x11/kdelibs11

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CXXFLAGS="$(CXXFLAGS)" \
		INSTALL_SCRIPT="$(INSTALL_SCRIPT)"
USE_QT=		yes

post-install:
.if !defined(NOPORTDOCS)
.for DIR in en de
	@${MKDIR} ${PREFIX}/share/doc/HTML/${DIR}/ktelnet
	@${INSTALL_MAN} ${WRKSRC}/doc/index.${DIR}.html \
	    ${PREFIX}/share/doc/HTML/${DIR}/ktelnet/index.html
.endfor
.endif

.include <bsd.port.mk>
