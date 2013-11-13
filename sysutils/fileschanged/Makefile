# Created by: Konstantin Reznichenko <kot@premierbank.dp.ua>
# $FreeBSD$

PORTNAME=	fileschanged
PORTVERSION=	0.6.5
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility that reports when files have been altered

LIB_DEPENDS=	libargp.so:${PORTSDIR}/devel/argp-standalone
BUILD_DEPENDS=	help2man:${PORTSDIR}/misc/help2man

GNU_CONFIGURE=	yes
USES=		gmake
USE_FAM=	yes
CONFIGURE_ENV+=	LIBS="-largp"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--datadir=${PREFIX}/share/doc --disable-nls

INFO=		fileschanged
DOCS=		AUTHORS ChangeLog INSTALL NEWS README

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for DOCFILE in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${DOCFILE} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
