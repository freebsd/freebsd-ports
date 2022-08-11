PORTNAME=	dc3dd
PORTVERSION=	7.2.646
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}/${PORTNAME}%20${PORTVERSION}

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	dd program useful for computer forensics

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_armv6=		fails to compile: bit-field 'verify_error_if_negative_size__' has negative width
BROKEN_armv7=		fails to compile: bit-field 'verify_error_if_negative_size__' has negative width

USES=		gettext iconv gmake zip
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

pre-configure:
	${CHMOD} +x ${WRKSRC}/configure

.include <bsd.port.mk>
