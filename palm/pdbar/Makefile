# Created by: Eric P. Scott <eps+pdbar@ana.com>
# $FreeBSD$

PORTNAME=	pdbar
PORTVERSION=	00.05.01
CATEGORIES=	palm
MASTER_SITES=	http://www.djw.org/product/palm/par/
DISTNAME=	prc
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Create and manipulate PalmOS database files

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" LDFLAGS="" AR=${AR} RANLIB=${RANLIB} LD=${CC}

PLIST_FILES=	bin/pdbar \
		man/man1/pdbar.1.gz

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/par ${STAGEDIR}${PREFIX}/bin/pdbar
		${INSTALL_MAN} ${WRKSRC}/par.man ${STAGEDIR}${MANPREFIX}/man/man1/pdbar.1

.include <bsd.port.mk>
