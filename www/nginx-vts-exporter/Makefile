PORTNAME=			nginx-vts-exporter
DISTVERSIONPREFIX=	v
DISTVERSION=		0.10.7
PORTREVISION=	28
CATEGORIES=			www

MAINTAINER=			joneum@FreeBSD.org
COMMENT=			Server that scraps NGINX vts stats and export them via HTTP
WWW=		https://github.com/hnlq715/nginx-vts-exporter

LICENSE=			MIT
LICENSE_FILE=		${WRKSRC}/LICENSE

USES=				gmake go
USE_RC_SUBR=		nginx_vts_exporter
USE_GITHUB=			yes
GH_ACCOUNT=			hnlq715

GO_BUILDFLAGS=		-v -ldflags "${LD_FLAG_STRING}"

SUB_FILES=			newsyslog.conf nginx_vts_exporter syslog.d.conf

SUB_LIST=			NGINX_VTS_EXPORTER_LOG_FILE=/var/log/nginx_vts_exporter \
					NGINX_VTS_EXPORTER_LOG_TAG=nginx_vts_exporter

BUILD_USER?=		${USER}
LD_FLAG_X_PREFIX=	-X ${GO_PKGNAME}/vendor/github.com/prometheus/common/version
LD_FLAG_STRING=		-s \
					${LD_FLAG_X_PREFIX}.Branch=release-${PORTVERSION:R} \
					${LD_FLAG_X_PREFIX}.BuildUser=${BUILD_USER} \
					${LD_FLAG_X_PREFIX}.Revision=${PORTREVISION} \
					${LD_FLAG_X_PREFIX}.Version=${PORTVERSION}

PLIST_FILES=	bin/nginx_vts_exporter \
			etc/newsyslog.conf.d/nginx-vts-exporter.conf \
			etc/syslog.d/nginx-vts-exporter.conf

do-install:
	${INSTALL_PROGRAM} \
		${GO_WRKDIR_BIN}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/nginx_vts_exporter

	${MKDIR} ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/syslog.d

	${INSTALL_DATA} \
		${WRKDIR}/newsyslog.conf \
		${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d/${PORTNAME}.conf

	${INSTALL_DATA} \
		${WRKDIR}/syslog.d.conf \
		${STAGEDIR}${PREFIX}/etc/syslog.d/${PORTNAME}.conf

.include <bsd.port.mk>
