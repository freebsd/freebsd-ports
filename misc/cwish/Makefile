# ex:ts=8
# Ports collection makefile for:  cwish
# Version required:     	  3.37
# Date created:			  Thur Sept 25, 1998
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $Id: Makefile,v 1.1.1.1 1998/09/25 10:57:57 obrien Exp $
#

DISTNAME=	cwish
PKGNAME=	cwish-3.37
CATEGORIES=	misc
MASTER_SITES=	http://www.hcs.de/users/hm/packages/

MAINTAINER=     obrien@FreeBSD.org

NO_WRKSUBDIR=	yes
ALL_TARGET=	#emtpy
MAN1=		cwish.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 300000
BROKEN=		"headers problem"
.endif

pre-configure:
	${CP} ${WRKSRC}/Makefile.freebsd ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cwish ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cwish.1 ${PREFIX}/man/man1

.include <bsd.port.post.mk>
