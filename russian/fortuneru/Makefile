# New ports collection makefile for:   fortuneru
# Date created:        26-09-2001
# Whom:                bestia@iptcom.net
#
# $FreeBSD$
#

PORTNAME=	fortuneru
PORTVERSION=	0.4
CATEGORIES=	russian
MASTER_SITES=	ftp://de22.kiev.ua/pub/files/ \
		ftp://hosting.cvu.kiev.ua/pub/files/ \
		ftp://viva-solutions.com/pub/files/
DISTNAME=	fortune.ru-${PORTVERSION}

MAINTAINER=	bestia@de22.kiev.ua
COMMENT=	Fortunes in russian

NO_BUILD=	yes

PKGMESSAGE=	${WRKDIR}/pkg-message

STRCMD=		/usr/games/strfile

do-install:
	@${SETENV} STRCMD=${STRCMD} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
	@${MKDIR} ${PREFIX}/share/games/fortune/rus
	${INSTALL_DATA} ${WRKSRC}/* ${PREFIX}/share/games/fortune/rus

pre-install:
.if !exists(${STRCMD})
	@${ECHO_MSG}   "Please install the games distribution"
	@exit 1
.endif

post-install:
	@for fortune in ${PREFIX}/share/games/fortune/rus/* ; do \
		${STRCMD} $$fortune >/dev/null 2>/dev/null ; \
		done
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Usage:"
	@${ECHO_MSG} "/usr/games/fortune ${PREFIX}/share/games/fortune/rus"
	@${ECHO_MSG} ""

.include <bsd.port.mk>
