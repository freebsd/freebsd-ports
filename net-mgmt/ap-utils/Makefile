# Created by: Jerry A! <jerry@thehutt.org>
# $FreeBSD$

PORTNAME=	ap-utils
PORTVERSION=	1.4.1
PORTREVISION=	5
CATEGORIES=	net-mgmt
MASTER_SITES=	SF

MAINTAINER=	david@catwhisker.org
COMMENT=	Set of utilities to configure and monitor wireless access points

GNU_CONFIGURE=	yes
USES=		iconv ncurses tar:bzip2
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lintl

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_WITHOUT=	--disable-nls

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MNLS}
BROKEN=		Does not build without gettext
.endif

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/Documentation && \
		${INSTALL_DATA} FAQ Ovislink-HOWTO.html HARDWARE-NOTES README.ap-gl ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
