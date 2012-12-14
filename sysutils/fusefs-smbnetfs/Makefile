# Created by: Denis Barov
# $FreeBSD$

PORTNAME=	smbnetfs
PORTVERSION=	0.5.3
PORTREVISION=	1
CATEGORIES=	sysutils net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/SMBNetFS-${PORTVERSION}
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mount smb shares (Fuse filesystem)

LIB_DEPENDS=	smbclient.0:${PORTSDIR}/net/samba-libsmbclient \
		gnome-keyring.0:${PORTSDIR}/security/libgnome-keyring

DOCSDIR+=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}

USE_BZIP2=	yes
USE_FUSE=	yes

GNU_CONFIGURE=	yes
CFLAGS+=	${PTHREAD_CFLAGS} -I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib
SUB_FILES=	pkg-message

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
