# Created by: bmc@WillsCreek.COM
# $FreeBSD$

PORTNAME=	gnuls
PORTVERSION=	8.22
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	GNU/coreutils
DISTNAME=	coreutils-${PORTVERSION}

MAINTAINER=	bmc@clapper.org
COMMENT=	GNU colorized 'ls'

OPTIONS_DEFINE=		NLS
NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	FORCE_UNSAFE_CONFIGURE=1
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

USES=		gmake perl5 tar:xz
USE_LDCONFIG=	yes
USE_PERL5=	build

PLIST_FILES=	bin/dir \
		bin/dircolors \
		bin/gnuls \
		bin/vdir \
		man/man1/dir.1.gz \
		man/man1/dircolors.1.gz \
		man/man1/gnuls.1.gz \
		man/man1/vdir.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/dir ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/dircolors ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/ls ${STAGEDIR}${PREFIX}/bin/gnuls
	${INSTALL_PROGRAM} ${WRKSRC}/src/vdir ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/dir.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/dircolors.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/ls.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/gnuls.1
	${INSTALL_MAN} ${WRKSRC}/man/vdir.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
