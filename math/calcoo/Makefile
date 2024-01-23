PORTNAME=	calcoo
PORTVERSION=	1.3.18
PORTREVISION=	9
CATEGORIES=	math
MASTER_SITES=	SF

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	RPN and algebraic scientific calculator
WWW=		https://calcoo.sourceforge.net/

LICENSE=	GPLv2+

USES=		gnome pkgconfig
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
LIBS+=		-lm

PLIST_FILES=	bin/calcoo \
		share/man/man1/calcoo.1.gz

.include <bsd.port.mk>
