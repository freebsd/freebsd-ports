# New ports collection makefile for:	webalizer
# Version required:	1.12
# Date created:		02.Jun 1998
# Whom:			dirk.meyer@dinoex.sub.org
#
# $Id$

DISTNAME=	webalizer-1.12-09-src
PKGNAME=	webalizer-1.12
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.mrunix.net/pub/webalizer/ \
		ftp://ftp.dinoex.sub.de/pub/approved/
EXTRACT_SUFX=	.tgz

MAINTAINER=	dirk.meyer@dinoex.sub.org

BUILD_DEPENDS=	${PREFIX}/lib/libgd.a:${PORTSDIR}/graphics/gd

BIN1=		webalizer
WRKSRC=		${WRKDIR}

do-install:
.for i in ${BIN1}
	@${INSTALL_SCRIPT} ${WRKSRC}/${i} ${PREFIX}/bin
.endfor

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/webalizer
.for i in CHANGES COPYING Copyright README TODO webalizer.LSM
	@${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/doc/webalizer/${i}
.endfor
.endif
	${MKDIR} ${PREFIX}/share/examples/webalizer
.for i in msfree.gif sample.conf
	@${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/examples/webalizer/${i}
.endfor

.include <bsd.port.mk>
