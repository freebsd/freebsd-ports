# New ports collection makefile for:    libesmtp
# Date created:         Sun Feb 21 2001
# Whom:                 tobez@tobez.org
#
# $FreeBSD$

PORTNAME=	libesmtp
PORTVERSION=	0.8.3
CATEGORIES=	mail
MASTER_SITES=	http://www.stafford.uklinux.net/libesmtp/ \
		http://www.theochem.kth.se/~pawsa/balsa/ \
		http://www.tobez.org/download/port-mirrors/mail/libesmtp/

MAINTAINER=	jmcoopr@webmail.bmi.net

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

# the following is required for Balsa-1.17
CONFIGURE_ARGS=	--enable-require-all-recipients

post-install:
.ifndef(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/examples/libesmtp
	${MKDIR} ${PREFIX}/share/doc/libesmtp
	${INSTALL_DATA} ${WRKSRC}/examples/* ${PREFIX}/share/examples/libesmtp
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/libesmtp
	${INSTALL_DATA} ${WRKSRC}/Notes ${PREFIX}/share/doc/libesmtp
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/libesmtp
.endif

.include <bsd.port.mk>
