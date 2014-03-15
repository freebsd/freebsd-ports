# Created by: Mitsuru Yoshida <mitsuru@riken.go.jp>
# $FreeBSD$

PORTNAME=	tinyproxy
PORTVERSION=	1.8.3
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	https://banu.com/pub/tinyproxy/1.8/

MAINTAINER=	marquis@roble.com
COMMENT=	A small, efficient HTTP proxy server

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

#BUILD_DEPENDS=	asciidoc:${PORTSDIR}/textproc/asciidoc\
#		xsltproc:${PORTSDIR}/textproc/libxslt\
#		xmllint:${PORTSDIR}/textproc/libxml2 \
#		${LOCALBASE}/share/xsl/docbook/lib/lib.xsl:${PORTSDIR}/textproc/docbook-xsl

USE_RC_SUBR=	tinyproxy
GNU_CONFIGURE=	yes
USES=		gmake
CONFIGURE_ARGS=	--bindir=${PREFIX}/sbin \
		--program-transform-name="" \
		--disable-silent-rules \
		--localstatedir=/var

MAN8=		tinyproxy.8
MAN5=		tinyproxy.conf.5

OPTIONS_DEFINE=	XHEADER REVERSE TRANSPARENT
XHEADER_DESC=		X-Tinyproxy header
REVERSE_DESC=		Reverse proxy support
TRANSPARENT_DESC=	Transparent proxy support

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MREVERSE}
CONFIGURE_ARGS+=	--enable-reverse
.endif

.if ${PORT_OPTIONS:MTRANSPARENT}
CONFIGURE_ARGS+=	--enable-transparent
.endif

.if !${PORT_OPTIONS:MXHEADER}
CONFIGURE_ARGS+=	--disable-xtinyproxy
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
.if !defined(NO_INSTALL_MANPAGES)
	${INSTALL_MAN} ${FILESDIR}/${MAN5} ${MAN1PREFIX}/man/man5
	${INSTALL_MAN} ${FILESDIR}/${MAN8} ${MAN1PREFIX}/man/man8
.endif

.include <bsd.port.mk>
