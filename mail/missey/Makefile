PORTNAME=	missey
PORTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.dengh.com/missey/
MASTER_SITES+=	LOCAL/delphij
DISTNAME=	mps.${PORTVERSION}

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Secure small and high performance POP3 server

USES=	tar:bzip2

MAKE_ENV+=	INSTALL_PROGRAM="${INSTALL_PROGRAM}" WRKSRC="${WRKSRC}" \
		INSTALL_DATA="${INSTALL_DATA}" MKDIR="${MKDIR}"

PLIST_FILES=	sbin/bent sbin/mps etc/mps/pop3d.conf-dist

USE_RC_SUBR=	mps

post-extract:
	@${MV} ${WRKDIR}/mps/src ${WRKSRC}
	@${RM} -r ${WRKDIR}/mps

post-patch:
	@${CP}	${FILESDIR}/Makefile ${WRKSRC}/Makefile

.include <bsd.port.mk>
