# New ports collection makefile for: publicfile
# Date created:		24 Jan 2000
# Whom:			Neil Blakey-Milner
#
# $FreeBSD$
#

PORTNAME=	publicfile
PORTVERSION=	0.52
PORTREVISION=	2
CATEGORIES=	www ftp
MASTER_SITES=	http://cr.yp.to/publicfile/ \
		ftp://cr.yp.to/publicfile/

MAINTAINER=	lx@redundancy.redundancy.org
COMMENT=	A secure, read-only, anonymous HTTP/FTP server

RUN_DEPENDS=	setuidgid:${PORTSDIR}/sysutils/daemontools \
		tcpserver:${PORTSDIR}/sysutils/ucspi-tcp

OPTIONS=	BASICAUTH "basic HTTP authentication support" off \
		COMMONLOG "support for Apache common log format" on \
		REDIRECT_SLASH "don't complain when omitting trailing slash" off \
		SSL "provide SSL support through ucspi-ssl" on

.include <bsd.port.pre.mk>

pre-everything::
.if defined(WITH_BASICAUTH) && defined(WITH_COMMONLOG)
	@${ECHO_MSG}
	@${ECHO_MSG} "Currently the common log and auth patches conflict."
	@${ECHO_MSG}
BROKEN=	"Currently the common log and auth patches conflict."
.endif

.if defined(WITH_BASICAUTH) && defined(WITH_REDIRECT_SLASH)
	@${ECHO_MSG}
	@${ECHO_MSG} "Currently the redirect slash and auth patches conflict."
	@${ECHO_MSG}
BROKEN=	"Currently the redirect slash and auth patches conflict."
.endif

.if defined(WITH_REDIRECT_SLASH)
pre-configure::
	@${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/redirect-slash-patch
.endif

.if defined(WITH_ENV_FILETYPES)
pre-configure::
	@${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/publicfile-0.52-filetype-diff
.endif

.if defined(WITH_SSL)
pre-configure::
	@${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/publicfile.sslserver
RUN_DEPENDS+=	sslserver:${PORTSDIR}/sysutils/ucspi-ssl
.endif

.if defined(WITH_BASICAUTH)
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

.if defined(WITH_COMMONLOG)
pre-configure::
	@${PATCH} ${PATCH_ARGS} -p1 < \
		${PATCHDIR}/publicfile-0.52-commonlog-2.patch
.endif

ALL_TARGET=	it
INSTALL_TARGET=	setup check

post-extract:
.if defined(WITH_BASICAUTH)
	@${LN} -s ${PORTSDIR}/databases/cdb/work/cdb-0.75 ${WRKSRC}/cdb-0.75
.endif

post-patch:
	@${ECHO_CMD} "${CC} ${CFLAGS}" > ${WRKSRC}/conf-cc
	@${ECHO_CMD} "${CC} -s" > ${WRKSRC}/conf-ld
	@${ECHO_CMD} "${PREFIX}" > ${WRKSRC}/conf-home

.include <bsd.port.post.mk>
