# New ports collection makefile for:	chpp
# Version required:			0.3.5
# Date created:				4 May 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=	chpp-0.3.5
CATEGORIES=	textproc
MASTER_SITES=	http://people.FreeBSD.org/~andy/distfiles/

MAINTAINER=	ports@FreeBSD.org

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--libdir=${PREFIX}/share

post-install:
	@ ${MKDIR} ${PREFIX}/share/examples/chpp
	@ cd ${WRKSRC}/test; tar -cf - * | \
		( cd ${PREFIX}/share/examples/chpp; tar --unlink -xf - )
	@ ${MKDIR} ${PREFIX}/share/doc/chpp
.if !defined(NOPORTDOCS)
.for file in AUTHORS COPYING NEWS README
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/chpp
.endfor
.endif

.include <bsd.port.mk>
