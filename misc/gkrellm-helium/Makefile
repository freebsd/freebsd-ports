# New ports collection makefile for:	gkrellm-helium
# Date Created:		19 Apr 2003
# Whom:			Pav Lucistnik <pav@oook.cz>
#
# $FreeBSD$
#

PORTNAME=	gkrellm-helium
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://kmlinux.fjfi.cvut.cz/~makovick/gkrellm/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pav@FreeBSD.org
COMMENT=	GKrellM plugin reading data from helium thermometer at Strahov, Prague

BUILD_DEPENDS=	${X11BASE}/include/gkrellm2/gkrellm.h:${PORTSDIR}/sysutils/gkrellm2
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm2

PLIST_FILES=	libexec/gkrellm2/plugins/helium.so
USE_X_PREFIX=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		s|/usr/local/lib/gkrellm2/plugins|${PREFIX}/libexec/gkrellm2/plugins| ; \
		s|gcc -c|gcc -c -fPIC|g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|ulong|u_long|' ${WRKSRC}/*.c

.include <bsd.port.mk>
