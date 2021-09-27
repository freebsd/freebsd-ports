# Created by: TAKANO Yuji <takano@net-chef.net>

PORTNAME=	irrd
PORTVERSION=	2.3.10
DISTVERSIONPREFIX=	v
CATEGORIES=	net
PKGNAMESUFFIX=	-legacy

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Internet Routing Registry database server

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKDIR}/${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}/COPYRIGHT

DEPRECATED=	Use net/irrd
EXPIRATION_DATE=2021-10-27
BROKEN_FreeBSD_13=	ld: error: duplicate symbol: error_buf
BROKEN_FreeBSD_14=	ld: error: duplicate symbol: error_buf

RUN_DEPENDS=	wget:ftp/wget

USES=		shebangfix
USE_GITHUB=	yes
USE_RC_SUBR=	irrd

GH_ACCOUNT=	irrdnet
GH_PROJECT=	${PORTNAME}${PKGNAMESUFFIX}

WRKSRC_SUBDIR=	src

IRRD_CONFDIR=	${PREFIX}/etc

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	YACC="${YACC}"
MAKE_JOBS_UNSAFE=	yes
DESTDIRNAME=	STAGEDIR

OPTIONS_DEFINE=		IPV6
IPV6_CONFIGURE_ENABLE=	ipv6

SHEBANG_FILES=	programs/irrdcacher/irrdcacher \
		programs/irrdcacher/ripe2rpsl

PLIST_FILES=	etc/irrd.conf.sample \
		man/man8/irrd.8.gz \
		sbin/irr_notify \
		sbin/irr_rpsl_check \
		sbin/irr_rpsl_submit \
		sbin/irrd \
		sbin/irrdcacher \
		sbin/ripe2rpsl

post-patch:
	${REINPLACE_CMD} -e 's|/etc/irrd.conf|${IRRD_CONFDIR}/irrd.conf|g' \
		${WRKSRC}/programs/IRRd/irrd.8 \
		${WRKSRC}/programs/IRRd/main.c \
		${WRKSRC}/programs/hdr_comm/read_conf.c \
		${WRKSRC}/programs/irr_notify/main.c \
		${WRKSRC}/programs/irr_rpsl_check/main.c \
		${WRKSRC}/programs/irr_rpsl_submit/main.c \
		${WRKSRC}/programs/irrdcacher/irrdcacher \
		${WRKSRC}/programs/rps_dist/rpsdist.c
	${REINPLACE_CMD} -e 's|\($$(DESTDIR)\)|$$(STAGEDIR)\1|g' \
		-e 's|\( -m 755 \)| -s\1|g' \
		-e 's| -o root -g bin||g' \
		${WRKSRC}/programs/IRRd/Makefile \
		${WRKSRC}/programs/irr_notify/Makefile \
		${WRKSRC}/programs/irr_rpsl_check/Makefile \
		${WRKSRC}/programs/irr_rpsl_submit/Makefile

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/programs/irrdcacher/irrdcacher \
		${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/programs/irrdcacher/ripe2rpsl \
		${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/../samples/irrd.conf.sample \
		${STAGEDIR}${IRRD_CONFDIR}
	${INSTALL_DATA} ${WRKSRC}/programs/IRRd/irrd.8 \
		${STAGEDIR}${PREFIX}/man/man8

.include <bsd.port.mk>
