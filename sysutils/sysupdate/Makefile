# Created by: Tig <tigger@lvlworld.com>
# $FreeBSD$

PORTNAME=	sysupdate
PORTVERSION=	0.5.8
CATEGORIES=	sysutils
MASTER_SITES=	SF/lvl/FreeBSD%20System%20Update/${PORTNAME}.sh%20v${PORTVERSION}
DISTNAME=	${PORTNAME}.sh-${PORTVERSION}

MAINTAINER=	tigger@lvlworld.com
COMMENT=	System and ports update script

MAN1=		sysupdate.sh.1
MANCOMPRESSED=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

NO_BUILD=	yes
PLIST_FILES=	bin/sysupdate.sh

OPTIONS_DEFINE=	FASTEST_CVSUP
FASTEST_CVSUP_DESC=	Support fastest_cvsup

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFASTEST_CVSUP}
RUN_DEPENDS+=	fastest_cvsup:${PORTSDIR}/sysutils/fastest_cvsup
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
