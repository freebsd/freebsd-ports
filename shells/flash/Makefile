# New ports collection makefile for:	flash
# Date created:		11 Dec 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	flash
PORTVERSION=	0.9.4
PORTREVISION=	1
CATEGORIES=	shells
MASTER_SITES=	http://www.netsoc.ucd.ie/flash/ \
		ftp://ftp.netsoc.ucd.ie/pub/computing/flash/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A ncurses-based restriction shell

.include <bsd.port.pre.mk>

# outdated version of ncurses in non-CURRENT
.if ${OSVERSION} < 400000
LIB_DEPENDS=	ncurses.5:${PORTSDIR}/devel/ncurses
.endif

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

MAN1=		flash.1

PROGRAM=	alarms background countdown
SCRIPT=		mailshell system.menu system.menu.9798 system.menu.oldlast \
		system.menu.old
DATA=		system.bg.Netsoc.3 system.bg.Netsoc.4 system.flashlogin \
		system.maillogin system.module system.module.9798 system.rc \
		system.rc.mailshell

.if ${OSVERSION} < 400000
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include -DHAVE_NCURSES_NCURSES_H" \
		LDFLAGS="-L${LOCALBASE}/lib"
.endif

post-patch:
.for file in ${SCRIPT}
	@${REINPLACE_CMD} -e "s:/usr/slocal:${PREFIX}:g" ${WRKSRC}/orcasetup/${file}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/flash ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/flash.1 ${MANPREFIX}/man/man1
	@${MKDIR} ${PREFIX}/lib/flash
	${INSTALL_DATA} ${WRKSRC}/Manual ${PREFIX}/lib/flash
.for file in ${PROGRAM}
	${INSTALL_PROGRAM} ${WRKSRC}/modules/${file} ${PREFIX}/lib/flash
.endfor
.for file in ${SCRIPT}
	${INSTALL_SCRIPT} ${WRKSRC}/orcasetup/${file} ${PREFIX}/lib/flash
.endfor
.for file in ${DATA}
	${INSTALL_DATA} ${WRKSRC}/orcasetup/${file} ${PREFIX}/lib/flash
.endfor
	@${MKDIR} ${PREFIX}/lib/flash/flashdocs
	${INSTALL_DATA} ${WRKSRC}/orcasetup/flashdocs/* ${PREFIX}/lib/flash/flashdocs

post-install:
	@${ECHO_MSG} "Updating /etc/shells"
	@${CP} /etc/shells /etc/shells.bak
	@(${GREP} -v ${PREFIX}/bin/flash /etc/shells.bak; \
	${ECHO_CMD} ${PREFIX}/bin/flash) > /etc/shells
	@${RM} /etc/shells.bak
	@${SED} -e "s:/usr/local:${PREFIX}:g" ${PKGMESSAGE}

.include <bsd.port.post.mk>
