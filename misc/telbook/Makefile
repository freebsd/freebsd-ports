# New ports collection makefile for:	telbook
# Date created:				19 May 2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$

PORTNAME=	telbook
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://home.arcor.de/kaffeetisch/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple telephone book

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Gtk.pm:${PORTSDIR}/x11-toolkits/p5-Gtk

NO_BUILD=	yes

DOC_FILES=	README

do-install:
		${INSTALL_SCRIPT} ${WRKSRC}/telbook ${PREFIX}/bin/
.ifndef (NOPORTDOCS)
		@${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
.for doc in ${DOC_FILES}
		@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
