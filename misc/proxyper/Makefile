# Created by: globalpanic@gmx.net
# $FreeBSD$

PORTNAME=	proxyper
PORTVERSION=	347
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://http.distributed.net/pub/dcti/proxyper/ \
		ftp://ftp.distributed.net/pub/dcti/proxyper/

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	The official distributed.net v2 personal proxy

ONLY_FOR_ARCHS=	i386 amd64

USE_RC_SUBR=	${PORTNAME}
NO_BUILD=	yes

BINDIR=		${PREFIX}/distributed.net/proxy
SUB_LIST+=	BINDIR=${BINDIR}

.include <bsd.port.pre.mk>

WRKSRC=		${WRKDIR}/proxyper${PORTVERSION}-freebsd-x86

DISTNAME=	proxyper${PORTVERSION}-freebsd7-x86

do-install:
	${MKDIR} ${STAGEDIR}${BINDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/proxyper ${STAGEDIR}${BINDIR}
	${INSTALL_MAN} ${WRKSRC}/ChangeLog.txt ${STAGEDIR}${BINDIR}
	${INSTALL_MAN} ${WRKSRC}/manual.html ${STAGEDIR}${BINDIR}
	${INSTALL} -c -m 644 ${WRKSRC}/proxyper.ini ${STAGEDIR}${BINDIR}/proxyper.ini.sample

.include <bsd.port.post.mk>
