PORTNAME=	xmail
PORTVERSION=	1.6
PORTREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	XCONTRIB/applications
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	cy@FreeBSD.org
COMMENT=	X-based interface to the Berkeley mail program

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		imake xorg
USE_XORG=	ice sm x11 xaw xbitmaps xext xmu xpm xt

CFLAGS+=	-Wno-incompatible-function-pointer-types -lutil

post-patch:
# Fix the build with -fno-common (for Clang 11 and GCC 10)
	@${REINPLACE_CMD} -e '/In_Bogus_Mail_File;/d' ${WRKSRC}/xmail.c

pre-install:
	@${ELFCTL} -e +noaslr ${WRKSRC}/xmail

.include <bsd.port.mk>
