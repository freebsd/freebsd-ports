# New ports collection makefile for:	mplayer-themes
# Date created:				18 Jun, 2007
# Whom:	Diego Depaoli <trebestie@gmail.com> and Yinghong.Liu <liu_yinghong@yahoo.com.cn>
#
# $FreeBSD$
#

PORTNAME=	smplayer-themes
PORTVERSION=	0.1.1
CATEGORIES=	multimedia audio kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=smplayer

MAINTAINER=	liu_yinghong@yahoo.com.cn
COMMENT=	Themes for smplayer

NO_BUILD=	yes

DATADIR=	${PREFIX}/share/smplayer

post-patch:
	@${REINPLACE_CMD} -e 's|PREFIX=/usr/local|PREFIX=${PREFIX}|g' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
