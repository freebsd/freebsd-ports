# $FreeBSD$

PORTNAME=	nstat
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Replacement for bw/netstat/vmstat/pcm-memory.x

RUN_DEPENDS=	pcm.x:sysutils/intel-pcm

NO_FETCH=	yes

PLIST_FILES=	bin/nstat \
		man/man1/nstat.1.gz

do-extract:
	@${MKDIR} ${WRKSRC}
	@(cd ${FILESDIR} && ${CP} -R . ${WRKSRC})

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/nstat ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/nstat.1.gz ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} <= 1200027
BROKEN=		Does not build without clock_nanosleep
.endif

.include <bsd.port.post.mk>
