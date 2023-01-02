PORTNAME=	nstat
PORTVERSION=	1.0
PORTREVISION=	4
CATEGORIES=	net-mgmt

PATCH_SITES=	https://github.com/gallatin/${PORTNAME}/commit/
PATCHFILES=	887938e948bb3f835c3554b482ad315df6cbbc0c.patch:-p1

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Replacement for bw/netstat/vmstat/pcm-memory.x
WWW=		https://github.com/gallatin/nstat

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${RUN_DEPENDS_${ARCH}}
RUN_DEPENDS_i386=	pcm-memory:sysutils/intel-pcm
RUN_DEPENDS_amd64=	pcm-memory:sysutils/intel-pcm

USE_GITHUB=	yes
GH_ACCOUNT=	gallatin
GH_TAGNAME=	89b3844

PLIST_FILES=	bin/nstat \
		man/man1/nstat.1.gz

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/nstat ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/nstat.1.gz ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
