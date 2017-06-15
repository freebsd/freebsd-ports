# Created by: Kevin Lo <kevlo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vtun
PORTVERSION=	3.0.4
PORTREVISION=	5
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Virtual Tunnels over TCP/IP networks with traffic shaping

LICENSE=        GPLv2

LIB_DEPENDS=	liblzo2.so:archivers/lzo2

CFLAGS+=	-ansi -Wno-pointer-sign -I${LOCALBASE}/include
USES=		autoreconf ssl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var \
		--with-ssl-headers=${OPENSSLINC} \
		--with-ssl-lib=${OPENSSLLIB} \
		--with-lzo-headers=${LOCALBASE}/include/lzo \
		--with-lzo-lib=${LOCALBASE}/lib
CONFIGURE_ENV=	YACC=${YACC}
USE_RC_SUBR=	vtunclient vtund

ALL_TARGET=	vtund

DOCS=		ChangeLog Credits FAQ README README.LZO README.Setup \
		README.Shaper TODO

OPTIONS_DEFINE=	DOCS

# Extended mode patches, obtained from
# http://home.jp.FreeBSD.org/~simokawa/vtun-v6.html
# are now dynamically enabled using the -e option.

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} \
		-e 's|$$\(SSL_HDR_DIR\)|$$\1 $$\1/openssl|g' \
		-e 's|$$\(BLOWFISH_HDR_DIR\)|$$\1 $$SSL_HDR_DIR/openssl|g' \
		${WRKSRC}/configure

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/vtund
	@${INSTALL_DATA} ${WRKSRC}/vtund.conf ${STAGEDIR}${PREFIX}/etc/vtund.conf.sample
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor
	@cd ${STAGEDIR}${PREFIX}/man/man1/ && \
	${LN} -s vtund.8 ../man1/vtun.1

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT:Mopenssl-devel}
BROKEN=		Does not build with openssl-devel
.endif

.include <bsd.port.post.mk>
