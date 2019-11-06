# $FreeBSD$

PORTNAME=	nfsping
PORTVERSION=	0.1.20131017
CATEGORIES=	sysutils net-mgmt
MASTER_SITES=	GH \
		LOCAL/bdrewery/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command line tool to check NFS server response times

BROKEN=		unfetchable

LICENSE=	BSD2CLAUSE

OPTIONS_DEFINE=	DOCS SMOKEPING
OPTIONS_DEFAULT=SMOKEPING
OPTIONS_SUB=	yes
SMOKEPING_DESC=	Install Smokeping probe

USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	mprovost
GH_PROJECT=	NFSping
GH_TAGNAME=	460c382

PORTDOCS=	README

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MSMOKEPING}
	${MKDIR} ${STAGEDIR}${PREFIX}/smokeping/lib/Smokeping/probes
	${INSTALL_DATA} ${WRKSRC}/Smokeping/NFSping.pm \
	    ${STAGEDIR}${PREFIX}/smokeping/lib/Smokeping/probes
.endif

.include <bsd.port.mk>
