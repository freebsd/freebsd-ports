# $FreeBSD$

PORTNAME=	vger
PORTVERSION=	0.0.20210315
CATEGORIES=	www
MASTER_SITES=	https://tildegit.org/solene/vger/archive/ \
		LOCAL/nc/mirror/
DISTFILES=	365e99400a8a13546c4c060f28e23bf81d68d45e.tar.gz

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
