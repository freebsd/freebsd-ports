# New ports collection makefile for:	telbook
# Date created:				19 May 2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$

PORTNAME=	telbook
PORTVERSION=	0.4
CATEGORIES=	misc
MASTER_SITES=	http://home.arcor.de/kaffeetisch/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple telephone book

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Gtk2.pm:${PORTSDIR}/x11-toolkits/p5-Gtk2

NO_BUILD=	yes
USE_BZIP2=	yes

PORTDOCS=	README
PLIST_FILES=	bin/telbook

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/telbook ${PREFIX}/bin
.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
