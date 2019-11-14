# Created by: Kevin Lo <kevlo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vtun
PORTVERSION=	3.0.4
PORTREVISION=	8
CATEGORIES=	net
MASTER_SITES=	SF LOCAL/mat/vtun

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Virtual Tunnels over TCP/IP networks with traffic shaping

LICENSE=	GPLv2

LIB_DEPENDS=	liblzo2.so:archivers/lzo2

USES=		autoreconf localbase ssl
USE_RC_SUBR=	vtunclient vtund
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--localstatedir=/var \
		--with-ssl-headers=${OPENSSLINC} \
		--with-ssl-lib=${OPENSSLLIB} \
		--with-lzo-headers=${LOCALBASE}/include/lzo \
		--with-lzo-lib=${LOCALBASE}/lib
CONFIGURE_ENV=	YACC=${YACC}

CFLAGS+=	-ansi -Wno-pointer-sign

ALL_TARGET=	vtund

DOCS=		ChangeLog Credits FAQ README README.LZO README.Setup \
		README.Shaper TODO

OPTIONS_DEFINE=	DOCS

# Extended mode patches, obtained from
# http://home.jp.FreeBSD.org/~simokawa/vtun-v6.html
# are now dynamically enabled using the -e option.

post-patch:
	${REINPLACE_CMD} \
		-e 's|$$\(SSL_HDR_DIR\)|$$\1 $$\1/openssl|g' \
		-e 's|$$\(BLOWFISH_HDR_DIR\)|$$\1 $$SSL_HDR_DIR/openssl|g' \
		${WRKSRC}/configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/vtund
	${INSTALL_DATA} ${WRKSRC}/vtund.conf ${STAGEDIR}${PREFIX}/etc/vtund.conf.sample
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor
	${RLN} ${STAGEDIR}${PREFIX}/man/man8/vtund.8 ${STAGEDIR}${PREFIX}/man/man1/vtun.1

.include <bsd.port.mk>
