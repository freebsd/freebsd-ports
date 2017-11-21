# Created by: Rozhuk Ivan <rozhuk.im@gmail.com>
# $FreeBSD$

PORTNAME=		mprime
PORTVERSION=		28.10
CATEGORIES=		math benchmarks net
MASTER_SITES=		http://www.mersenne.org/ftp_root/gimps/ \
			ftp://mersenne.org/gimps/
DISTNAME=		p95v${PORTVERSION:R}${PORTVERSION:E}.source

MAINTAINER=		rozhuk.im@gmail.com
COMMENT=		Great Internet Mersenne Prime Search

LICENSE=		EULA
LICENSE_NAME=		EULA
LICENSE_FILE=		${FILESDIR}/LICENSE
LICENSE_PERMS=		dist-mirror pkg-mirror auto-accept

ONLY_FOR_ARCHS=		amd64 i386

LIB_DEPENDS=		libcurl.so:ftp/curl

USES=			zip
USE_LDCONFIG=		yes
NO_WRKSUBDIR=		yes
WRKSRC=			${WRKDIR}/${PORTNAME}-${PORTVERSION}
ALL_TARGET=		mprime

SUB_FILES=		wrapper.sh

PLIST_FILES+=\
			bin/mprime \
			bin/mprime-real

post-patch:
	@${REINPLACE_CMD} -e 's| abs (| labs (|g ; \
			s|(abs (|(labs (|g ; \
			s| abs(| labs(|g ; \
			s|(abs(|(labs(|g' \
				${WRKSRC}/../gwnum/gwnum.c \
				${WRKSRC}/../commonc.c \
				${WRKSRC}/../ecm.c \
				${WRKSRC}/../gwtest.c
	@${REINPLACE_CMD} -e 's|__APPLE__|__FreeBSD__|g' \
				${WRKSRC}/../gwnum/gwutil.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mprime ${STAGEDIR}${PREFIX}/bin/mprime-real
	${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh ${STAGEDIR}${PREFIX}/bin/mprime

.include <bsd.port.mk>
