# New ports collection makefile for:	OpenJade
# Date created:		May 19, 2000
# Whom:			kuriyama
#
# $FreeBSD$
#

PORTNAME=	openjade
PORTVERSION= 	1.3
CATEGORIES=	textproc
MASTER_SITES=	http://download.sourceforge.net/openjade/

MAINTAINER=	kuriyama@FreeBSD.org

USE_GMAKE=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CXXFLAGS="${CFLAGS}"
CONFIGURE_ARGS=	--enable-default-catalog=${PREFIX}/share/sgml/catalog

pre-install:
	@find ${WRKSRC} \( -name \*.orig -o -name \*~ \) -exec ${RM} -f \{} \;

post-install:
	${MKDIR} ${PREFIX}/share/sgml/openjade
	${INSTALL_DATA} ${WRKSRC}/dsssl/* ${PREFIX}/share/sgml/openjade
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m $(PREFIX)/lib

.include <bsd.port.mk>
