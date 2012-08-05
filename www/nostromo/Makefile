# New ports collection makefile for:	nostromo
# Date created:		20 Mar 2011
# Whom:			Adrian Steinmann <ast@marabu.ch>
#
# $FreeBSD$
#

PORTNAME=	nostromo
PORTVERSION=	1.9.5
CATEGORIES=	www ipv6
MASTER_SITES=	http://www.nazgul.ch/dev/

MAINTAINER=	ast@marabu.ch
COMMENT=	A fast, secure HTTP/1.1 CGI/1.1 SSL IPv4/IPv6 webserver

LICENSE=	BSD

NOSTROMO_DIR?=		${PREFIX}/nostromo
NOSTROMO_LOGDIR?=	${NOSTROMO_DIR}/logs
NOSTROMO_LOGDIR_PERMS?=	0775

USE_RC_SUBR=	nostromo

MAN8=		nhttpd.8

MAKE_ENV?=	MAKEOBJDIR=. PREFIX=${PREFIX} NOSTROMO_DIR=${NOSTROMO_DIR}

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
	@${MKDIR} ${NOSTROMO_DIR}
	@${MKDIR} ${NOSTROMO_DIR}/conf
	@${MKDIR} -m ${NOSTROMO_LOGDIR_PERMS} -p ${NOSTROMO_LOGDIR}
	@${INSTALL_DATA} ${WRKSRC}/conf/mimes ${NOSTROMO_DIR}/conf
	@${INSTALL_DATA} ${WRKSRC}/conf/nhttpd.conf-dist ${NOSTROMO_DIR}/conf
	@${MKDIR} ${NOSTROMO_DIR}/htdocs
	@${INSTALL_DATA} ${WRKSRC}/htdocs/index.html ${NOSTROMO_DIR}/htdocs
	@${INSTALL_DATA} ${WRKSRC}/htdocs/nostromo.gif ${NOSTROMO_DIR}/htdocs
	@${MKDIR} ${NOSTROMO_DIR}/htdocs/cgi-bin
	@${INSTALL_SCRIPT} ${WRKSRC}/htdocs/cgi-bin/printenv \
		${NOSTROMO_DIR}/htdocs/cgi-bin
	@${MKDIR} ${NOSTROMO_DIR}/icons
	@${INSTALL_DATA} ${WRKSRC}/icons/dir.gif ${NOSTROMO_DIR}/icons
	@${INSTALL_DATA} ${WRKSRC}/icons/file.gif ${NOSTROMO_DIR}/icons

.include <bsd.port.mk>
