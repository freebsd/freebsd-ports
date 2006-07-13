# New ports collection makefile for:	unrtf
# Date created:		26 March 2002
# Whom:			Oliver Braun <obraun@informatik.unibw-muenchen.de>
#
# $FreeBSD$

PORTNAME=	unrtf
PORTVERSION=	0.20.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A converter from RTF to several formats, including HTML and LaTeX

USE_GNOME=	gnometarget
GNU_CONFIGURE=	yes

MAN1=		unrtf.1
PLIST_FILES=	bin/unrtf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/unrtf ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/unrtf.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
