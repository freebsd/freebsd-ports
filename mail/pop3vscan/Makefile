# Created by: Yen-Ming Lee <leeym@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pop3vscan
PORTVERSION=	0.4
PORTREVISION=	5
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	Transparent POP3-Proxy with virus-scanning capabilities

LIB_DEPENDS=	libpcre.so:devel/pcre

USES=		gmake
USE_GCC=	yes
MAKE_ENV=	_LDFLAGS="${LDFLAGS}"

USERS=		pop3vscan

PLIST_FILES=	etc/pop3vscan.conf.sample \
		etc/pop3vscan.mail.sample \
		etc/rc.d/pop3vscan.sh \
		sbin/pop3vscan

SUB_FILES=	pkg-message

post-extract:
	@${RM} ${WRKSRC}/ripmime/ripmime.a

post-patch:
	@${REINPLACE_CMD} -e "/CC/s,gcc,${CC},g" ${WRKSRC}/Makefile ${WRKSRC}/ripmime/Makefile ${WRKSRC}/ripmime/tnef/Makefile
	@${REINPLACE_CMD} -e 's,malloc.h,stdlib.h,g' ${WRKSRC}/*.c
	@${REINPLACE_CMD} -e 's,#endif.*,#endif,g' ${WRKSRC}/*.h
	@${REINPLACE_CMD} -e 's,make,${MAKE_CMD},g' ${WRKSRC}/ripmime/build_tnef
	@${REINPLACE_CMD} -e 's,=4321,=_BYTE_ORDER -include /usr/include/machine/endian.h,g' \
		${WRKSRC}/ripmime/tnef/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pop3vscan ${STAGEDIR}${PREFIX}/sbin/
	${INSTALL_DATA} ${WRKSRC}/pop3vscan.conf ${STAGEDIR}${PREFIX}/etc/pop3vscan.conf.sample
	${INSTALL_DATA} ${WRKSRC}/pop3vscan.mail ${STAGEDIR}${PREFIX}/etc/pop3vscan.mail.sample
	${INSTALL_SCRIPT} ${FILESDIR}/pop3vscan.sh ${STAGEDIR}${PREFIX}/etc/rc.d/

.include <bsd.port.mk>
