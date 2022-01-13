PORTNAME=	vger
PORTVERSION=	1.08
CATEGORIES=	www
MASTER_SITES=	https://tildegit.org/solene/vger/archive/
DISTFILES=	${PORTVERSION}.tar.gz

MAINTAINER=	nc@FreeBSD.org
COMMENT=	Simplistic and secure Gemini server

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_CSTD=	c99

WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	${CP} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${MAN8PREFIX}/man/man8/

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}/gemini

.include <bsd.port.mk>
