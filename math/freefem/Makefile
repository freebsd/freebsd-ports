# New ports collection makefile for:   freefem
# Date created:        20 December 1996
# Whom:                Pedro Giffuni
#
# $FreeBSD$
#

PORTNAME=	freefem
PORTVERSION=	3.5.1
CATEGORIES=	math cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	kfem

MAINTAINER=	ports@FreeBSD.org

USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--enable-adapt --with-optimization

MAN1=		freefem.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/freefem/freefem ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/debian/freefem.1 ${MANPREFIX}/man/man1
	@${MKDIR} ${PREFIX}/share/examples/freefem
	${INSTALL_DATA} ${WRKSRC}/examples/*.pde ${PREFIX}/share/examples/freefem
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/freefem
.for file in ChangeLog NEWS README
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/freefem
.endfor
.endif

.include <bsd.port.mk>
