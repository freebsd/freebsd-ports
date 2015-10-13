# Created by: James FitzGibbon <jfitz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	diablo
PORTVERSION=	5.1
PORTREVISION=	2
CATEGORIES=	news
MASTER_SITES=	http://www.openusenet.org/diablo/download/
DISTNAME=	${PORTNAME}-${PORTVERSION}-REL

MAINTAINER=	lifanov@mail.lifanov.com
COMMENT=	Comprehensive newsfeeding and newsreading software package

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	xmake:${PORTSDIR}/devel/xmake

PORTDOCS=	COPYRIGHT INSTALL README.READER README.SERVER RELEASE_NOTES

OPTIONS_DEFINE=	DES DOCS
DES_DESC=	DES encryption support

USES=		tar:tgz

post-patch:
	@${CP} ${FILESDIR}/diablo.in ${WRKDIR}/diablo
	@${REINPLACE_CMD} -E 's|%%PREFIX%%|${STAGEDIR}${PREFIX}|g ;\
		s|-g -O.?|${CFLAGS}| ; s|g?cc|${CC}|' \
		${WRKSRC}/XMakefile.inc
	@${REINPLACE_CMD} -E 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKDIR}/diablo ${WRKSRC}/XMakefile.inst
# Fix for GCC 4.2
	@${REINPLACE_CMD} -e 's|VServerConfig\[\]|*VServerConfig|' \
		${WRKSRC}/dreaderd/main.c

post-patch-DES-off:
	@${REINPLACE_CMD} -e 's| -ldes||g' ${WRKSRC}/XMakefile.inc

do-build:
	(cd ${WRKSRC} && xmake all)

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/news/dbin
	${MKDIR} ${STAGEDIR}${PREFIX}/news/dqueue
	${MKDIR} ${STAGEDIR}${PREFIX}/news/spool
	${MKDIR} ${STAGEDIR}${PREFIX}/news/spool/news
	${MKDIR} ${STAGEDIR}${PREFIX}/news/spool/cache
	${MKDIR} ${STAGEDIR}${PREFIX}/news/spool/group
	${MKDIR} ${STAGEDIR}${PREFIX}/news/spool/postq
	(cd ${WRKSRC} && xmake install)
	@${RM} -rf ${STAGEDIR}${PREFIX}/news/man
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/news/dbin/*
	${INSTALL_SCRIPT} ${WRKDIR}/diablo ${STAGEDIR}${PREFIX}/etc/rc.d

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
