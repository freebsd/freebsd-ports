# $FreeBSD$

PORTNAME=	icinga-classicweb
PORTREVISION=	1
DISTNAME=	icinga-${PORTVERSION}

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Classic web interface for Icinga 1 and 2

.include "${.CURDIR}/../icinga-core/Makefile.common"

LIB_DEPENDS+=	libgd.so:graphics/gd

CONFIGURE_ARGS+=--disable-idoutils
CFLAGS+=	-I${LOCALBASE}/include

ALL_TARGET=	classicui-standalone
INSTALL_TARGET=	install-classicui-standalone install-classicui-standalone-conf

post-patch:
	@${REINPLACE_CMD} -e 's#775#755#g; s#664#644#g' \
		${WRKSRC}/html/Makefile.in
# Use correct make(1) syntax to unbreak parallel builds
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} \
		-E 's#cd (.+) && (make|\$$\(MAKE\))#$$(MAKE) -C \1#'

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${ICINGAWWWDIR}/ssi

.include <bsd.port.mk>
