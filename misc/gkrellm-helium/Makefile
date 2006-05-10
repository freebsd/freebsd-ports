# New ports collection makefile for:	gkrellm-helium
# Date Created:		19 Apr 2003
# Whom:			Pav Lucistnik <pav@oook.cz>
#
# $FreeBSD$
#

PORTNAME=	gkrellm-helium
PORTVERSION=	2.3.1
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://kmlinux.fjfi.cvut.cz/~makovick/gkrellm/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pav@FreeBSD.org
COMMENT=	GKrellM plugin reading data from helium thermometer at Strahov, Prague

BUILD_DEPENDS=	${X11BASE}/include/gkrellm2/gkrellm.h:${PORTSDIR}/sysutils/gkrellm2
LIB_DEPENDS=	curl.3:${PORTSDIR}/ftp/curl
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm2

PLIST_FILES=	libexec/gkrellm2/plugins/helium.so
USE_X_PREFIX=	yes

CFLAGS+=	-fPIC -I${LOCALBASE}/include
MAKE_ARGS=	CFLAGS="${CFLAGS}"

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/lib/gkrellm2/plugins|${PREFIX}/libexec/gkrellm2/plugins| ; \
		s|CFLAGS =|CFLAGS?=| ; s|-lcurl|-lcurl -L${LOCALBASE}/lib|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|ulong|u_long|' ${WRKSRC}/*.c

.include <bsd.port.mk>
