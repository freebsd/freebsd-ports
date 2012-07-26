# New ports collection makefile for:	httpsqs
# Date created:		2011-04-22
# Whom:			Zhihao Yuan <lichray@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	httpsqs
PORTVERSION=	1.7
CATEGORIES=	www devel
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	lichray@gmail.com
COMMENT=	Simple Queue Service based on HTTP GET/POST protocol

LICENSE=	BSD

LIB_DEPENDS+=	tokyocabinet:${PORTSDIR}/databases/tokyocabinet \
	event-2.0:${PORTSDIR}/devel/libevent2

USE_PKGCONFIG=	yes
MAKE_ENV=	LIBS="${PTHREAD_LIBS}"

PLIST_FILES=	bin/${PORTNAME}

post-patch:
	${CP} ${PATCHDIR}/Makefile ${WRKSRC}
	@${REINPLACE_CMD} -e 's|{ 0 }|"${PREFIX}/bin/${PORTNAME}"|' \
		${WRKSRC}/httpsqs.c

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
