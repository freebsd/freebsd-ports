# New ports collection makefile for:	smail
# Version required:	3.1.28
# Date created:		16 Oct 1994
# Whom:			torstenb
#
# $Id:$
#

DISTNAME=	smail-3.1.28
MASTER_SITES=	ftp://ftp.uu.net/networking/mail/smail/
.if !exists(/usr/local/bin/bash)
DEPENDS=	${PORTSDIR}/shells/bash
.endif
MAKE_FLAGS=	"SHELL=/usr/local/bin/bash"
EXTRACT_SUFX=	.tar.Z

pre-install:
	@mkdir -p ${PREFIX}/bin
	@mkdir -p ${PREFIX}/lib/smail
	@mkdir -p ${PREFIX}/man/man1
	@mkdir -p ${PREFIX}/man/man5
	@mkdir -p ${PREFIX}/man/man8
	@cp ${WRKSRC}/samples/generic/config ${PREFIX}/lib/smail/config.sample
	@cp ${WRKSRC}/samples/generic/directors ${PREFIX}/lib/smail/directorys.sample
	@cp ${WRKSRC}/samples/generic/routers ${PREFIX}/lib/smail/routers.sample
	@cp ${WRKSRC}/samples/generic/transports ${PREFIX}/lib/smail/transports.sample

.include <bsd.port.mk>
