# Created by: Maxim Tulyuk <mt@primats.org.ua>
# $FreeBSD$

PORTNAME=	mailsync
PORTVERSION=	5.2.1
PORTREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mailsync is a way of keeping a collection of mailboxes synchronized

LIB_DEPENDS=	libc-client4.so:${PORTSDIR}/mail/cclient

USES=		gmake
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-c-client=${LOCALBASE}

OPTIONS_DEFINE=	DOCS EXAMPLES

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/mailsync ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/mailsync.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS COPYING NEWS README \
		THANKS TODO ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ABSTRACT HACKING \
		mail_open_close_flowchart.dia \
		mail_open_close_flowchart.svg \
		mail_open_close_flowchart2.svg ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/examples/mailsync ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
