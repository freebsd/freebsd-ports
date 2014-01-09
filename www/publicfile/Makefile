# Created by: Neil Blakey-Milner
# $FreeBSD$

PORTNAME=	publicfile
PORTVERSION=	0.52
PORTREVISION=	2
CATEGORIES=	www ftp
MASTER_SITES=	http://cr.yp.to/publicfile/

MAINTAINER=	lx@FreeBSD.org
COMMENT=	A secure, read-only, anonymous HTTP/FTP server

RUN_DEPENDS=	setuidgid:${PORTSDIR}/sysutils/daemontools \
		tcpserver:${PORTSDIR}/sysutils/ucspi-tcp

OPTIONS_DEFINE=	BASICAUTH COMMONLOG REDIRECT_SLASH ENV_FILETYPES SSL
BASICAUTH_DESC=		basic HTTP authentication support
COMMONLOG_DESC=		support for Apache common log format
REDIRECT_SLASH_DESC=	do not require trailing slash on directories
ENV_FILETYPES_DESC=	get mime types from the environment
SSL_DESC=		provide SSL support through ucspi-ssl

CONFLICTS=	xshttpd-3*
LEGAL_TEXT=	No license -- see http://cr.yp.to/softwarelaw.html

NO_STAGE=	yes
.include <bsd.port.options.mk>

pre-everything::
.if ${PORT_OPTIONS:MBASICAUTH} && ${PORT_OPTIONS:MCOMMONLOG}
	@${ECHO_MSG}
	@${ECHO_MSG} "Currently the common log and auth patches conflict."
	@${ECHO_MSG}
BROKEN=	Currently the common log and auth patches conflict.
.endif

.if ${PORT_OPTIONS:MBASICAUTH} && ${PORT_OPTIONS:MREDIRECT_SLASH}
	@${ECHO_MSG}
	@${ECHO_MSG} "Currently the redirect slash and auth patches conflict."
	@${ECHO_MSG}
BROKEN=	Currently the redirect slash and auth patches conflict.
.endif

.if ${PORT_OPTIONS:MREDIRECT_SLASH}
pre-configure::
	@${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/redirect-slash-patch
.endif

.if ${PORT_OPTIONS:MENV_FILETYPES}
pre-configure::
	@${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/publicfile-0.52-filetype-diff
.endif

.if ${PORT_OPTIONS:MSSL}
pre-configure::
	@${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/publicfile.sslserver
RUN_DEPENDS+=	sslserver:${PORTSDIR}/sysutils/ucspi-ssl
.endif

.if ${PORT_OPTIONS:MBASICAUTH}
pre-configure::
	@${SED} -e "s:__PORTSDIR__:${PORTSDIR}:g" \
		-e "s:__WRKSRC__:${WRKSRC}:g" \
		${PATCHDIR}/publicfile-0.52_basicauth.patch.in > \
		${PATCHDIR}/publicfile-0.52_basicauth.patch
	@${PATCH} ${PATCH_ARGS} -p1 < \
		${PATCHDIR}/publicfile-0.52_basicauth.patch
BUILD_DEPENDS+=	${NONEXISTENT}:${PORTSDIR}/databases/cdb:extract
PLIST_SUB+=	BASICAUTH=""
.else
PLIST_SUB+=	BASICAUTH="@comment "
.endif

.if ${PORT_OPTIONS:MCOMMONLOG}
pre-configure::
	@${PATCH} ${PATCH_ARGS} -p1 < \
		${PATCHDIR}/publicfile-0.52-commonlog-2.patch
.endif

ALL_TARGET=	it
INSTALL_TARGET=	setup check

post-extract:
.if ${PORT_OPTIONS:MBASICAUTH}
	@${LN} -s ${PORTSDIR}/databases/cdb/work/cdb-0.75 ${WRKSRC}/cdb-0.75
.endif

post-patch:
	@${ECHO_CMD} "${CC} ${CFLAGS}" > ${WRKSRC}/conf-cc
	@${ECHO_CMD} "${CC} -s" > ${WRKSRC}/conf-ld
	@${ECHO_CMD} "${PREFIX}" > ${WRKSRC}/conf-home

.include <bsd.port.mk>
