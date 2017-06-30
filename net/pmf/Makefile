# Created by: adam
# $FreeBSD$

PORTNAME=	pmf
PORTVERSION=	1.13.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://ftp.ntua.gr/pub/net/mud/lpmud/clients/pmf/ \
		LOCAL/glarkin

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Padrone's Mud Frontend

BROKEN_powerpc64=	fails to link: ld: cannot find -lreadline

WRKSRC=		${WRKDIR}/pmfdir
BUILD_WRKSRC=	${WRKDIR}/pmfdir/src
PATCH_WRKSRC=	${WRKDIR}/pmfdir/src

USES=		readline

SUB_FILES=	pmfrc.default

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.pre.mk>

.if !exists(/usr/lib/libreadline.so)
BROKEN=	Does not build with modern readline from ports
.endif

post-build:
	@${LN} -sf .pmfrc ${WRKSRC}/examples/dot.pmfrc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/pmf ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/system_dir/NEWS ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/pmfrc.default ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/system_dir && ${COPYTREE_SHARE} helpfiles ${STAGEDIR}${DATADIR})
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.post.mk>
