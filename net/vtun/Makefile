# Created by: Kevin Lo <kevlo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vtun
PORTVERSION=	3.0.3
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Virtual Tunnels over TCP/IP networks with traffic shaping

LIB_DEPENDS=	liblzo2.so:archivers/lzo2

CFLAGS+=	-ansi -Wno-pointer-sign -I${LOCALBASE}/include
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var \
		--with-ssl-headers=${OPENSSLBASE}/include/openssl \
		--with-ssl-lib=${OPENSSLBASE}/lib \
		--with-lzo-headers=${LOCALBASE}/include/lzo \
		--with-lzo-lib=${LOCALBASE}/lib
CONFIGURE_ENV=	YACC=${YACC}
USE_RC_SUBR=	vtunclient vtund

ALL_TARGET=	vtund

DOCS=		ChangeLog Credits FAQ README README.LZO README.Setup \
		README.Shaper TODO

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${CC} == "clang" || ${CXX} == "clang++" || ${OSVERSION} >= 1000026
EXTRA_PATCHES+= ${FILESDIR}/extra-cfg_file.y
.endif

.if defined(VTUN_EXTENDED_MODE)
# Obtained from http://home.jp.FreeBSD.org/~simokawa/vtun-v6.html
EXTRA_PATCHES+=	${FILESDIR}/extra-tun_dev.c
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/vtund
	@${INSTALL_DATA} ${WRKSRC}/vtund.conf ${STAGEDIR}${PREFIX}/etc/vtund.conf.sample
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor
	@${LN} -s ${PREFIX}/man/man8/vtund.8 ${STAGEDIR}${PREFIX}/man/man1/vtun.1

.include <bsd.port.post.mk>
