PORTNAME=	ufetch
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3
CATEGORIES=	sysutils

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Tiny system info for Unix-like operating systems
WWW=		https://gitlab.com/jschx/ufetch/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITLAB=	yes
GL_ACCOUNT=	jschx

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME}

post-patch:
	${REINPLACE_CMD} -e 's|-freebsd||g' ${WRKSRC}/${PORTNAME}-freebsd

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}-freebsd \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
