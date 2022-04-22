PORTNAME=	portconfig
PORTVERSION=	0.3
CATEGORIES=	ports-mgmt

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Utility to set up FreeBSD port options

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${LOCALBASE}/lib/libbsddialog.a:devel/bsddialog

USES=		localbase:ldflags

USE_GITLAB=	yes
GL_ACCOUNT=	alfix
GL_COMMIT=	d8863468ba3f5927a6f27180ec18b21724a24fcf

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz \

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
