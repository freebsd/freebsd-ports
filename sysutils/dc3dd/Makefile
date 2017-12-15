# Created by: MANTANI Nobutaka <nobutaka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dc3dd
PORTVERSION=	7.2.641
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/7.2

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	dd program useful for computer forensics

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_armv6=		fails to compile: bit-field 'verify_error_if_negative_size__' has negative width
BROKEN_armv7=		fails to compile: bit-field 'verify_error_if_negative_size__' has negative width

USES=		gettext iconv gmake tar:bzip2
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

.include <bsd.port.mk>
