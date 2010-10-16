# New ports collection makefile for:	trafficserver
# Date created:		2010-08-15
# Whom:			Jui-Nan Lin <jnlin@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	trafficserver
PORTVERSION=	2.1.1
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	trafficserver
DISTNAME=	${PORTNAME}-${PORTVERSION}-unstable

MAINTAINER=	jnlin@csie.nctu.edu.tw
COMMENT=	A fast, scalable and extensible HTTP proxy server

BUILD_DEPENDS=	expat>0:${PORTSDIR}/textproc/expat2 \
		pcre>0:${PORTSDIR}/devel/pcre
LIB_DEPENDS=	execinfo.1:${PORTSDIR}/devel/libexecinfo
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_AUTOTOOLS=	autoconf:268 automake:111 libtool:22
USE_BZIP2=	yes
USE_ICONV=	yes
USE_OPENSSL=	yes
USE_SQLITE=	yes
USE_TCL=	yes
USE_RC_SUBR=	${PORTNAME}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800505 || (${OSVERSION} >= 900000 && ${OSVERSION} < 900012)
BUILD_DEPENDS+=	xz>0:${PORTSDIR}/archivers/xz
RUN_DEPENDS+=	xz>0:${PORTSDIR}/archivers/xz
.endif

.if ${OSVERSION} < 700000
IGNORE=		only supports 7.0 and above
.endif

pre-configure:
	@cd ${WRKSRC} && ${AUTORECONF} -i

.include <bsd.port.post.mk>
