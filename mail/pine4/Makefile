# New ports collection makefile for:	pine
# http://www.washington.edu/pine/
# Version required:     3.96
# Date created:		03 September 1994
# Whom:			mr
#
# $Id: Makefile,v 1.20 1997/02/06 08:45:06 asami Exp $
#

DISTNAME=       pine3.96
PKGNAME=        pine-3.96
CATEGORIES=     mail news
MASTER_SITES=	ftp://ftp.cac.washington.edu/pine/

MAINTAINER=	ports@FreeBSD.org

MAN1= 		pine.1 pico.1 pilot.1

post-install:
	install -d -o ${SHAREOWN} -g ${SHAREGRP} -m 755 \
		${PREFIX}/share/doc/pine
	cd ${WRKSRC} && \
		${INSTALL_DATA} doc/tech-notes.txt ${PREFIX}/share/doc/pine

.include <bsd.port.mk>
