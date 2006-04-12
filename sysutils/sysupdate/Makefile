# New ports collection makefile for:	sysupdate
# Date created:                    	17 Jan 2006
# Whom:                        		Tig <tig@lvlworld.com>
#
# $FreeBSD$
#

PORTNAME=	sysupdate
PORTVERSION=	0.3.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	lvl
DISTFILES=	${PORTNAME}.sh-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	tig@lvlworld.com
COMMENT=	System and ports update script

MAN1=		sysupdate.sh.1
MANCOMPRESSED=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

NO_BUILD=	yes
PLIST_FILES=	bin/sysupdate.sh

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
