PORTNAME=	ncrack
DISTVERSION=	0.7
CATEGORIES=	security

MAINTAINER=	se@FreeBSD.org
COMMENT=	High-speed network authentication cracking tool

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake ssl
USE_GITHUB=	yes
GH_ACCOUNT=	nmap

GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

.include <bsd.port.mk>
