# New ports collection makefile for: yaf
# Date created:		2009-06-29
# Whom:			Dikshie <dikshie@sfc.wide.ad.jp>
#
# $FreeBSD$

PORTNAME=	yaf
PORTVERSION=	1.0.0.2
CATEGORIES=	net-mgmt
MASTER_SITES=	http://tools.netsa.cert.org/releases/

MAINTAINER=	dikshie@sfc.wide.ad.jp
COMMENT=	YAF is Yet Another Flowmeter

LIB_DEPENDS=	fixbuf:${PORTSDIR}/net/libfixbuf \
		pcre.0:${PORTSDIR}/devel/pcre

GNU_CONFIGURE=	yes
USE_GNOME=	glib20 gnomehack
USE_LDCONFIG=	yes

MAN1=	airdaemon.1 filedaemon.1 yaf.1 yafscii.1

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/configure

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700042
BROKEN=		does not build on 6.x.
.endif

.include <bsd.port.post.mk>
