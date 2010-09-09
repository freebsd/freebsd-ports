# New ports collection makefile for:	toilet
# Date created:		13 August 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	toilet
PORTVERSION=	0.2
CATEGORIES=	misc
MASTER_SITES=	http://caca.zoy.org/raw-attachment/wiki/toilet/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Enhanced figlet(6)

LIB_DEPENDS=	caca.0:${PORTSDIR}/graphics/libcaca

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-transform-name=""
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CFLAGS+=	-fno-strength-reduce
MAN1=		${PORTNAME}.1
PORT_VERBS=	${PORTNAME} caca2tlf share/figlet/*tlf

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		does not compile
.endif

post-patch:
	@${REINPLACE_CMD} -e '/CFLAGS=/d;/ac_build_date=/s|=.*|="$$stamp"|'\
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|\$$\^|$${.ALLSRC}|' ${WRKSRC}/doc/Makefile.in

post-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/tools/caca2tlf ${PREFIX}/bin/

.include <bsd.port.post.mk>
