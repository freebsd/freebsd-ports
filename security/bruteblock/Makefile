PORTNAME=	bruteblock
PORTVERSION=	0.0.5
PORTREVISION=	11
CATEGORIES=	security
MASTER_SITES=	https://samm.kiev.ua/bruteblock/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Software for blocking bruteforce attacks with ipfw
WWW=		https://samm.kiev.ua/bruteblock/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/doc/LICENSE

LIB_DEPENDS=	libpcre.so:devel/pcre

SUB_FILES=	pkg-message

USE_RC_SUBR=	bruteblockd

CONFDIR=	${PREFIX}/etc/${PORTNAME}

PORTDOCS=	FAQ README CHANGES

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bruteblock ${STAGEDIR}${PREFIX}/sbin/
	${INSTALL_PROGRAM} ${WRKSRC}/bruteblockd ${STAGEDIR}${PREFIX}/sbin/
	@${MKDIR} ${STAGEDIR}${CONFDIR}
.for file in ssh proftpd
	${INSTALL_DATA} ${WRKSRC}/etc/${file}.conf ${STAGEDIR}${CONFDIR}/${file}.conf.sample
.endfor
	${INSTALL_MAN} ${WRKSRC}/doc/bruteblock.8 ${STAGEDIR}${PREFIX}/share/man/man8/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
