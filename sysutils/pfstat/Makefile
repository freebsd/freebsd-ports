# New ports collection makefile for:	pfstat
# Date created:		10 October 2003
# Whom:			Max Laier <max@love2party.net>
#
# $FreeBSD$
#

PORTNAME=	pfstat
PORTVERSION=	1.7
CATEGORIES=	sysutils net
MASTER_SITES=	http://www.benzedrine.cx/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	mlaier@freebsd.org
COMMENT=	Utility to render grafical statistics for pf

.if defined(WITH_GD1)
LIB_DEPENDS=	gd1.2:${PORTSDIR}/graphics/gd1
CFLAGS+=	-I${LOCALBASE}/include/gd
MAKE_ARGS=	"LD_GD=gd1"
.else
LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd
MAKE_ARGS=	"LD_GD=gd"
.endif

USE_REINPLACE=	yes

MAN8=		pfstat.8

MANCOMPRESSED=	no
PLIST_FILES=	bin/pfstat

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		"Only for 5.0 and above"
.endif

.if ${OSVERSION} < 502106
BUILD_DEPENDS=	${LOCALBASE}/include/pf/net/pfvar.h:${PORTSDIR}/security/pf
RUN_DEPENDS=	${LOCALBASE}/modules/pf.ko:${PORTSDIR}/security/pf

CFLAGS+=	-I${LOCALBASE}/include/pf
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lgd|-l$${LD_GD}|; s| -lttf||' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pfstat ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pfstat.8 ${PREFIX}/man/man8

.include <bsd.port.post.mk>
