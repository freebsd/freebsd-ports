# New ports collection makefile for:	smail
# Version required:	3.1.29
# Date created:		16 Oct 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.10 1995/10/06 22:03:17 torstenb Exp $
#

DISTNAME=	smail-3.1.29.1
CATEGORIES+=	mail
MASTER_SITES=	ftp://ftp.uu.net/networking/mail/smail/

MAINTAINER=	torstenb@FreeBSD.ORG

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash

MAKE_FLAGS=	"SHELL=${PREFIX}/bin/bash"

pre-install:
	mkdir -p ${PREFIX}/lib/smail

post-install:
	@cp ${WRKSRC}/samples/generic/config ${PREFIX}/lib/smail/config.sample
	@cp ${WRKSRC}/samples/generic/directors ${PREFIX}/lib/smail/directors.sample
	@cp ${WRKSRC}/samples/generic/routers ${PREFIX}/lib/smail/routers.sample
	@cp ${WRKSRC}/samples/generic/transports ${PREFIX}/lib/smail/transports.sample
	gzip -9nf ${PREFIX}/man/man1/pathto.1 ${PREFIX}/man/man1/uuwho.1 \
	${PREFIX}/man/man1/uupath.1 ${PREFIX}/man/man5/smail.5 \
	${PREFIX}/man/man8/pathalias.8 ${PREFIX}/man/man8/mkdbm.8 \
	${PREFIX}/man/man8/mkline.8 ${PREFIX}/man/man8/mksort.8 \
	${PREFIX}/man/man8/mkaliases.8 ${PREFIX}/man/man8/smail.8 \
	${PREFIX}/man/man8/mkpath.8 ${PREFIX}/man/man8/pathmerge.8 \
	${PREFIX}/man/man8/checkerr.8 ${PREFIX}/man/man8/getmap.8 \
	${PREFIX}/man/man8/mkhpath.8 ${PREFIX}/man/man8/savelog.8 \
	${PREFIX}/man/man8/mkuuwho.8 ${PREFIX}/man/man8/mailq.8 \
	${PREFIX}/man/man8/sendmail.8 ${PREFIX}/man/man8/runq.8 \
	${PREFIX}/man/man8/rmail.8 ${PREFIX}/man/man8/rsmtp.8 \
	${PREFIX}/man/man8/smtpd.8

.include <bsd.port.mk>
