# New ports collection makefile for:	xlogmaster
# Version required:	1.2.2
# Date created:		11 July 1998
# Whom:			Adrian Wontroba <aw1@stade.co.uk>
#
# $Id: Makefile,v 1.2 1998/08/05 09:31:38 asami Exp $
#

DISTNAME=	xlogmaster-1.2.2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.fusebox.hanse.de/xlogmaster/\
		http://porter.desy.de/~greve/xlogmaster/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	aw1@stade.co.uk

LIB_DEPENDS=	gtk\\.1\\.:${PORTSDIR}/x11-toolkits/gtk

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=		xlogmaster.1
WRKSRC=		${WRKDIR}/xlogmaster
USE_X_PREFIX=	yes
NO_PACKAGE=	ignores cflags

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/xlogmaster
	${INSTALL_MAN} ${WRKSRC}/doc/tutorial.txt ${PREFIX}/share/doc/xlogmaster
.endif

.include <bsd.port.mk>
