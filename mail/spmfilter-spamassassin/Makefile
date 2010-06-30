# New ports collection makefile for:	spmfilter-spamassassin
# Date created:				2010-04-29
# Whom:					Axel Steiner <ast@treibsand.com>
#
# $FreeBSD$
#

PORTNAME=	spmfilter-spamassassin
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.spmfilter.org/attachments/download/58/

MAINTAINER=	ast@treibsand.com
COMMENT=	Spamassassin plugin for spmfilter

BUILD_DEPENDS=	spmfilter>=0.4:${PORTSDIR}/mail/spmfilter
RUN_DEPENDS=	spmfilter>=0.4:${PORTSDIR}/mail/spmfilter

USE_CMAKE=	yes
CMAKE_ARGS+=	-DCMAKE_INCLUDE_PATH="${LOCALBASE}/include" \
		-DCMAKE_LIBRARY_PATH="${LOCALBASE}/lib"

USE_LDCONFIG=	${PREFIX}/lib/spmfilter

OPTIONS=	DEBUG	"Enable Debugging"	off

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
CMAKE_USE_PTHREAD=	yes
.endif

.if defined(WITH_DEBUG)
CMAKE_ARGS+=	-DENABLE_DEBUG=TRUE
.endif

MAN1=		${PORTNAME}.1 \
		smf-spamq.1 \
		smf-spamctl.1

MANCOMPRESSED=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|share/man|man|' \
		${WRKSRC}/cmake/Modules/SMFMacros.cmake

.include <bsd.port.post.mk>
