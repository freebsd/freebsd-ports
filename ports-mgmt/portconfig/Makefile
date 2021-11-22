PORTNAME=	portconfig
PORTVERSION=	0.0.0.g20211122
CATEGORIES=	ports-mgmt

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Utility to set up FreeBSD port options

LICENSE=	BSD2CLAUSE

USE_GITLAB=	yes
GL_ACCOUNT=	alfix
GL_COMMIT=	49d968fbd5f8285b53f3527708e45544dd456c48

USES=		localbase:ldflags
BUILD_DEPENDS=	${LOCALBASE}/lib/libbsddialog.a:devel/bsddialog

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>

