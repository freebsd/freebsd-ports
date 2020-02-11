# Created by: Valerio Daelli <valerio.daelli@gmail.com>
# $FreeBSD$

PORTNAME=	geteltorito
PORTVERSION=	0.6
PORTEPOCH=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://userpages.uni-koblenz.de/~krienke/ftp/noarch/geteltorito/geteltorito/
DISTFILES=	${PORTNAME}.pl
EXTRACT_ONLY=

MAINTAINER=	valerio.daelli@gmail.com
COMMENT=	El Torito image extractor

NO_BUILD=	yes
NO_ARCH=	yes
USES=		perl5 shebangfix
USE_PERL5=	run

PLIST_FILES=	bin/${PORTNAME}
SHEBANG_FILES=	geteltorito.pl

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
