# New ports collection makefile for:	flex
# Date created:		13 August 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	flex
PORTVERSION=	2.5.33
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Fast lexical analyzer generator

BUILD_DEPENDS=	bison:${PORTSDIR}/devel/bison2 \
		help2man:${PORTSDIR}/misc/help2man \
		gm4:${PORTSDIR}/devel/m4

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-nls
USE_GMAKE=	yes
MAN1=		flex.1
PLIST_FILES=	bin/flex include/FlexLexer.h lib/libfl.a

post-patch:
	@${REINPLACE_CMD} -e 's/install-info-recursive//g;s/info-recursive//g' \
		-e 's/po //;s/tests//' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's/ install-info-am//' ${WRKSRC}/doc/Makefile.in

.include <bsd.port.mk>
