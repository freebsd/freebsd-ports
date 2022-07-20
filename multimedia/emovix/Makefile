PORTNAME=	emovix
PORTVERSION=	0.9.0
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	SF/movix/eMoviX/0.9

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mini Linux distro to create bootable video CDs

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USES=		gmake perl5 shebangfix
SHEBANG_FILES=	mplayer-fonts/centralEU-cp1250/runme \
		mplayer-fonts/centralEU-iso-8859-2/runme \
		scripts/mkmovixiso scripts/movix-conf.in
NO_ARCH=	yes

.include <bsd.port.mk>
