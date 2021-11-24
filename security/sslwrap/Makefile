# Created by: Zahemszky, Gabor <ZGabor at CoDe dot HU>

PORTNAME=	sslwrap
PORTVERSION=	2.0.6
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://www.rickk.com/sslwrap/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Another SSL Wrapper application, which uses SSLEay/OpenSSL

# 4th clause is actually different here and does not really apply
# to FreeBSD, but the license still contains advertising clause
# making it identical to classic BSD4CLAUSE
LICENSE=	BSD4CLAUSE

DEPRECATED=	Abandonware, marked BROKEN on 12+ in 2019
EXPIRATION_DATE=2022-03-31

WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION:S/.//g}

USES=		ssl

PORTDOCS=	README docs.html
PLIST_FILES=	bin/sslwrap

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT} == base
BROKEN_FreeBSD_12=	incomplete definition of type 'struct dh_st'
BROKEN_FreeBSD_13=	incomplete definition of type 'struct dh_st'
BROKEN_FreeBSD_14=	incomplete definition of type 'struct dh_st'
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "*.[ch]" | ${XARGS} ${REINPLACE_CMD} -e \
		's|SSL_OP_NON_EXPORT_FIRST|SSL_OP_CIPHER_SERVER_PREFERENCE|g ; \
		 s|OPENSSL"|"openssl/|g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sslwrap ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.post.mk>
