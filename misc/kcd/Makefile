# New ports collection makefile for:	kcd
# Version required:			4.11.1
# Date created:				5 May 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=		kcd-4.11.1
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SUNSITE} \
			http://www-scf.usc.edu/~lerdsuwa/util/
MASTER_SITE_SUBDIR=	utils/shell

MAINTAINER=		ports@FreeBSD.org

LIB_DEPENDS=		ncurses.4:${PORTSDIR}/devel/ncurses

GNU_CONFIGURE=		yes
CONFIGURE_ENV=		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include/ncurses -I${LOCALBASE}/include" \
			LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"
MAN1=			kcd.1

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/kcdmain ${PREFIX}/bin
	@ ${INSTALL_SCRIPT} ${WRKSRC}/kcdscr ${PREFIX}/bin
	@ ${INSTALL_MAN} ${WRKSRC}/kcd.1 ${PREFIX}/man/man1
	@ ${MKDIR} ${PREFIX}/share/examples/kcd
	@ ${INSTALL_DATA} ${WRKSRC}/kcd.csh.init ${PREFIX}/share/examples/kcd
	@ ${INSTALL_DATA} ${WRKSRC}/kcd.sh.init ${PREFIX}/share/examples/kcd

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/kcd
.for file in CHANGES COPYING INSTALL README
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/kcd
.endfor
.endif

.include <bsd.port.mk>
