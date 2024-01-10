PORTNAME=	vger
PORTVERSION=	2.0.1
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	https://tildegit.org/solene/vger/archive/
DISTFILES=	${PORTVERSION}.tar.gz

MAINTAINER=	nc@FreeBSD.org
COMMENT=	Simplistic and secure Gemini server
WWW=		https://tildegit.org/solene/vger

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_CSTD=	c99

WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	${CP} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${PREFIX}/share/man/man8/

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}/gemini

.include <bsd.port.mk>
