# New ports collection makefile for:	smail
# Version required:	3.1.29
# Date created:		16 Oct 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.5 1995/04/11 20:28:32 asami Exp $
#

DISTNAME=	smail-3.1.29.1
CATEGORIES+=	mail
MASTER_SITES=	ftp://ftp.uu.net/networking/mail/smail/

.if !exists(/usr/local/bin/bash)
DEPENDS=	${PORTSDIR}/shells/bash
.endif

MAKE_FLAGS=	"SHELL=/usr/local/bin/bash"

pre-install:
	@mkdir -p ${PREFIX}/lib/smail
	@cp ${WRKSRC}/samples/generic/config ${PREFIX}/lib/smail/config.sample
	@cp ${WRKSRC}/samples/generic/directors ${PREFIX}/lib/smail/directorys.sample
	@cp ${WRKSRC}/samples/generic/routers ${PREFIX}/lib/smail/routers.sample
	@cp ${WRKSRC}/samples/generic/transports ${PREFIX}/lib/smail/transports.sample

.include <bsd.port.mk>
