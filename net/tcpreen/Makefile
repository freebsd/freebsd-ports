# Created by: Janos.Mohacsi@bsd.hu
# $FreeBSD$

PORTNAME=	tcpreen
PORTVERSION=	1.4.4
PORTREVISION=	3
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.remlab.net/files/tcpreen/

MAINTAINER=	jmohacsi@bsd.hu
COMMENT=	Simple TCP session re-engineering tool

USES=		tar:bzip2
GNU_CONFIGURE=	yes

DOC_FILES=	AUTHORS NEWS README THANKS TODO

OPTIONS_DEFINE=	DOCS NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
