# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pvk
PORTVERSION=	20070406
CATEGORIES=	security
MASTER_SITES=	http://www.drh-consultancy.demon.co.uk/
DISTNAME=	pvksrc
EXTRACT_SUFX=	.tgz.bin

MAINTAINER=	sobomax@FreeBSD.org
COMMENT=	Tool to convert a RSA key in PEM format into a PVK file and vice versa

USES=		ssl
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

NO_WRKSUBDIR=	yes

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT} == base
BROKEN_FreeBSD_12=	variable has incomplete type 'EVP_MD_CTX' (aka 'struct evp_md_ctx_st')
BROKEN_FreeBSD_13=	variable has incomplete type 'EVP_MD_CTX' (aka 'struct evp_md_ctx_st')
.endif

post-patch:
	${REINPLACE_CMD} -e 's|\(-lcrypto\)|$$(LDFLAGS) \1|g' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pvk ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
