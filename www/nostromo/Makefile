# Created by: Adrian Steinmann <ast@marabu.ch>
# $FreeBSD$

PORTNAME=	nostromo
PORTVERSION=	1.9.5
PORTREVISION=	1
CATEGORIES=	www ipv6
MASTER_SITES=	http://www.nazgul.ch/dev/

MAINTAINER=	ast@marabu.ch
COMMENT=	A fast, secure HTTP/1.1 CGI/1.1 SSL IPv4/IPv6 webserver

LICENSE=	BSD

NOSTROMO_DIR?=		nostromo
NOSTROMO_LOGDIR?=	${NOSTROMO_DIR}/logs
NOSTROMO_LOGDIR_PERMS?=	0775

USE_RC_SUBR=	nostromo

MAN8=		nhttpd.8

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
	@${INSTALL_SCRIPT} ${WRKSRC}/src/nhttpd/nhttpd ${PREFIX}/sbin
	@${INSTALL_SCRIPT} ${WRKSRC}/src/tools/crypt ${PREFIX}/sbin
	@${INSTALL_MAN} ${WRKSRC}/src/nhttpd/nhttpd.8 ${PREFIX}/man/man8
	@${MKDIR} ${PREFIX}/${NOSTROMO_DIR}
	@${MKDIR} ${PREFIX}/${NOSTROMO_DIR}/conf
	@${MKDIR} -m ${NOSTROMO_LOGDIR_PERMS} -p ${PREFIX}/${NOSTROMO_LOGDIR}
	@${INSTALL_DATA} ${WRKSRC}/conf/mimes ${PREFIX}/${NOSTROMO_DIR}/conf
	@${INSTALL_DATA} ${WRKSRC}/conf/nhttpd.conf-dist ${PREFIX}/${NOSTROMO_DIR}/conf
	if [ ! -f ${PREFIX}/${NOSTROMO_DIR}/conf/nhttpd.conf ]; then \
		${CP} -p ${PREFIX}/${NOSTROMO_DIR}/conf/nhttpd.conf-dist ${PREFIX}/${NOSTROMO_DIR}/conf/nhttpd.conf ; \
	fi
	@${MKDIR} ${PREFIX}/${NOSTROMO_DIR}/htdocs
	@${INSTALL_DATA} ${WRKSRC}/htdocs/index.html ${PREFIX}/${NOSTROMO_DIR}/htdocs
	@${INSTALL_DATA} ${WRKSRC}/htdocs/nostromo.gif ${PREFIX}/${NOSTROMO_DIR}/htdocs
	@${MKDIR} ${PREFIX}/${NOSTROMO_DIR}/htdocs/cgi-bin
	@${INSTALL_SCRIPT} ${WRKSRC}/htdocs/cgi-bin/printenv \
		${PREFIX}/${NOSTROMO_DIR}/htdocs/cgi-bin
	@${MKDIR} ${PREFIX}/${NOSTROMO_DIR}/icons
	@${INSTALL_DATA} ${WRKSRC}/icons/dir.gif ${PREFIX}/${NOSTROMO_DIR}/icons
	@${INSTALL_DATA} ${WRKSRC}/icons/file.gif ${PREFIX}/${NOSTROMO_DIR}/icons

.include <bsd.port.mk>
