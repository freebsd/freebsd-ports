PORTNAME=	portconfig
PORTVERSION=	0.1.1
CATEGORIES=	ports-mgmt

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Utility to set up FreeBSD port options

LICENSE=	BSD2CLAUSE

USE_GITLAB=	yes
GL_ACCOUNT=	alfix
GL_COMMIT=	222ee8a8f6a790fe6a9c72f7b615e47ecdb56399

USES=		localbase:ldflags
BUILD_DEPENDS=	${LOCALBASE}/lib/libbsddialog.a:devel/bsddialog

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>

