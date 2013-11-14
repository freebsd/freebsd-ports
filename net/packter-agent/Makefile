# Created by: Masaki TAGAWA <masaki@club.kyutech.ac.jp>
# $FreeBSD$

PORTNAME=	packter-agent
PORTVERSION=	2.5
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.packter.jp/
DISTNAME=	PackterAgent-${PORTVERSION}

MAINTAINER=	masaki@club.kyutech.ac.jp
COMMENT=	Agent of the tool for graphical Internet traffic visualization

LICENSE=	BSD

GNU_CONFIGURE=	yes
USES=		pkgconfig
USE_GNOME=	glib20
CFLAGS+=	-Wno-return-type

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL LICENSE NEWS README

OPTIONS_DEFINE=	IPV6 PACKTERTC DOCS
PACKTERTC_DESC=	Install Packter TC
OPTIONS_DEFAULT=	IPV6

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if ${PORT_OPTIONS:MPACKTERTC}
USES+=		perl5
USE_PERL5=	run
RUN_DEPENDS+=	p5-XML-Pastor>=0:${PORTSDIR}/devel/p5-XML-Pastor
PLIST_SUB+=	PACKTERTC=""
.else
PLIST_SUB+=	PACKTERTC="@comment "
.endif

post-install:
.if ${PORT_OPTIONS:MPACKTERTC}
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${CP} -pr ${WRKSRC}/packter_tc ${STAGEDIR}${DATADIR}/
.endif

.for f in packter.conf
	@if [ ! -f ${PREFIX}/etc/${f} ]; then \
		${CP} -p ${STAGEDIR}${PREFIX}/etc/${f}.sample ${STAGEDIR}/${PREFIX}/etc/${f} ; \
	fi
.endfor

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_MAN} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
