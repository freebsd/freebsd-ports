# New ports collection makefile for:	trafficserver
# Date created:		2010-08-15
# Whom:			Jui-Nan Lin <jnlin@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	trafficserver
PORTVERSION=	2.1.4
CATEGORIES=	www
MASTER_SITES=	APACHE/${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}-unstable

MAINTAINER=	jnlin@csie.nctu.edu.tw
COMMENT=	A fast, scalable and extensible HTTP proxy server

LICENSE=	ASL

LIB_DEPENDS=	execinfo.1:${PORTSDIR}/devel/libexecinfo \
		expat.6:${PORTSDIR}/textproc/expat2 \
		pcre.0:${PORTSDIR}/devel/pcre

USE_AUTOTOOLS=	autoconf:268 automake:111 libtool:22
USE_BZIP2=	yes
USE_ICONV=	yes
USE_OPENSSL=	yes
USE_SQLITE=	yes
USE_TCL=	yes
USE_RC_SUBR=	${PORTNAME}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800505 || (${OSVERSION} >= 900000 && ${OSVERSION} < 900012)
BUILD_DEPENDS=	xz>0:${PORTSDIR}/archivers/xz
RUN_DEPENDS=	xz>0:${PORTSDIR}/archivers/xz
.endif

.if ${OSVERSION} < 700000
IGNORE=		only supports 7.0 and above
.endif

pre-configure:
	@cd ${WRKSRC} && ${AUTORECONF} -i

.include <bsd.port.post.mk>
