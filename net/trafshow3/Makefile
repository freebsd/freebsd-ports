# New ports collection makefile for:	trafshow
# Date created:         25 September 1996
# Whom:                 igor@zynaps.ru
#
# $FreeBSD$
#

PORTNAME=	trafshow
PORTVERSION=	3.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.nsk.su/pub/RinetSoftware/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jseger@FreeBSD.org

.include <bsd.port.pre.mk>
.if ${OSVERSION} < 400010
LIB_DEPENDS=	ncurses.5:${PORTSDIR}/devel/ncurses
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include/ncurses -I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
ALL_TARGET=	trafshow

MAN1=		trafshow.1

post-patch:
	@${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/*.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/trafshow ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/trafshow.1 ${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/.trafshow ${PREFIX}/etc/trafshow.dist
	${CP} ${PREFIX}/etc/trafshow.dist ${PREFIX}/etc/trafshow

.include <bsd.port.post.mk>
