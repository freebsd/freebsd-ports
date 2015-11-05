# $FreeBSD$

PORTNAME=	colwide
PORTVERSION=	0.01
CATEGORIES=	misc perl5
MASTER_SITES=	http://www.neelc.org/files/colwide/
EXTRACT_SUFX=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	neel@neelc.org
COMMENT=	Utility which outputs a number of characters to the screen

LICENSE=	BSD2CLAUSE

USES=		perl5 shebangfix
USE_PERL5=	run
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

SHEBANG_FILES=	colwide

PLIST_FILES=	bin/${PORTNAME}

do-extract:
	${CP} ${DISTDIR}/colwide-${PORTVERSION} ${WRKSRC}/colwide

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/colwide ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
