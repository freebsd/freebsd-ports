# New ports collection makefile for:	cops
# Date created:				29 August 1996
# Whom:					oly
#
# $FreeBSD$
#

PORTNAME=	cops
PORTVERSION=	1.04
DISTNAME=	cops.1.04
PKGNAME=	cops-1.04
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.cert.org/pub/tools/cops/
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	oly@world.std.com

WRKSRC=		${WRKDIR}/cops_104
EXECUTABLE=	home.chk user.chk is_writable crc crc_check \
		addto clearfiles filewriters members tilde is_able
C_SRC=		home.chk.c user.chk.c is_able.c is_something.c \
		addto.c clearfiles.c filewriters.c members.c tilde.c \
		crc.c crc_check.c

pre-build:
	(cd ${WRKSRC} ; ./reconfig)
	(cd ${WRKSRC} ; \
	${SED} 's,^SECURE=/usr/foo/bar,SECURE=${PREFIX}/cops,g' < cops | ${SED} '/^$$SECURE\/passwd\.chk.*/d' | ${SED} 's,SECURE_USERS="foo@bar\.edu",SECURE_USERS="root@localhost",g' | ${SED} 's/passwd\.chk pass.chk //g' > cops.out ; \
	${MV} cops.out cops ; ${CHMOD} u+x cops)

do-build:
	(cd ${WRKSRC} ; make EXECUTABLE="${EXECUTABLE}" C_SRC="${C_SRC}")

do-install:
	(cd ${WRKSRC} ; ${RM} -rf ${PREFIX}/cops ; ${MKDIR} ${PREFIX}/cops ; \
	${CP} -R * ${PREFIX}/cops ; \
	${CHMOD} -R go-rwx ${PREFIX}/cops ; \
	${RM} -rf ${PREFIX}/cops/*.old ${PREFIX}/cops/src)

.include <bsd.port.mk>
