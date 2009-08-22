# New ports collection makefile for:	smbnetfs
# Date created:				06 August 2006
# Whom:					Denis Barov
# $FreeBSD$
#

PORTNAME=	smbnetfs
PORTVERSION=	0.3.7
CATEGORIES=	sysutils net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/SMBNetFS-${PORTVERSION}
PKGNAMEPREFIX=	fusefs-
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	dindin@freebsd.org.ua
COMMENT=	Mount smb shares (Fuse filesystem)

LIB_DEPENDS=	fuse.2:${PORTSDIR}/sysutils/fusefs-libs \
		smbclient.0:${PORTSDIR}/net/samba-libsmbclient
RUN_DEPENDS=	${LOCALBASE}/modules/fuse.ko:${PORTSDIR}/sysutils/fusefs-kmod
BUILD_DEPENDS=	fusefs-libs>2.4.1:${PORTSDIR}/sysutils/fusefs-libs

USE_BZIP2=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS} -I${LOCALBASE}/include"
SUB_FILES=	pkg-message

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
