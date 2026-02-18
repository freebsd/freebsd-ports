PORTNAME=	xclipsync
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.3
CATEGORIES=	sysutils

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Trivial tool for synchronizing the clipboard between two X11 sessions

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	xclip>=0:x11/xclip

USES=		tk:wrapper
USE_GITHUB=	yes
GH_ACCOUNT=	DtxdF

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/xclipsync \
		libexec/xclipsync/smart-xclip-out.sh \
		libexec/xclipsync/xclipfrom \
		share/man/man1/xclipsync.1.gz

.include <bsd.port.mk>
