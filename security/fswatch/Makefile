PORTNAME=	fswatch
DISTVERSION=	0.02beta5
PORTREVISION=	2
CATEGORIES=	security sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-0.02beta5

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	File system checksum checker
WWW=		https://fswatch.sourceforge.net

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--enable-regex \
		--enable-stflags
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CFLAGS+=	-fcommon

PORTSCOUT=	ignore:1

post-patch:
	@${REINPLACE_CMD} '/INSTALL/ s|prefix)|DESTDIR)$$(&|' \
		${WRKSRC}/examples/Makefile.in

.include <bsd.port.mk>
