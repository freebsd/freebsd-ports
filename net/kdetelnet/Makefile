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

BUILD_DEPENDS=	moc:${PORTSDIR}/x11-toolkits/qt142
LIB_DEPENDS=	qt.2:${PORTSDIR}/x11-toolkits/qt142 \
		gif.5:${PORTSDIR}/graphics/giflib \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		kdecore.2:${PORTSDIR}/x11/kdelibs11 \
		kdeui.2:${PORTSDIR}/x11/kdelibs11

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	"--prefix=$(PREFIX)"
CONFIGURE_ENV=	CXXFLAGS="$(CFLAGS)" \
		INSTALL_SCRIPT="install -c -m 555"

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/HTML/en/ktelnet
	${MKDIR} ${PREFIX}/share/doc/HTML/de/ktelnet
	${INSTALL_MAN} ${WRKSRC}/doc/index.en.html \
		${PREFIX}/share/doc/HTML/en/ktelnet/index.html
	${INSTALL_MAN} ${WRKSRC}/doc/index.de.html \
		${PREFIX}/share/doc/HTML/de/ktelnet/index.html
.endif

.include <bsd.port.mk>
