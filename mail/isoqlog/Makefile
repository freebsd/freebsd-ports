# New ports collection makefile for:   isoqlog
# Date created:                 17 June 2002
# Whom:                         Omer Faruk Sen <roots@enderunix.org>
#
# $FreeBSD$
#

PORTNAME=	isoqlog
PORTVERSION=	2.1
CATEGORIES=	mail
MASTER_SITES=	http://www.enderunix.org/isoqlog/ \
		http://www.trunix.org/projeler/isoqlog/ \
		http://www.acikkod.org/softwares/

MAINTAINER=	roots@enderunix.org
COMMENT=	A MTA log analysis program supporting qmail, postfix, sendmail

GNU_CONFIGURE=	YES
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GMAKE=	YES

post-install:
	@${CAT} ${PKGMESSAGE} | ${SED} -e 's|%%PREFIX%%|${PREFIX}|g'

.include <bsd.port.mk>
