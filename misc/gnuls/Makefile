PORTNAME=	gnuls
PORTVERSION=	9.1
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	GNU/coreutils
DISTNAME=	coreutils-${PORTVERSION}

MAINTAINER=	bmc@clapper.org
COMMENT=	GNU colorized 'ls'

USES=		gmake localbase perl5 tar:xz
USE_LDCONFIG=	yes
USE_PERL5=	build

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	FORCE_UNSAFE_CONFIGURE=1

CONFLICTS_INSTALL=	opendircolors # bin/dircolors

PLIST_FILES=	bin/dir \
		bin/dircolors \
		bin/gnuls \
		bin/vdir \
		share/man/man1/dir.1.gz \
		share/man/man1/dircolors.1.gz \
		share/man/man1/gnuls.1.gz \
		share/man/man1/vdir.1.gz

OPTIONS_DEFINE=		NLS
NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/dir ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/dircolors ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/ls ${STAGEDIR}${PREFIX}/bin/gnuls
	${INSTALL_PROGRAM} ${WRKSRC}/src/vdir ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/dir.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/dircolors.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/ls.1 ${STAGEDIR}${PREFIX}/share/man/man1/gnuls.1
	${INSTALL_MAN} ${WRKSRC}/man/vdir.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
