PORTNAME=	atomicparsley
PORTVERSION=	20210114.184825.1dbe1be
CATEGORIES=	multimedia

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command line program for reading parsing and setting MP4/M4A metadata

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	wez
PLIST_FILES=	bin/AtomicParsley

do-install:
	${INSTALL_PROGRAM} ${PLIST_FILES:Mbin/*:T:S,^,${INSTALL_WRKSRC}/,} \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
