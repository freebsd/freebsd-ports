# Created by: Max Khon
# $FreeBSD$

PORTNAME=	htick
PORTVERSION=	1.0.4
PORTREVISION=	3
CATEGORIES=	news mail
MASTER_SITES=	SF/husky/${PORTNAME}/1.0-release
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	FTN file ticker

LIB_DEPENDS=	libfidoconfig.so:${PORTSDIR}/news/husky-fidoconf

CONFLICTS=	husky-htick-devel-[0-9]*

USES=		makeinfo
MAN1=		htick.1
INFO=		htick

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's^/fido/etc/config^${PREFIX}/etc/fido/config^' \
		${WRKSRC}/man/htick.1

post-build:
	@cd ${WRKSRC}/doc && ${MAKE_CMD} ${MAKE_ARGS} all

post-install:
	@cd ${WRKSRC}/doc && ${MAKE_CMD} ${MAKE_ARGS} install

.include "${.CURDIR}/../husky-base/Makefile.inc"
.include <bsd.port.mk>
