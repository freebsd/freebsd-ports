# $FreeBSD$

PORTNAME=	colwide
PORTVERSION=	0.01
CATEGORIES=	misc perl5

MAINTAINER=	neel@neelc.org
COMMENT=	Utility which outputs a number of characters to the screen

LICENSE=	BSD2CLAUSE

USES=		perl5 shebangfix
USE_PERL5=	run
NO_ARCH=	yes
NO_BUILD=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	neelchauhan
GH_TAGNAME=	7b32131

SHEBANG_FILES=	colwide

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/colwide ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
