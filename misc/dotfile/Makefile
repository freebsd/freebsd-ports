# New ports collection makefile for: dotfile
# Version required:  2.0
# Date created:      11/12/96
# Whom:              oly@world.std.com
#
# $Id: Makefile,v 1.8 1998/02/25 10:10:53 asami Exp $
#

DISTNAME=	dotfile-2.2
CATEGORIES=	misc tk80
MASTER_SITES=	ftp://ftp.imada.ou.dk/pub/dotfile/

MAINTAINER=	oly@world.std.com

LIB_DEPENDS=	tk80\\.1:${PORTSDIR}/x11/tk80
RUN_DEPENDS=	wish8.0:${PORTSDIR}/x11/tk80

GNU_CONFIGURE=	yes
MAN1=		dotfile.1

NO_BUILD=	yes

post-install:
	@${MKDIR} ${PREFIX}/share/doc/${DISTNAME}
	@${MKDIR} ${PREFIX}/share/doc/${DISTNAME}/dotfile
	@${MKDIR} ${PREFIX}/share/doc/${DISTNAME}/procmail
	@${MKDIR} ${PREFIX}/share/doc/${DISTNAME}/tcsh
	${INSTALL_DATA} ${WRKSRC}/Doc/index.html ${PREFIX}/share/doc/${DISTNAME}
	${INSTALL_DATA} ${WRKSRC}/Doc/dotfile/* ${PREFIX}/share/doc/${DISTNAME}/dotfile
	${INSTALL_DATA} ${WRKSRC}/Doc/tcsh/* ${PREFIX}/share/doc/${DISTNAME}/tcsh
	${INSTALL_DATA} ${WRKSRC}/Doc/procmail/* ${PREFIX}/share/doc/${DISTNAME}/procmail
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
