# Created by: Kevin Lo <kevlo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vtun
PORTVERSION=	3.0.3
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Virtual Tunnels over TCP/IP networks with traffic shaping

LIB_DEPENDS=	lzo2.2:${PORTSDIR}/archivers/lzo2

MAN5=		vtund.conf.5
MAN8=		vtund.8
MLINKS=		vtund.8 vtun.8

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

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${CC} == "clang" || ${CXX} == "clang++" || ${OSVERSION} >= 1000026
EXTRA_PATCHES+= ${FILESDIR}/extra-cfg_file.y
.endif

.if defined(VTUN_EXTENDED_MODE)
# Obtained from http://home.jp.FreeBSD.org/~simokawa/vtun-v6.html
EXTRA_PATCHES+=	${FILESDIR}/extra-tun_dev.c
.endif

post-install:
	@${STRIP_CMD} ${PREFIX}/sbin/vtund
	@${INSTALL_DATA} ${WRKSRC}/vtund.conf ${PREFIX}/etc/vtund.conf.example
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
