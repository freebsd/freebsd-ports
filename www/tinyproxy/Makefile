# Created by: Mitsuru Yoshida <mitsuru@riken.go.jp>

PORTNAME=	tinyproxy
PORTVERSION=	1.11.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	https://github.com/tinyproxy/tinyproxy/releases/download/${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Small, efficient HTTP proxy server

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake tar:xz

CONFIGURE_ARGS=	--bindir=${PREFIX}/sbin \
		--disable-manpage_support \
		--program-transform-name=""
GNU_CONFIGURE=	yes
USE_RC_SUBR=	tinyproxy

OPTIONS_DEFINE=	FILTER REVERSE UPSTREAM TRANSPARENT XHEADER
OPTIONS_DEFAULT=FILTER REVERSE UPSTREAM TRANSPARENT XHEADER
FILTER_DESC=		Filter support
REVERSE_DESC=		Reverse proxy support
UPSTREAM_DESC=		Upstream proxying support
TRANSPARENT_DESC=	Transparent proxy support
XHEADER_DESC=		X-Tinyproxy header

FILTER_CONFIGURE_ENABLE=	filter
REVERSE_CONFIGURE_ENABLE=	reverse
UPSTREAM_CONFIGURE_ENABLE=	upstream
TRANSPARENT_CONFIGURE_ENABLE=	transparent
XHEADER_CONFIGURE_ENABLE=	xtinyproxy

post-patch:
	@${REINPLACE_CMD} -e 's|tinyproxy/tinyproxy|tinyproxy|g; s|/etc/tinyproxy|${PREFIX}&|' \
		${WRKSRC}/docs/man5/tinyproxy.conf.5 \
		${WRKSRC}/docs/man8/tinyproxy.8 \
		${WRKSRC}/etc/tinyproxy.conf.in
	@${REINPLACE_CMD} -e '/\/usr\/share\/tinyproxy/d; s|^#\(LogFile \)|\1|; s|^#\(PidFile \)|\1|' ${WRKSRC}/etc/tinyproxy.conf.in

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/tinyproxy.conf ${STAGEDIR}${PREFIX}/etc/tinyproxy.conf.sample
	${INSTALL_MAN} ${WRKSRC}/docs/man5/tinyproxy.conf.5 ${STAGEDIR}${PREFIX}/share/man/man5/
	${INSTALL_MAN} ${WRKSRC}/docs/man8/tinyproxy.8 ${STAGEDIR}${PREFIX}/share/man/man8/

.include <bsd.port.mk>
