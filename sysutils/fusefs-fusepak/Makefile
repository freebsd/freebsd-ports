PORTNAME=	fusepak
PORTVERSION=	0.5
CATEGORIES=	sysutils games
MASTER_SITES=	SF
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mount packed data files of various games (PACK, WAD, etc.)

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USES=		fuse pkgconfig tar:bzip2

PLIST_FILES=	bin/pakmount man/man1/pakmount.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's,Linux,${OPSYS}, ; s,Fatnasy,Fantasy,' \
		${WRKSRC}/src/pakmount.1

.include <bsd.port.mk>
