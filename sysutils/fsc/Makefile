PORTNAME=	fsc
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	samm@FreeBSD.org
COMMENT=	FreeBSD Services Control family of utilities
WWW=		https://github.com/bsdtrhodes/freebsd-fscd/

LICENSE=	BSD2CLAUSE

PLIST_FILES=	bin/fscadm sbin/fscd etc/rc.d/fscd share/man/man5/fscd.conf.5.gz \
		share/man/man8/fscadm.8.gz share/man/man8/fscd.8.gz

USE_GITHUB=	yes
GH_ACCOUNT=	bsdtrhodes
GH_PROJECT=	freebsd-fscd
GH_TAGNAME=	ef16626

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=unused-but-set-variable
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|' \
		${WRKSRC}/fscd/fscd.8 ${WRKSRC}/fscd/fscd.c \
		${WRKSRC}/fscd/fscd.conf.5 ${WRKSRC}/fscadm/fscadm.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fscadm/fscadm ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/fscd/fscd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/rc.d/fscd ${STAGEDIR}${PREFIX}/etc/rc.d
	${INSTALL_DATA} ${WRKSRC}/fscd/fscd.conf.5.gz \
		${STAGEDIR}${PREFIX}/share/man/man5
	${INSTALL_DATA} ${WRKSRC}/fscd/fscd.8.gz \
		${STAGEDIR}${PREFIX}/share/man/man8
	${INSTALL_DATA} ${WRKSRC}/fscadm/fscadm.8.gz \
		${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>
