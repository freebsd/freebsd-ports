# New ports collection makefile for:    libesmtp
# Date created:         Sun Feb 21 2001
# Whom:                 tobez@tobez.org
#
# $FreeBSD$
#

PORTNAME=	libesmtp
PORTVERSION=	0.5
CATEGORIES=	mail
MASTER_SITES=	http://www.stafford.uklinux.net/libesmtp/ \
		http://www.tobez.org/download/port-mirrors/mail/libesmtp/

MAINTAINER=	tobez@tobez.org

USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

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
