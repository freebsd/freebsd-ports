# New ports collection makefile for:	popa3d
# Version required:	0.4
# Date created:		Sun Feb  6 12:31:29 MSK 2000
# Whom:			Sergey Samoyloff <gonza@techline.ru>
#
# $FreeBSD$
#

DISTNAME=	popa3d-0.4
CATEGORIES=	mail
MASTER_SITES=	http://www.openwall.com/popa3d/ \
		ftp://ftp.openwall.com/popa3d/ \
		ftp://ftp.dataforce.net/pub/solar/ \
		ftp://ftp.false.com/pub/security/popa3d/

MAINTAINER=	gonza@techline.ru

ALL_TARGET=	popa3d

do-install:
	${INSTALL} ${COPY} -o root -g wheel -m 500 \
	    ${WRKSRC}/popa3d ${PREFIX}/libexec/popa3d

.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/popa3d
	${INSTALL_MAN} ${WRKSRC}/DESIGN ${PREFIX}/share/doc/popa3d
	${INSTALL_MAN} ${WRKSRC}/COPYING ${PREFIX}/share/doc/popa3d
.endif

pre-install:
	@ ${SH} ${PKGDIR}/INSTALL ${PKGNAME} PRE-INSTALL

post-install:
	@ ${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
