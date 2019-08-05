# Created by: Anton Karpov <toxa@toxahost.ru>
# $FreeBSD$

PORTNAME=	weplab
PORTVERSION=	0.1.5
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	WepLab is a tool designed to teach how WEP works

BROKEN=		unfetchable

GNU_CONFIGURE=	yes
USE_CSTD=	gnu89

PLIST_FILES=	bin/weplab \
		man/man1/weplab.1.gz

post-patch:
	@${REINPLACE_CMD} -E 's,^(CC|CFLAGS|LDFLAGS) *=,\1 ?=,g' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
