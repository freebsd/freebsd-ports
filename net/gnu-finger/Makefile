# New ports collection makefile for:	GNU finger
# Date created:				20 June 1996
# Whom:					Yoshiro MIHIRA <sanpei@yy.cs.keio.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	finger
PORTVERSION=	1.37
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	finger
PKGNAMEPREFIX=	gnu-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU version of finger

CONFLICTS=	pfinger-0.*

post-patch:
	${REINPLACE_CMD} -e 's,DEFS="$$DEFS -D_ANSI_SOURCE",,' \
		${WRKSRC}/configure
	${REINPLACE_CMD} -e 's,extern char \*sys_errlist,//extern char \*sys_errlist,' \
		${WRKSRC}/lib/os.c ${WRKSRC}/lib/error.c
	${REINPLACE_CMD} -e 's,longjmperror (),void longjmperror (void),' \
		${WRKSRC}/lib/error.c
	${REINPLACE_CMD} -e 's,\, sys_nerr,,' \
		${WRKSRC}/lib/error.c
	${REINPLACE_CMD} -e 's,char \*source,const char \*source,' \
		${WRKSRC}/lib/savedir.c

HAS_CONFIGURE=	yes
INSTALL_TARGET=	server

post-install:
	${MKDIR} ${PREFIX}/etc/fingerdir
	${MKDIR} ${PREFIX}/etc/rc.d
	@${CP} ${WRKSRC}/support/ttylocs ${PREFIX}/etc/fingerdir/ttylocs.sample
	@${CP} ${FILESDIR}/clients.sample ${PREFIX}/etc/fingerdir/clients.sample
	@${INSTALL} ${COPY} -m 744 -o root ${FILESDIR}/fingerd.sh.sample ${PREFIX}/etc/rc.d/fingerd.sh.sample
	@${ECHO_CMD} "GNU.finger.server.hostname" > ${PREFIX}/etc/fingerdir/serverhost.sample
	@${ECHO_CMD} "mail.spool.server.hostname" > ${PREFIX}/etc/fingerdir/mailhost.sample

.include <bsd.port.mk>
