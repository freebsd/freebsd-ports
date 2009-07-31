# New ports collection makefile for:	toilet
# Date created:		13 August 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	toilet
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://libcaca.zoy.org/files/ CENKES

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Enhanced figlet(6)

LIB_DEPENDS=	cucul.0:${PORTSDIR}/graphics/libcaca

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-transform-name=""
CFLAGS+=	-fno-strength-reduce
MAN1=		${PORTNAME}.1
PORT_VERBS=	${PORTNAME} caca2tlf share/figlet/*tlf

post-patch:
	@${REINPLACE_CMD} -e '/CFLAGS=/d;/ac_build_date=/s|=.*|="$$stamp"|'\
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|\$$\^|$${.ALLSRC}|' ${WRKSRC}/doc/Makefile.in

post-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/tools/caca2tlf ${PREFIX}/bin/

.include <bsd.port.mk>
