# Created by: Yen-Ming Lee <leeym@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cryptofs
PORTVERSION=	0.6.0
PORTREVISION=	7
CATEGORIES=	sysutils
MASTER_SITES=	http://reboot78.re.funpic.de/cryptofs/
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Encrypted filesystem for FUSE

LIB_DEPENDS=	libgcrypt.so:${PORTSDIR}/security/libgcrypt \
		libglib-2.0.so:${PORTSDIR}/devel/glib20

GNU_CONFIGURE=	yes
USES=		fuse pkgconfig tar:bzip2
DOCS=		README cryptofs.conf

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
