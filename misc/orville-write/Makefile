# New ports collection makefile for:	orville-write
# Version required:	2.41a
# Date created:		4 December 1999
# Whom:			James Howard <howardj@wam.umd.edu>
#
# $FreeBSD$
#

DISTNAME=	orville-write-2.41a
CATEGORIES=	misc
MASTER_SITES=	http://www.wwnet.net/~janc/software/

MAINTAINER=	howardjp@wam.umd.edu

MAN1=	amin.1 helpers.1 huh.1 mesg.1 write.1

post-extract:
	@(cd ${WRKSRC}; ${RM} -f .depend)

post-patch:
	@${PERL} -pi -e 's,%%PREFIX%%,${PREFIX},g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_SCRIPT} -g tty -o root -m 6711 ${WRKSRC}/write ${PREFIX}/bin 
	${INSTALL_SCRIPT} -o root -m 4711 ${WRKSRC}/mesg ${PREFIX}/bin
	${INSTALL_SCRIPT} -o root -m 4711 ${WRKSRC}/amin ${PREFIX}/bin
	${INSTALL_SCRIPT} -o root -m 4711 ${WRKSRC}/huh ${PREFIX}/bin
	${INSTALL_SCRIPT} -o root -m 4711 ${WRKSRC}/helpers ${PREFIX}/bin
	${INSTALL_SCRIPT} -g tty -o root -m 6711 ${WRKSRC}/write ${PREFIX}/bin/tel
	${INSTALL_SCRIPT} -g tty -o root -m 6711 ${WRKSRC}/write ${PREFIX}/bin/chat
	${TOUCH} /var/run/wrttmp
	${TOUCH} /var/run/wrthist
	${TOUCH} /var/log/writelog
	${INSTALL_SCRIPT} ${WRKSRC}/wrttab ${PREFIX}/etc/wrttab
.for f in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/${f} ${PREFIX}/man/man1/
.endfor

.include <bsd.port.mk>
