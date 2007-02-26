# New ports collection makefile for:	vtun
# Date created:				05 Feb 2000
# Whom:					Kevin Lo <kevlo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vtun
PORTVERSION=	3.0.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Virtual Tunnels over TCP/IP networks with traffic shaping

LIB_DEPENDS=	lzo.1:${PORTSDIR}/archivers/lzo

MAN5=		vtund.conf.5
MAN8=		vtund.8
MLINKS=		vtund.8 vtun.8

USE_OPENSSL=	yes
USE_AUTOTOOLS=	autoconf:259
CONFIGURE_ARGS=	--localstatedir=/var \
		--with-ssl-headers=${OPENSSLBASE}/include/openssl \
		--with-ssl-lib=${OPENSSLBASE}/lib \
		--with-lzo-headers=${LOCALBASE}/include \
		--with-lzo-lib=${LOCALBASE}/lib
CONFIGURE_ENV=	YACC=${YACC}
USE_RC_SUBR=	vtunclient vtund

ALL_TARGET=	vtund

DOCS=		ChangeLog Credits FAQ README README.LZO README.Setup \
		README.Shaper TODO

.if defined(VTUN_EXTENDED_MODE)
# Obtained from http://home.jp.FreeBSD.org/~simokawa/vtun-v6.html
EXTRA_PATCHES=	${FILESDIR}/extra-tun_dev.c
.endif

post-install:
	@${INSTALL_DATA} ${WRKSRC}/vtund.conf ${PREFIX}/etc/vtund.conf.example
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
