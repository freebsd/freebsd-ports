# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	talkfilters
PORTVERSION=	2.3.8
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://www.hyperrealm.com/talkfilters/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Set of filters to convert English text to various stereotyped dialects

LICENSE=	GPLv2

CONFLICTS=	jive* chef* filters-*

USES=		libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

SUB_FILES=	pkg-message

INFO=	talkfilters

post-extract:
	@${ECHO} ${DO_NADA} > ${WRKSRC}/install-sh
	@${CHMOD} +x ${WRKSRC}/install-sh

post-patch:
	@${RM} -f ${WRKSRC}/*.info*
	@${REINPLACE_CMD} -e \
		's|^\(pkgconfigdir\ =\ \).*|\1$$(prefix)/libdata/pkgconfig|' \
			${WRKSRC}/Makefile.am \
			${WRKSRC}/Makefile.in

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libtalkfilters.so*

.include <bsd.port.mk>
