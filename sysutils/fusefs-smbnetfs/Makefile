# Created by: Denis Barov
# $FreeBSD$

PORTNAME=	smbnetfs
PORTVERSION=	0.5.3a
CATEGORIES=	sysutils net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/SMBNetFS-${PORTVERSION}
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mount smb shares (Fuse filesystem)

OPTIONS_DEFINE=	GNOME_KEYRING
OPTIONS_DEFAULT=GNOME_KEYRING
GNOME_KEYRING_DESC=	Build with gnome-keyring support

LIB_DEPENDS=	libsmbclient.so:${PORTSDIR}/net/samba-libsmbclient

DOCSDIR+=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}

USE_BZIP2=	yes
USES=		fuse pkgconfig

GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib
SUB_FILES=	pkg-message

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGNOME_KEYRING}
CONFIGURE_ARGS+=--with-gnome-keyring=yes
LIB_DEPENDS+=	gnome-keyring.0:${PORTSDIR}/security/libgnome-keyring
.else
CONFIGURE_ARGS+=--with-gnome-keyring=no
.endif

post-patch:
	${REINPLACE_CMD} -e 's|а|a|g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
