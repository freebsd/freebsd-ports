# New ports collection makefile for:	sigit
# Date created:				18 August 2001
# Whom:					petef
#
# $FreeBSD$
#

PORTNAME=	sigit
PORTVERSION=	0.0.4
CATEGORIES=	mail
MASTER_SITES=	http://www.math.ku.dk/~m99khn/download/stable/

MAINTAINER=	petef@FreeBSD.org

USE_GMAKE=	yes

MAN1=	sigit.1 sigit.rc.1

post-patch:
	@${PERL} -pi -e 's,/etc/sigit.rc,${PREFIX}/etc/sigit.rc,; \
		s,/usr/share/sigit,${DATADIR},' ${WRKSRC}/config.h

post-install:
	@(if [ ! -f ${PREFIX}/etc/sigit.rc ]; then \
		${CP} ${PREFIX}/etc/sigit.rc.dist ${PREFIX}/etc/sigit.rc; fi)

.include <bsd.port.mk>
