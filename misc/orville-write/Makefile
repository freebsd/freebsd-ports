# New ports collection makefile for:	orville-write
# Date created:		4 December 1999
# Whom:			James Howard <howardj@wam.umd.edu>
#
# $FreeBSD$
#

PORTNAME=	orville-write
PORTVERSION=	2.41a
CATEGORIES=	misc
MASTER_SITES=	http://www.wwnet.net/~janc/software/

MAINTAINER=	howardjp@wam.umd.edu

MAN1=	amin.1 helpers.1 huh.1 mesg.1 write.1

post-extract:
	@(cd ${WRKSRC}; ${RM} -f .depend)

post-patch:
	@${PERL} -pi -e 's,%%PREFIX%%,${PREFIX},g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} -g tty -o root -m 6711 ${WRKSRC}/write ${PREFIX}/bin 
	${LN} -sf ${PREFIX}/bin/write ${PREFIX}/bin/tel
	${LN} -sf ${PREFIX}/bin/write ${PREFIX}/bin/chat
	${INSTALL_PROGRAM} -o root -m 4711 ${WRKSRC}/mesg ${PREFIX}/bin
	${INSTALL_PROGRAM} -o root -m 4711 ${WRKSRC}/amin ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/huh ${PREFIX}/bin
	${INSTALL_PROGRAM} -o root -m 4711 ${WRKSRC}/helpers ${PREFIX}/bin
	${TOUCH} /var/run/wrttmp
	${TOUCH} /var/run/wrthist
	${TOUCH} /var/log/writelog
	${INSTALL_DATA} ${WRKSRC}/wrttab ${PREFIX}/etc/wrttab
.for f in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/${f} ${PREFIX}/man/man1/
.endfor

.include <bsd.port.mk>
