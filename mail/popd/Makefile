# Created by: ianf@za.uu.net
# $FreeBSD$

PORTNAME=	popd
PORTVERSION=	2.2.2a
PORTREVISION=	5
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp3.za.freebsd.org/pub/popd/

MAINTAINER=	ian@freislich.nom.za
COMMENT=	Very fast, highly configurable POP3 server (fully RFC1939 compliant)

MAN5=	popd.conf.5
MAN8=	popd.8

USE_LDCONFIG=	yes
MANCOMPRESSED=	maybe
.if defined(NOPROFILE)
PLIST_SUB=	NOPROFILE="@comment "
.else
PLIST_SUB=	NOPROFILE=""
.endif

NO_STAGE=	yes
post-install:
	${INSTALL_DATA} ${WRKSRC}/src/popd.conf.default ${PREFIX}/etc/.

.include <bsd.port.mk>
