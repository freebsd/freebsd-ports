# Created by: Gavin McDonald <gavin@16degrees.com.au>
# $FreeBSD$

PORTNAME=	orthrus
PORTVERSION=	0.8.0
CATEGORIES=	security
MASTER_SITES=	GOOGLE_CODE  \
		http://16degrees.com.au/${PORTNAME}/

MAINTAINER=	gavin@16degrees.com.au
COMMENT=	One-Time Password System (OTP) alternative to OPIE or S/Key

LICENSE=	AL2

LIB_DEPENDS=	apr-1:${PORTSDIR}/devel/apr1

USE_SCONS=	yes
USE_BZIP2=	yes
USE_LDCONFIG=	yes
USES=		iconv
PORTDOCS=	*

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && \
		${INSTALL_DATA} NOTICE README TODO ${DOCSDIR})
.endif
	${TOUCH} ${PREFIX}/etc/orthruskeys

	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
