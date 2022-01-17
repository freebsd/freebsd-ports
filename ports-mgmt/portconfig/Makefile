PORTNAME=	portconfig
PORTVERSION=	0.2
CATEGORIES=	ports-mgmt

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Utility to set up FreeBSD port options

LICENSE=	BSD2CLAUSE

USE_GITLAB=	yes
GL_ACCOUNT=	alfix
GL_COMMIT=	9103a17b253ead68937bfffdf9135cd6ada8a538

USES=		localbase:ldflags
BUILD_DEPENDS=	${LOCALBASE}/lib/libbsddialog.a:devel/bsddialog

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>

