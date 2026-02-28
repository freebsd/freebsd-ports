PORTNAME=	fiche
PORTVERSION=	0.9.1
PORTREVISION=	4
CATEGORIES=	net

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Command line pastebin for sharing terminal output
WWW=		https://github.com/solusipse/fiche

LICENSE=	MIT

USES=		compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	solusipse

USE_RC_SUBR=	${PORTNAME}
SUB_FILES=	pkg-message

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/sbin ${STAGEDIR}${WWWDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
