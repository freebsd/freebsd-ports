PORTNAME=	portconfig
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	ports-mgmt

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Utility to set up FreeBSD port options

LICENSE=	BSD2CLAUSE

USE_GITLAB=	yes
GL_ACCOUNT=	alfix
GL_COMMIT=	0292159f4e2431a2f7c1cebe13e28de34d0c8932

USES=		localbase:ldflags
BUILD_DEPENDS=	${LOCALBASE}/lib/libbsddialog.a:devel/bsddialog

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>

