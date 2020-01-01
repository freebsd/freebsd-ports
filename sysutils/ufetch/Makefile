# $FreeBSD$

PORTNAME=	ufetch
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2
CATEGORIES=	sysutils

MAINTAINER=	vulcan@wired.sh
COMMENT=	Tiny system info for Unix-like operating systems

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITLAB=	yes

GL_ACCOUNT=	jschx
GL_COMMIT=	9831ec29c6ec3b105a7a1c3573f58f4f7c414e09

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/ufetch

post-patch:
	${REINPLACE_CMD} -e 's|-freebsd||g' ${WRKSRC}/${PORTNAME}-freebsd

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}-freebsd \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
