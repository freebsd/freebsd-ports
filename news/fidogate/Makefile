# New ports collection makefile for:    fidogate
# Version required:     fidogate-4.2.9
# Date created:         02 Dez 1997
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $Id$
#

DISTNAME=       fidogate-4.2.9
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		ftp://ftp.dinoex.sub.org/pub/approved/
MASTER_SITE_SUBDIR=system/fido

MAINTAINER=     dirk.meyer@dinoex.sub.org

USE_GMAKE=	yes

# you may commet out this line if you have another transfer-agent
RUN_DEPENDS=	${PREFIX}/libexec/ifmail/ifcico:${PORTSDIR}/news/ifmail

WRKSRC=		${WRKDIR}/fidogate

pre-install:
	${MKDIR} ${PREFIX}/libexec/fidogate
	${MKDIR} ${PREFIX}/share/doc/fidogate/html
	${MKDIR} ${PREFIX}/share/doc/fidogate/info

.include <bsd.port.mk>
