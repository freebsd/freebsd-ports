# Created by: Max Khon <fjoe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	crashmail
PORTVERSION=	0.71
CATEGORIES=	news mail
MASTER_SITES=	http://www.billingware.org/crashmail/
DISTNAME=	cm071linux

MAINTAINER=	vk@vk.pp.ru
COMMENT=	CrashMail II FTN mail tosser

BROKEN=		unfetchable

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
BUILD_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=	${WRKSRC}/src
ALL_TARGET=	linux

USES=		gmake zip

post-patch:
	@${REINPLACE_CMD} \
		-e 's^"crashmail.prefs"^"${PREFIX}/etc/crashmail/crashmail.prefs"^' \
		${WRKSRC}/src/oslib_linux/os_linux.h
	@${FIND} ${WRKSRC} -name 'Makefile*' | ${XARGS} ${REINPLACE_CMD} \
		-e 's|gcc|${CC}|'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/crashexport ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/crashgetnode ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/crashlist ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/crashmail ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/crashmaint ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/crashstats ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/crashwrite ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/example.prefs ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/AreafixHelp.txt \
		${STAGEDIR}${ETCDIR}/areafix.help

.include <bsd.port.mk>
