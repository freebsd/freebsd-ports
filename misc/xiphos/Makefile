# New ports collection makefile for: gnomesword
# Date created:   Oct 26, 2002
# Whom:           J Shoemaker <shoemaker@softhome.net>
#
# $FreeBSD$
#

PORTNAME=		gnomesword
PORTVERSION=		0.7.8
PORTREVISION=		1
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=		ports@freebsd.org
COMMENT=		A bible interface utilizing the sword framework

LIB_DEPENDS=		sword.1:${PORTSDIR}/misc/sword
BUILD_DEPENDS=		aspell:${PORTSDIR}/textproc/aspell

USE_GNOMENG=		yes
USE_GNOME=		gal gnomehack gnomeprefix gtkhtml
USE_X_PREFIX=   	yes
USE_GMAKE=      	yes
GNU_CONFIGURE=		yes

DOC_FILES=	AUTHORS COPYING ChangeLog INSTALL NEWS README TODO

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
