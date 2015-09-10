# Created by: Adrian Steinmann <ast@marabu.ch>
# $FreeBSD$

PORTNAME=	nostromo
PORTVERSION=	1.9.5
PORTREVISION=	4
CATEGORIES=	www ipv6
MASTER_SITES=	http://www.nazgul.ch/dev/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast, secure HTTP/1.1 CGI/1.1 SSL IPv4/IPv6 webserver

LICENSE=	ISCL

NOSTROMO_DIR?=		nostromo
NOSTROMO_LOGDIR?=	${NOSTROMO_DIR}/logs
NOSTROMO_LOGDIR_PERMS?=	0775

USE_OPENSSL=	yes
USE_RC_SUBR=	nostromo

USES=		shebangfix
SHEBANG_FILES=	htdocs/cgi-bin/printenv

MAKE_ENV?=	MAKEOBJDIR=. PREFIX=${PREFIX} NOSTROMO_DIR=${NOSTROMO_DIR}
PLIST_SUB+=	NOSTROMODIR="${NOSTROMO_DIR}" NOSTROMOLOGDIR="${NOSTROMO_LOGDIR}"

post-extract:
	@${REINPLACE_CMD} -e "s@/var/nostromo@${NOSTROMO_DIR}@g" \
		${WRKSRC}/src/nhttpd/nhttpd.8
	@${REINPLACE_CMD} -e "s@/var/nostromo@${NOSTROMO_DIR}@g" \
		${WRKSRC}/src/nhttpd/main.c
	@${REINPLACE_CMD} -e "s@/var/nostromo@${NOSTROMO_DIR}@g" \
		${WRKSRC}/conf/nhttpd.conf-dist

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/nhttpd/nhttpd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/src/tools/crypt ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/src/nhttpd/nhttpd.8 ${STAGEDIR}${PREFIX}/man/man8
	@${MKDIR} ${STAGEDIR}${PREFIX}/${NOSTROMO_DIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/${NOSTROMO_DIR}/conf
	@${MKDIR} -m ${NOSTROMO_LOGDIR_PERMS} -p ${STAGEDIR}${PREFIX}/${NOSTROMO_LOGDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/mimes ${STAGEDIR}${PREFIX}/${NOSTROMO_DIR}/conf
	${INSTALL_DATA} ${WRKSRC}/conf/nhttpd.conf-dist ${STAGEDIR}${PREFIX}/${NOSTROMO_DIR}/conf/nhttpd.conf.sample
	@${MKDIR} ${STAGEDIR}${PREFIX}/${NOSTROMO_DIR}/htdocs
	${INSTALL_DATA} ${WRKSRC}/htdocs/index.html ${STAGEDIR}${PREFIX}/${NOSTROMO_DIR}/htdocs
	${INSTALL_DATA} ${WRKSRC}/htdocs/nostromo.gif ${STAGEDIR}${PREFIX}/${NOSTROMO_DIR}/htdocs
	@${MKDIR} ${STAGEDIR}${PREFIX}/${NOSTROMO_DIR}/htdocs/cgi-bin
	${INSTALL_SCRIPT} ${WRKSRC}/htdocs/cgi-bin/printenv \
		${STAGEDIR}${PREFIX}/${NOSTROMO_DIR}/htdocs/cgi-bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/${NOSTROMO_DIR}/icons
	${INSTALL_DATA} ${WRKSRC}/icons/dir.gif ${STAGEDIR}${PREFIX}/${NOSTROMO_DIR}/icons
	${INSTALL_DATA} ${WRKSRC}/icons/file.gif ${STAGEDIR}${PREFIX}/${NOSTROMO_DIR}/icons

.include <bsd.port.mk>
