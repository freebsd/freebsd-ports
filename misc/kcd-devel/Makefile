# New ports collection makefile for:	kcd
# Date created:				5 May 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	kcd
PORTVERSION=	5.0.2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

.include <bsd.port.pre.mk>
.if ${OSVERSION} < 400010
LIB_DEPENDS=	ncurses.5:${PORTSDIR}/devel/ncurses
.endif

USE_NEWGCC=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include/ncurses -I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
MAN1=		kcd.1

post-patch:
	@${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/kcd.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/kcdmain ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/kcdscr ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/kcd.1 ${PREFIX}/man/man1
	@${MKDIR} ${PREFIX}/share/examples/kcd
	${INSTALL_DATA} ${WRKSRC}/kcd.csh.init ${PREFIX}/share/examples/kcd
	${INSTALL_DATA} ${WRKSRC}/kcd.sh.init ${PREFIX}/share/examples/kcd
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/kcd
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${PREFIX}/share/doc/kcd
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/kcd
.endif

.include <bsd.port.post.mk>
