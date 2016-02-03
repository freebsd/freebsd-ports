# Created by: Will Andrews <andrews@technologist.com>
# $FreeBSD$

PORTNAME=	flash
PORTVERSION=	0.9.5
CATEGORIES=	shells
MASTER_SITES=	http://www.sourcefiles.org/Shells/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ncurses-based restriction shell

USES=		gmake ncurses
GNU_CONFIGURE=	yes
LDFLAGS+=	-rdynamic
CFLAGS+=	-rdynamic
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

PROGRAM=	alarms background countdown
SCRIPT=		mailshell system.menu system.menu.9798 system.menu.oldlast \
		system.menu.old
DATA=		system.bg.Netsoc.3 system.bg.Netsoc.4 system.flashlogin \
		system.maillogin system.module system.module.9798 system.rc \
		system.rc.mailshell

post-patch:
.for file in ${SCRIPT}
	@${REINPLACE_CMD} -e "s:/usr/slocal:${PREFIX}:g" ${WRKSRC}/orcasetup/${file}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/flash ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/flash.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/flash
	${INSTALL_DATA} ${WRKSRC}/Manual ${STAGEDIR}${PREFIX}/lib/flash
.for file in ${PROGRAM}
	${INSTALL_PROGRAM} ${WRKSRC}/modules/${file} ${STAGEDIR}${PREFIX}/lib/flash
.endfor
.for file in ${SCRIPT}
	${INSTALL_SCRIPT} ${WRKSRC}/orcasetup/${file} ${STAGEDIR}${PREFIX}/lib/flash
.endfor
.for file in ${DATA}
	${INSTALL_DATA} ${WRKSRC}/orcasetup/${file} ${STAGEDIR}${PREFIX}/lib/flash
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/flash/flashdocs
	${INSTALL_DATA} ${WRKSRC}/orcasetup/flashdocs/* ${STAGEDIR}${PREFIX}/lib/flash/flashdocs

.include <bsd.port.mk>
