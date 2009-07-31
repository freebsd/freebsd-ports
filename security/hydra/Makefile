# ex:ts=8
# Ports collection makefile for:  hydra
# Date created:			  Tue Oct 08, 2002
# Whom:				  Laurent LEVIER (llevier@argosnet.com)
#
# $FreeBSD$
#

PORTNAME=	hydra
PORTVERSION=	5.4
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	http://www.thc.org/releases/ \
		${MASTER_SITE_PACKETSTORM}
MASTER_SITE_SUBDIR=	groups/thc
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	llevier@argosnet.com
COMMENT=	Brute force attack utility working on multiple network services

NO_LATEST_LINK=	yes
PLIST_FILES=	bin/hydra bin/xhydra
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20
USE_OPENSSL=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-src

post-patch:
	@${REINPLACE_CMD} -e 's|CC = gcc||; \
		s|-O2|${CFLAGS}|; s|md4\..||g' \
		${WRKSRC}/Makefile.am

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/hydra ${WRKSRC}/hydra-gtk/src/xhydra ${PREFIX}/bin

.include <bsd.port.mk>
