# Created by: dominik karczmarski <dominik@karczmarski.com>
# $FreeBSD$

PORTNAME=	fswatch
DISTVERSION=	0.02beta5
CATEGORIES=	security sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-0.02beta5

MAINTAINER=	ports@FreeBSD.org
COMMENT=	File system checksum checker

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--enable-regex \
		--enable-stflags

SUB_FILES=	pkg-message

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:C/.b/beta/}/

post-patch:
	@${REINPLACE_CMD} '/INSTALL/ s|prefix)|DESTDIR)$$(&|' \
		${WRKSRC}/examples/Makefile.in

.include <bsd.port.mk>
