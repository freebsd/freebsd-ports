# New ports collection makefile for:	soothsayer
# Date created:		7 August 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	soothsayer
PORTVERSION=	0.5
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Intelligent predictive text entry platform

USE_LDCONFIG=	yes
USE_SQLITE=	3
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static --localstatedir=${PREFIX}/var/${PORTNAME}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

PORT_VERBS=	${PORTNAME} text2ngram

post-patch:
	@${GREP} -rl 'sqlite.h' ${WRKSRC}/src|${XARGS} ${REINPLACE_CMD} -e\
		's|sqlite\.h|sqlite3.h|g'
	@${REINPLACE_CMD} -e 's|\$$\^|$${.ALLSRC}|' ${WRKSRC}/resources/Makefile.in
	@${REINPLACE_CMD} -e '1s|/.*|/bin/sh|'\
		${WRKSRC}/resources/profiles/generate_soothsayer_config.sh

.include <bsd.port.mk>
