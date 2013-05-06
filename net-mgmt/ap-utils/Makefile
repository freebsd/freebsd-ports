# Created by: Jerry A! <jerry@thehutt.org>
# $FreeBSD$

PORTNAME=	ap-utils
PORTVERSION=	1.4.1
PORTREVISION=	4
CATEGORIES=	net-mgmt
MASTER_SITES=	 SF

MAINTAINER=	david@catwhisker.org
COMMENT=	A set of utilities to configure and monitor wireless access points

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USES=		iconv
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-lintl -L${LOCALBASE}/lib
MAN8=		ap-trapd.8 ap-mrtg.8 ap-config.8

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
BROKEN=		Does not build without gettext
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|_nl_domain_bindings|libintl_nl_domain_bindings|' ${WRKSRC}/configure

.if ${PORT_OPTIONS:MDOCS}
post-install:
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/Documentation && \
		${INSTALL_DATA} FAQ Ovislink-HOWTO.html HARDWARE-NOTES README.ap-gl ${DOCSDIR}
.endif

.include <bsd.port.mk>
