# Created by: Masaki TAGAWA <masaki@club.kyutech.ac.jp>
# $FreeBSD$

PORTNAME=	packter-agent
PORTVERSION=	2.5
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.packter.jp/
DISTNAME=	PackterAgent-${PORTVERSION}

MAINTAINER=	masaki@club.kyutech.ac.jp
COMMENT=	Agent of the tool for graphical Internet traffic visualization

LICENSE=	BSD2CLAUSE

GNU_CONFIGURE=	yes
USES=		pkgconfig
USE_GNOME=	glib20
CFLAGS+=	-Wno-return-type

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL LICENSE NEWS README

OPTIONS_DEFINE=	IPV6 PACKTERTC DOCS
PACKTERTC_DESC=	Install Packter TC

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if ${PORT_OPTIONS:MPACKTERTC}
USES+=		perl5
USE_PERL5=	run
RUN_DEPENDS+=	p5-XML-Pastor>=0:devel/p5-XML-Pastor
PLIST_SUB+=	PACKTERTC=""
.else
PLIST_SUB+=	PACKTERTC="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} 's/-lssl/-lcrypto/' ${WRKSRC}/configure

post-install:
.if ${PORT_OPTIONS:MPACKTERTC}
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${CP} -pr ${WRKSRC}/packter_tc ${STAGEDIR}${DATADIR}/
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_MAN} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
