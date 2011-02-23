# New ports collection makefile for:	tinyproxy
# Date created:		01 Jul 1999
# Whom:			Mitsuru Yoshida <mitsuru@riken.go.jp>
#
# $FreeBSD$
#

PORTNAME=	tinyproxy
PORTVERSION=	1.8.2
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	https://banu.com/pub/tinyproxy/1.8/

MAINTAINER=	wxs@FreeBSD.org
COMMENT=	A small, efficient HTTP proxy server

BUILD_DEPENDS=	asciidoc:${PORTSDIR}/textproc/asciidoc\
		xsltproc:${PORTSDIR}/textproc/libxslt\
		xmllint:${PORTSDIR}/textproc/libxml2 \
		${LOCALBASE}/share/xsl/docbook/lib/lib.xsl:${PORTSDIR}/textproc/docbook-xsl

USE_RC_SUBR=	tinyproxy.sh
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes
CONFIGURE_ARGS=	--bindir=${PREFIX}/sbin \
		--program-transform-name="" \
		--disable-silent-rules

MAN8=		tinyproxy.8
MAN5=		tinyproxy.conf.5

OPTIONS=	REVERSE "Enable reverse proxy support" Off \
		TRANSPARENT "Enable transparent proxy support" Off

.include <bsd.port.pre.mk>

.if defined(WITH_REVERSE)
CONFIGURE_ARGS+=	--enable-reverse
.endif

.if defined(WITH_TRANSPARENT)
CONFIGURE_ARGS+=	--enable-transparent
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/etc/tinyproxy/tinyproxy.conf|${PREFIX}/etc/tinyproxy.conf|' \
	  ${WRKSRC}/docs/man8/tinyproxy.txt.in
	@${REINPLACE_CMD} -e 's|/var/run/tinyproxy/tinyproxy.pid|/var/run/tinyproxy.pid|' \
	  ${WRKSRC}/docs/man8/tinyproxy.txt.in
	@${REINPLACE_CMD} -e 's|/var/log/tinyproxy/tinyproxy.log|/var/log/tinyproxy.log|' \
	  ${WRKSRC}/docs/man8/tinyproxy.txt.in
	@${REINPLACE_CMD} -e 's|/etc/tinyproxy/tinyproxy.conf|${PREFIX}/etc/tinyproxy.conf|' \
	  ${WRKSRC}/docs/man5/tinyproxy.conf.txt.in
	@${REINPLACE_CMD} -e 's|/usr/share/tinyproxy|${DATADIR}|' \
	  ${WRKSRC}/etc/tinyproxy.conf.in
	@${REINPLACE_CMD} -e 's|/run/tinyproxy/|/run/|' \
	  ${WRKSRC}/etc/tinyproxy.conf.in
	@${REINPLACE_CMD} -e 's|/log/tinyproxy/|/log/|' \
	  ${WRKSRC}/etc/tinyproxy.conf.in

post-install:
	@if [ ! -f ${PREFIX}/etc/tinyproxy.conf ]; then \
		${CP} -p ${PREFIX}/etc/tinyproxy.conf.sample \
		${PREFIX}/etc/tinyproxy.conf ; \
	fi

.include <bsd.port.post.mk>
