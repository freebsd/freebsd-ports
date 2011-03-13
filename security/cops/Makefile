# New ports collection makefile for:	cops
# Date created:				29 August 1996
# Whom:					oly
#
# $FreeBSD$
#

PORTNAME=	cops
PORTVERSION=	1.04
CATEGORIES=	security
MASTER_SITES=	http://www.fish2.com/cops/ \
		http://mirror2.unixfreunde.de/ \
		http://freebsd.unixfreunde.de/sources/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}+

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A system secureness checker

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION:S/.//g}+
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	reconfig
MAKEFILE=	makefile
MAKE_ARGS=	EXECUTABLE="${EXECUTABLE}" C_SRC="${C_SRC}"

EXECUTABLE=	home.chk user.chk is_writable crc crc_check \
		addto clearfiles filewriters members tilde is_able
C_SRC=		home.chk.c user.chk.c is_able.c is_something.c \
		addto.c clearfiles.c filewriters.c members.c tilde.c \
		crc.c crc_check.c

pre-build:
	${SED} \
	    -e 's,^SECURE=/usr/foo/bar,SECURE=${PREFIX}/cops,g' \
	    -e '/^$$SECURE\/passwd\.chk.*/d' \
	    -e 's,SECURE_USERS="foo@bar\.edu",SECURE_USERS="root@localhost",g' \
	    -e 's/passwd\.chk pass.chk //g' \
		${WRKSRC}/cops > ${WRKSRC}/cops.out
	${MV} ${WRKSRC}/cops.out ${WRKSRC}/cops

do-install:
	${MKDIR} ${PREFIX}/cops
	${TAR} -C ${WRKSRC} --exclude "*.old" -cf - . | \
		${TAR} -C ${PREFIX}/cops --unlink -xf -
	${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/cops
	${CHMOD} -R go-rwx ${PREFIX}/cops

.include <bsd.port.mk>
