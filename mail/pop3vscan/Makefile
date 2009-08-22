# New ports collection makefile for:	pop3vscan
# Date created:				01 June 2003
# Whom:	      				Yen-Ming Lee <leeym@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pop3vscan
PORTVERSION=	0.4
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	A transparent POP3-Proxy with virus-scanning capabilities

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre

USE_GMAKE=	yes
MAKE_ENV=	_LDFLAGS="${LDFLAGS}"
SCRIPTS_ENV=	PKG_PREFIX=${PREFIX} NONEXISTENT=${NONEXISTENT} PASSWD=/etc/passwd

post-extract:
	@${RM} ${WRKSRC}/ripmime/ripmime.a

post-patch:
	@${REINPLACE_CMD} -e 's,malloc.h,stdlib.h,g' ${WRKSRC}/*.c
	@${REINPLACE_CMD} -e 's,#endif.*,#endif,g' ${WRKSRC}/*.h
	@${REINPLACE_CMD} -e 's,make,${GMAKE},g' ${WRKSRC}/ripmime/build_tnef
	@${REINPLACE_CMD} -e 's,=4321,=_BYTE_ORDER -include /usr/include/machine/endian.h,g' \
		${WRKSRC}/ripmime/tnef/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pop3vscan ${PREFIX}/sbin/
	${INSTALL_DATA} ${WRKSRC}/pop3vscan.conf ${PREFIX}/etc/pop3vscan.conf.sample
	${INSTALL_DATA} ${WRKSRC}/pop3vscan.mail ${PREFIX}/etc/pop3vscan.mail.sample
	${INSTALL_SCRIPT} ${FILESDIR}/pop3vscan.sh ${PREFIX}/etc/rc.d/

post-install:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${SED} -e 's,PREFIX,${PREFIX},g' ${PKGMESSAGE}

.include <bsd.port.mk>
