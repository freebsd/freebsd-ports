# Created by: Emmanuel Richiardone (err@tollari.org)
# $FreeBSD$

PORTNAME=	netembryo
PORTVERSION=	0.1.1
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=		LOCAL/rakuco \
			http://pkgs.fedoraproject.org/repo/pkgs/netembryo/netembryo-0.1.1.tar.bz2/d5a3c96b37fe3e4fb1c49df1f7a4a16f/ \
			http://lscube.org/files/downloads/netembryo/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Network abstraction library

LICENSE=	LGPL21

OPTIONS_DEFINE=		OPENSSL SCTP IPV6
OPTIONS_DEFAULT=	OPENSSL SCTP
OPTIONS_SUB=		yes
SCTP_DESC=		Stream Control Transmission Protocol support

OPTIONS_EXCLUDE_DragonFly=	SCTP
IPV6_CONFIGURE_ENABLE=		ipv6
SCTP_CONFIGURE_ENABLE=		sctp

USES=		gmake gnome libtool pathfix pkgconfig tar:bzip2
USE_GNOME=	glib20
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENSSL}
USES+=		ssl
CONFIGURE_ENV+=	OPENSSL_CFLAGS="-I${OPENSSLINC}" \
		OPENSSL_LIBS="-L${OPENSSLLIB}"
.else
CONFIGURE_ARGS+=--without-openssl
.endif

post-patch:
	@${REINPLACE_CMD} '/_XOPEN_SOURCE/d' ${WRKSRC}/configure

.include <bsd.port.mk>
