# ex:ts=8
# Ports collection makefile for:  hydra
# Date created:			  Tue Oct 08, 2002
# Whom:				  Laurent LEVIER (llevier@argosnet.com)
#
# $FreeBSD$
#

PORTNAME=	hydra
PORTVERSION=	2.2
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.thc.org/releases/ \
		${MASTER_SITE_PACKETSTORM}
MASTER_SITE_SUBDIR=	groups/thc

MAINTAINER=	llevier@argosnet.com
COMMENT=	Bruce Force Attack Utility working on multiple network services

PLIST_FILES=	bin/hydra
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|CC = gcc||; \
		s|-O2|${CFLAGS}|' \
		${WRKSRC}/Makefile.am

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/hydra ${PREFIX}/bin

.include <bsd.port.mk>
