# New ports collection makefile for:    husky-sqpack
# Date created:                         6 January 2003
# Whom:                                 Max Khon
#
# $FreeBSD$
#

PORTNAME=	sqpack
PORTVERSION=	1.2.4
PORTREVISION=	1
CATEGORIES=	news mail
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	Message base packer

LIB_DEPENDS=	fidoconfig.0:${PORTSDIR}/news/husky-fidoconf

USE_REINPLACE=	yes

MAN1=		sqpack.1
MANCOMPRESSED=	yes

post-patch:
	@${REINPLACE_CMD} -e 's^/etc/fido/config^${PREFIX}/etc/fido/config^' \
		${WRKSRC}/sqpack.1

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/news/husky-base/Makefile.inc"
.include <bsd.port.post.mk>
