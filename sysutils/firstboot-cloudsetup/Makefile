PORTNAME=	cloudsetup
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	https://git.sr.ht/~jornane/${PORTNAME}/archive/
PKGNAMEPREFIX=	firstboot-

MAINTAINER=	jornane@icloud.com
COMMENT=	Configure network and user when the system first boots

LICENSE=	BSD3CLAUSE

WRKSRC=		work/${PORTNAME}-${DISTNAME}
NO_BUILD=	yes
NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e "s,/usr/local,${PREFIX},g" \
		${WRKSRC}/firstboot_cloudsetup.rc

.include <bsd.port.mk>
