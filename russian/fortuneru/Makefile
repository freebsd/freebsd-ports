# New ports collection makefile for:   fortuneru
# Date created:        26-09-2001
# Whom:                bestia@iptcom.net
#
# $FreeBSD$
#

PORTNAME=	fortuneru
PORTVERSION=	0.2
CATEGORIES=	russian
MASTER_SITES=	ftp://de22.kiev.ua/pub/files/
DISTNAME=	fortune.ru-${PORTVERSION}

MAINTAINER=	bestia@iptcom.net

NO_BUILD=	yes

PKGMESSAGE=	${WRKDIR}/pkg-message

STRCMD=		/usr/games/strfile
FORTUNES=	4hf aphorizms beer-murphy enciklopedy fomenko fortune_rus \
		guberman marazm maxim_and_fedor murphy police speed-info \
		strug usenet verse windows_errors

do-install:
	@${SETENV} STRCMD=${STRCMD} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
	${SED} -e "s,%%PREFIX%%,${PREFIX}," < ${FILESDIR}/pkg-message.in > \
		${PKGMESSAGE}
	@${MKDIR} ${PREFIX}/share/games/fortune/rus
.for fortune in ${FORTUNES}
	${INSTALL_DATA} ${WRKSRC}/${fortune} ${PREFIX}/share/games/fortune/rus
.endfor
.for fortune in ${FORTUNES}
	${STRCMD} ${PREFIX}/share/games/fortune/rus/${fortune} \
		>/dev/null 2>/dev/null
.endfor
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
