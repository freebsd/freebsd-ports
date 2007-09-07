# New ports collection makefile for:	soothsayer
# Date created:		7 August 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	soothsayer
PORTVERSION=	0.6
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Intelligent predictive text entry platform

BUILD_DEPENDS=	swig>=1.3.31:${PORTSDIR}/devel/swig13

USE_LDCONFIG=	yes
USE_SQLITE=	3
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static --localstatedir=${PREFIX}/var/${PORTNAME}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

PORT_VERBS=	${PORTNAME} text2ngram

post-patch:
	@${REINPLACE_CMD} -e 's|\$$\^|$${.ALLSRC}|' ${WRKSRC}/resources/Makefile.in
	@${REINPLACE_CMD} -e '1s|/.*|/bin/sh|'\
		${WRKSRC}/resources/profiles/generate_soothsayer_config.sh

.include <bsd.port.mk>
