# New ports collection makefile for:	crashmail
# Date created:				21 January 2003
# Whom:					Max Khon <fjoe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	crashmail
PORTVERSION=	0.70
PORTREVISION=	1
CATEGORIES=	news mail
MASTER_SITES=	http://www.df.lth.se/~billing/crashmail/
DISTNAME=	cm07linux

MAINTAINER=	vk@vk.pp.ru
COMMENT=	CrashMail II FTN mail tosser

WRKSRC=		${WRKDIR}/CrashMail
BUILD_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=	${WRKSRC}/src
ALL_TARGET=	linux

USE_ZIP=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} \
	  -e 's^"crashmail.prefs"^"${PREFIX}/etc/crashmail/crashmail.prefs"^' \
	  ${WRKSRC}/src/oslib_linux/os_linux.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/crashexport ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/crashgetnode ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/crashlist ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/crashmail ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/crashmaint ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/crashstats ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/crashwrite ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/etc/crashmail
	${INSTALL_DATA} ${WRKSRC}/doc/example.prefs ${PREFIX}/etc/crashmail
	${INSTALL_DATA} ${WRKSRC}/doc/AreafixHelp.txt \
		${PREFIX}/etc/crashmail/areafix.help

.include <bsd.port.mk>
