# New ports collection makefile for:    husky-htick
# Date created:                         6 January 2003
# Whom:                                 Max Khon
#
# $FreeBSD$
#

PORTNAME=	htick
PORTVERSION=	1.0.4
PORTREVISION=	2
CATEGORIES=	news mail
MASTER_SITES=	SF/husky/${PORTNAME}/1.0-release
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	FTN file ticker

LIB_DEPENDS=	fidoconfig.0:${PORTSDIR}/news/husky-fidoconf

CONFLICTS=	husky-htick-devel-[0-9]*

MAN1=		htick.1
INFO=		htick

post-patch:
	@${REINPLACE_CMD} -e 's^/fido/etc/config^${PREFIX}/etc/fido/config^' \
		${WRKSRC}/man/htick.1

post-build:
	@cd ${WRKSRC}/doc && ${GMAKE} ${MAKE_ARGS} all

post-install:
	@cd ${WRKSRC}/doc && ${GMAKE} ${MAKE_ARGS} install

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/news/husky-base/Makefile.inc"
.include <bsd.port.post.mk>
