# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	bruteblock
PORTVERSION=	0.0.5
PORTREVISION=	9
CATEGORIES=	security
MASTER_SITES=	http://samm.kiev.ua/bruteblock/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Software for blocking bruteforce attacks with ipfw

LIB_DEPENDS=	libpcre.so:devel/pcre

PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message

USE_RC_SUBR=	bruteblockd

CONFDIR=	${PREFIX}/etc/${PORTNAME}

PORTDOCS=	FAQ README CHANGES

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bruteblock ${STAGEDIR}${PREFIX}/sbin/
	${INSTALL_PROGRAM} ${WRKSRC}/bruteblockd ${STAGEDIR}${PREFIX}/sbin/
	${MKDIR} ${STAGEDIR}${CONFDIR}
.for file in ssh proftpd
	${INSTALL_DATA} ${WRKSRC}/etc/${file}.conf ${STAGEDIR}${CONFDIR}/${file}.conf.sample
.endfor
	${INSTALL_MAN} ${WRKSRC}/doc/bruteblock.8 ${STAGEDIR}${MAN8PREFIX}/man/man8/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
