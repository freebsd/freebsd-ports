# Created by: Masaki TAGAWA <masaki@club.kyutech.ac.jp>
# $FreeBSD$

PORTNAME=	packter-agent
PORTVERSION=	2.5
CATEGORIES=	net
MASTER_SITES=	http://www.packter.net/
DISTNAME=	PackterAgent-${PORTVERSION}

MAINTAINER=	masaki@club.kyutech.ac.jp
COMMENT=	An agent of the tool for graphical Internet traffic visualization

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

GNU_CONFIGURE=	yes
USES=		pkgconfig
USE_GNOME=	glib20

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL LICENSE NEWS README

OPTIONS_DEFINE=	IPV6 PACKTERTC
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
	@${MKDIR} ${DATADIR}
	${CP} -pr ${WRKSRC}/packter_tc ${DATADIR}/
.endif

.for f in packter.conf
	@if [ ! -f ${PREFIX}/etc/${f} ]; then \
		${CP} -p ${PREFIX}/etc/${f}.sample ${PREFIX}/etc/${f} ; \
	fi
.endfor

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
