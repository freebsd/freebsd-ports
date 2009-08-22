# New ports collection makefile for:	husky-htick-devel
# Date created:				2008-10-25
# Whom:					Andrew Clarke <mail@ozzmosis.com>
#
# $FreeBSD$
#

PORTNAME=	htick
DISTVERSION=	1.4-rc5
CATEGORIES=	news mail
MASTER_SITES=	SF/husky/${PORTNAME}/1.4-RC5

PKGNAMESUFFIX=	-devel

MAINTAINER=	mail@ozzmosis.com
COMMENT=	FTN File ticker, development version

LIB_DEPENDS=	fidoconfig.1:${PORTSDIR}/news/husky-fidoconf-devel

CONFLICTS=	husky-htick-[0-9]*

MAN1=		htick.1
INFO=		htick

PLIST_FILES=	bin/htick \
		share/doc/husky/htick.html

post-patch:
	@${REINPLACE_CMD} -e 's^/fido/etc/config^${PREFIX}/etc/fido/config^' \
		${WRKSRC}/man/htick.1

post-build:
	@cd ${WRKSRC}/doc && ${GMAKE} ${MAKE_ARGS} all

post-install:
	@cd ${WRKSRC}/doc && ${GMAKE} ${MAKE_ARGS} install

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/news/husky-base-devel/Makefile.inc"
.include <bsd.port.post.mk>
