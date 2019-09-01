# $FreeBSD$

PORTNAME=	ufetch
DISTVERSION=	0.1-1
CATEGORIES=	sysutils

MAINTAINER=	vulcan@wired.sh
COMMENT=	Tiny system info for Unix-like operating systems

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITLAB=	yes

GL_ACCOUNT=	jschx
GL_COMMIT=	544c670443be515b07512afccb1adf22d9a3825f

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/ufetch

post-patch:
	${REINPLACE_CMD} -e 's/-freebsd//g' ${WRKSRC}/ufetch-freebsd

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}-freebsd \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
