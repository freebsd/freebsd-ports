# New ports collection makefile for:	sigit
# Date created:				18 August 2001
# Whom:					petef
#
# $FreeBSD$
#

PORTNAME=	sigit
PORTVERSION=	0.1.0
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.redhead.dk/download/stable/
DISTNAME=	Sigit-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool to create random signatures

USE_PERL5=	yes
USE_GMAKE=	yes
WRKSRC=	${WRKDIR}/sigit-${PORTVERSION}

MAN1=	sigit.1 sigit.rc.1

post-patch:
	@${REINPLACE_CMD} -e 's,/etc/sigit.rc,${PREFIX}/etc/sigit.rc,; \
		s,/usr/share/sigit,${DATADIR},' ${WRKSRC}/config.h

post-install:
	@(if [ ! -f ${PREFIX}/etc/sigit.rc ]; then \
		${CP} ${PREFIX}/etc/sigit.rc.dist ${PREFIX}/etc/sigit.rc; fi)

.include <bsd.port.mk>
