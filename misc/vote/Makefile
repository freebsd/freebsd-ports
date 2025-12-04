PORTNAME=	vote
DISTVERSION=	1.2
CATEGORIES=	misc
MASTER_SITES=	https://codeberg.org/tcberner/${PORTNAME}/raw/v${DISTVERSION}/
DISTFILES=	${PORTNAME}
DIST_SUBDIR=	vote-${DISTVERSION}
EXTRACT_ONLY=	#

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Transparent git based voting system
WWW=		https://codeberg.org/tcberner/vote

LICENSE=	BSD2CLAUSE

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/vote

do-install:
	${INSTALL_SCRIPT} ${DISTDIR}/${DIST_SUBDIR}/vote ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
