# New ports collection makefile for:	sysupdate
# Date created:                    	17 Jan 2006
# Whom:                        		Tig <tigger@lvlworld.com>
#
# $FreeBSD$
#

PORTNAME=	sysupdate
PORTVERSION=	0.4
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	lvl
DISTNAME=	${PORTNAME}.sh-${PORTVERSION}

MAINTAINER=	tigger@lvlworld.com
COMMENT=	System and ports update script

MAN1=		sysupdate.sh.1
MANCOMPRESSED=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

NO_BUILD=	yes
PLIST_FILES=	bin/sysupdate.sh

OPTIONS=	FASTEST_CVSUP "Support fastest_cvsup" off

.include <bsd.port.pre.mk>

.if defined(WITH_FASTEST_CVSUP)
RUN_DEPENDS=	fastest_cvsup:${PORTSDIR}/sysutils/fastest_cvsup
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' \
		${WRKSRC}/Makefile

.include <bsd.port.post.mk>
