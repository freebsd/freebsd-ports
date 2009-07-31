# New ports collection makefile for:	pfstat
# Date created:		10 October 2003
# Whom:			Max Laier <max@love2party.net>
#
# $FreeBSD$
#

PORTNAME=	pfstat
PORTVERSION=	2.4
PORTREVISION=	1
CATEGORIES=	sysutils net
MASTER_SITES=	http://www.benzedrine.cx/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	mlaier@FreeBSD.org
COMMENT=	Utility to render graphical statistics for pf

LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd

MAKE_ARGS=	"LD_GD=gd"
MAKE_ENV+=	__MAKE_CONF=/dev/null
USE_ICONV=	yes

MAN8=		pfstat.8 \
		pfstatd.8

MANCOMPRESSED=	no
PLIST_FILES=	bin/pfstat \
		bin/pfstatd

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700048
EXTRA_PATCHES=	${PATCHDIR}/pre41-patch-pf.c
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lgd|-l$${LD_GD}|; s| -lttf||' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e "s|/etc/|${PREFIX}/etc/|" \
		${WRKSRC}/pfstat.[c8]

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pfstat ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/pfstatd/pfstatd ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pfstat.8 ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/pfstatd/pfstatd.8 ${PREFIX}/man/man8

.include <bsd.port.post.mk>
