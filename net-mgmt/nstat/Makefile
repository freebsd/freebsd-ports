PORTNAME=	nstat
DISTVERSION=	g20250705
PORTEPOCH=	1
CATEGORIES=	net-mgmt

MAINTAINER=	glebius@FreeBSD.org
COMMENT=	Replacement for bw/netstat/vmstat/pcm-memory.x
WWW=		https://github.com/gallatin/nstat

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${RUN_DEPENDS_${ARCH}}
RUN_DEPENDS_i386=	pcm-memory:sysutils/intel-pcm
RUN_DEPENDS_amd64=	pcm-memory:sysutils/intel-pcm

USE_GITHUB=	yes
GH_ACCOUNT=	gallatin
GH_TAGNAME=	bccbdfd

PLIST_FILES=	bin/nstat \
		share/man/man1/nstat.1.gz

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/nstat ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/nstat.1.gz ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
