# Created by: Kay Lehmann
# $FreeBSD$

PORTNAME=	lineakd
PORTVERSION=	0.9
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	SF/lineak/${PORTNAME}/${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	lineak

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lineakd is a daemon which enables special keys on internet keyboards

USE_GMAKE=	yes
USE_XORG=	x11 xext xt
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes

CONFIGURE_ARGS+=--program-prefix=''

DOCS=		README TODO AUTHORS

post-patch:
	@${REINPLACE_CMD} -e 's|-ldl||' \
		${WRKSRC}/lineak/Makefile.in ${WRKSRC}/lineakd/Makefile.in
	@${REINPLACE_CMD} -e 's|-O2||' ${WRKSRC}/configure

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/lineakd.conf.example ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
