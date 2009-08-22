# New ports collection makefile for:	flex
# Date created:		13 August 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	flex
PORTVERSION=	2.5.35
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast lexical analyzer generator

BUILD_DEPENDS=	help2man:${PORTSDIR}/misc/help2man \
		gm4:${PORTSDIR}/devel/m4

USE_BISON=	build
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
# install flex header to its own dir to avoid conflict with system flex.
CONFIGURE_ARGS=	--disable-nls --includedir=${PREFIX}/include/flex
USE_GMAKE=	yes
MAN1=		flex.1
PLIST_FILES=	bin/flex include/flex/FlexLexer.h lib/libfl.a lib/libfl_pic.a
PLIST_DIRS=	include/flex

post-patch:
	@${REINPLACE_CMD} -e 's/install-info-recursive//g;s/info-recursive//g' \
		-e 's/po //;s/tests//' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's/ install-info-am//' ${WRKSRC}/doc/Makefile.in

.include <bsd.port.mk>
