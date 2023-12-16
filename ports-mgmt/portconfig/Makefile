PORTNAME=	portconfig
DISTVERSION=	0.6.1
CATEGORIES=	ports-mgmt

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Utility to set up FreeBSD port options
WWW=		https://gitlab.com/alfix/portconfig

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/lib/libbsddialog.a:devel/bsddialog

USES=		localbase:ldflags

USE_GITLAB=	yes
GL_ACCOUNT=	alfix

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
