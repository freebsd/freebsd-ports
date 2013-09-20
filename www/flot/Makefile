# $FreeBSD$

PORTNAME=	flot
PORTVERSION=	0.7
CATEGORIES=	www devel
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	JavaScript plotting library for jQuery

LICENSE=	MIT

WRKSRC=	${WRKDIR}/${PORTNAME}

USERS=	www
GROUPS=	www

NO_BUILD=	YES

PORTDOCS=	API.txt	\
		FAQ.txt	\
		NEWS.txt \
		PLUGINS.txt \
		README.txt
PORTEXAMPLES=	*

NO_STAGE=	yes
do-install:
	@${INSTALL} -d -g ${USERS} -o ${GROUPS} ${WWWDIR}
	${INSTALL_DATA} -o www -g www ${WRKSRC}/*.js ${WWWDIR}

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
