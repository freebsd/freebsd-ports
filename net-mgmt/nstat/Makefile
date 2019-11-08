# $FreeBSD$

PORTNAME=	nstat
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	net-mgmt

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Replacement for bw/netstat/vmstat/pcm-memory.x

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	pcm.x:sysutils/intel-pcm

USE_GITHUB=	yes
GH_ACCOUNT=	gallatin
GH_TAGNAME=	30de621

PLIST_FILES=	bin/nstat \
		man/man1/nstat.1.gz

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/nstat ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/nstat.1.gz ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} <= 1200027
BROKEN=		Does not build without clock_nanosleep
.endif

.include <bsd.port.post.mk>
