# New ports collection makefile for:	popa3d
# Version required:	0.4
# Date created:		Sun Feb  6 12:31:29 MSK 2000
# Whom:			Sergey Samoyloff <gonza@techline.ru>
#
# $FreeBSD$
#

DISTNAME=	popa3d-0.4
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.false.com/pub/security/popa3d/

MAINTAINER=	gonza@techline.ru

post-install:

	@ ${ECHO} "==========================================================================="
	@ ${ECHO} "1. Edit your /etc/inetd.conf to use popa3d. The line should look like this:"
	@ ${ECHO} ""
	@ ${ECHO} "pop3	stream	tcp	nowait	root	/usr/local/libexec/popa3d   popa3d"
	@ ${ECHO} ""
	@ ${ECHO} "Note: when started via an inetd clone, the logging of connections is left"
	@ ${ECHO} "up to that inetd clone or TCP wrappers."
	@ ${ECHO} ""
	@ ${ECHO} "2. Restart inetd by sending it a SIGHUP:"
	@ ${ECHO} ""
	@ ${ECHO} "# killall -HUP inetd"
	@ ${ECHO} "==========================================================================="

do-install:
	${INSTALL} ${COPY} -o root -g wheel -m 500 \
	    ${WRKSRC}/popa3d ${PREFIX}/libexec/popa3d

.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/popa3d
	${INSTALL_MAN} ${WRKSRC}/INSTALL \
		${PREFIX}/share/doc/popa3d
	${INSTALL_MAN} ${WRKSRC}/DESIGN \
		${PREFIX}/share/doc/popa3d
	${INSTALL_MAN} ${WRKSRC}/COPYING \
		${PREFIX}/share/doc/popa3d
.endif

pre-install:
	${SH} ${PKGDIR}/INSTALL ${PKGNAME} PRE-INSTALL

.include <bsd.port.mk>
