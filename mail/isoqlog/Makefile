# New ports collection makefile for:   isoqlog
# Date created:                 17 June 2002
# Whom:				ofsen@enderunix.org
#
# $FreeBSD$
#

PORTNAME=	isoqlog
PORTVERSION=	2.2.1
CATEGORIES=	mail
MASTER_SITES=	http://www.enderunix.org/isoqlog/ \
		http://www.trunix.org/projeler/isoqlog/ \
		http://www.acikkod.org/softwares/

MAINTAINER=	ofsen@enderunix.org
COMMENT=	A qmail, postfix, sendmail, exim MTA log analysis program

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GMAKE=	yes

post-install:
	@${CAT} ${PKGMESSAGE} | ${SED} -e 's|%%PREFIX%%|${PREFIX}|g'

.include <bsd.port.mk>
