# New ports collection makefile for:   surfraw
# Date created:                2000-08-03
# Whom:                        Christian Weisgerber <naddy@mips.inka.de>
#
# $FreeBSD$

PORTNAME=	surfraw
PORTVERSION=	2.2.5
CATEGORIES=	www
MASTER_SITES=	http://surfraw.alioth.debian.org/dist/

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	Command line interface to popular WWW search engines

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PERL5=	yes

MAN1=	surfraw-update-path.1 \
	surfraw.1 \
	elvi.1sr \
	opensearch-discover.1 \
	opensearch-genquery.1

post-install:
	${MKDIR} ${PREFIX}/share/examples/surfraw
	${INSTALL_DATA} ${WRKSRC}/surfraw.conf ${PREFIX}/share/examples/surfraw
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
