# Created by: bmc@WillsCreek.COM
# $FreeBSD$

PORTNAME=	gnuls
PORTVERSION=	8.20
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	coreutils
DISTNAME=	coreutils-${PORTVERSION}

MAINTAINER=	bmc@clapper.org
COMMENT=	GNU colorized 'ls'

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib" FORCE_UNSAFE_CONFIGURE=1
CPPFLAGS+=	-I${LOCALBASE}/include

USE_XZ=		yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_PERL5_BUILD=yes # Required for tests and man page generation

MAN1=		gnuls.1 dircolors.1 dir.1 vdir.1

PLIST_FILES=	bin/dir \
		bin/dircolors \
		bin/gnuls \
		bin/vdir

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/dir ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/dircolors ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/ls ${PREFIX}/bin/gnuls
	${INSTALL_PROGRAM} ${WRKSRC}/src/vdir ${PREFIX}/bin
	${CP} ${WRKSRC}/man/ls.1 ${WRKSRC}/man/gnuls.1
	${INSTALL_MAN} ${MAN1:S,^,${WRKSRC}/man/,} ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
