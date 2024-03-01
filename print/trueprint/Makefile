PORTNAME=	trueprint
PORTVERSION=	5.4
PORTREVISION=	3
CATEGORIES=	print
MASTER_SITES=	GNU

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Print program listings on postscript printer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gettext gmake
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
LDFLAGS+=	-L${LOCALBASE}/lib -lintl

INFO=		trueprint

PLIST_FILES=	bin/trueprint share/man/man1/trueprint.1.gz

.include <bsd.port.mk>
