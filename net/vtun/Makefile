# New ports collection makefile for:	vtun
# Date created:				05 Feb 2000
# Whom:					Kevin Lo <kevlo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vtun
PORTVERSION=	2.6
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
USE_AUTOCONF_VER=	213
CONFIGURE_ARGS=	--localstatedir=/var \
		--with-ssl-headers=${OPENSSLBASE}/include/openssl \
		--with-ssl-lib=${OPENSSLBASE}/lib \
		--with-lzo-headers=${LOCALBASE}/include \
		--with-lzo-lib=${LOCALBASE}/lib
CONFIGURE_ENV=	YACC=${YACC}
USE_RC_SUBR=	yes

WRKSRC=		${WRKDIR}/vtun

ALL_TARGET=	vtund
RC_SCRIPT_SUB=	PREFIX=${PREFIX} RC_SUBR=${RC_SUBR}

.if defined(VTUN_EXTENDED_MODE)
# Obtained from http://home.jp.FreeBSD.org/~simokawa/vtun-v6.html
EXTRA_PATCHES=	${FILESDIR}/extra-tun_dev.c
.endif

post-build:
	@${SED} ${RC_SCRIPT_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		<${FILESDIR}/vtund.sh >${WRKDIR}/vtund.sh
	@${SED} ${RC_SCRIPT_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		<${FILESDIR}/vtunclient.sh >${WRKDIR}/vtunclient.sh

post-install:
	@${INSTALL_DATA} ${WRKSRC}/vtund.conf ${PREFIX}/etc/vtund.conf.example
	@${MKDIR} ${PREFIX}/share/doc/vtund
.for doc in FAQ README README.Setup README.Shaper
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${PREFIX}/share/doc/vtund
.endfor
	@${INSTALL_SCRIPT} ${WRKDIR}/vtund.sh ${PREFIX}/etc/rc.d
	@${INSTALL_SCRIPT} ${WRKDIR}/vtunclient.sh ${PREFIX}/etc/rc.d

.include <bsd.port.mk>
