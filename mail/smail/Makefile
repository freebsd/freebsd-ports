# New ports collection makefile for:	smail
# Version required:	3.1.29
# Date created:		16 Oct 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.12 1996/11/10 21:32:45 obrien Exp $
#

DISTNAME=	smail-3.1.29.1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.uu.net/networking/mail/smail/

MAINTAINER=	torstenb@FreeBSD.ORG

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash

MAKE_FLAGS=	"SHELL=${PREFIX}/bin/bash"
MAN1=		pathto.1 uuwho.1 uupath.1
MAN5=		smail.5
MAN8=		pathalias.8 mkdbm.8 mkline.8 mksort.8 mkaliases.8 smail.8 \
		mkpath.8 pathmerge.8 checkerr.8 getmap.8 mkhpath.8 savelog.8 \
		mkuuwho.8 mailq.8 sendmail.8 runq.8 rmail.8 rsmtp.8 smtpd.8

pre-install:
	${MKDIR} ${PREFIX}/lib/smail

post-install:
	@${INSTALL_DATA} ${WRKSRC}/samples/generic/config ${PREFIX}/lib/smail/config.sample
	@${INSTALL_DATA} ${WRKSRC}/samples/generic/directors ${PREFIX}/lib/smail/directors.sample
	@${INSTALL_DATA} ${WRKSRC}/samples/generic/routers ${PREFIX}/lib/smail/routers.sample
	@${INSTALL_DATA} ${WRKSRC}/samples/generic/transports ${PREFIX}/lib/smail/transports.sample

.include <bsd.port.mk>
