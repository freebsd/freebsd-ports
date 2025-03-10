PORTNAME=	loaders-update
DISTVERSION=	1.2.1
CATEGORIES=	sysutils
MASTER_SITES=	GH

MAINTAINER=	kmachine@free.fr
COMMENT=	Update bootcodes and loaders
WWW=		https://github.com/emrion/uploaders/

LICENSE=	BSD2CLAUSE

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	Utility is specific to amd64's boot code

GH_PROJECT=	uploaders
USE_GITHUB=	yes
GH_ACCOUNT=	emrion

NO_BUILD=	yes

PLIST_FILES=	sbin/${PORTNAME} \
		share/man/man8/${PORTNAME}.8.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/sbin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 \
		${STAGEDIR}${PREFIX}/share/man/man8/

.include <bsd.port.mk>
