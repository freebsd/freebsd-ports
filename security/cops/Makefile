# new ports collection makefile for:	cops
# Version required:			1.04
# Date created:				29 August 1996
# Whom:					oly
#
# $Id$
#

PKGNAME=	cops-1.04
DISTNAME=	cops_104
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.cert.org/pub/tools/cops/1.04/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	oly@world.std.com

EXECUTABLE = home.chk user.chk is_writable crc crc_check \
             addto clearfiles filewriters members tilde is_able
C_SRC      = home.chk.c user.chk.c is_able.c is_something.c \
             addto.c clearfiles.c filewriters.c members.c tilde.c \
             crc.c crc_check.c

pre-build:
	(cd ${WRKSRC} ; ./reconfig)
	(cd ${WRKSRC} ; \
	sed 's,^SECURE=/usr/foo/bar,SECURE=${PREFIX}/cops,g' < cops | sed '/^$$SECURE\/passwd\.chk.*/d' | sed 's,SECURE_USERS="foo@bar\.edu",SECURE_USERS="root@localhost",g' | sed 's/passwd\.chk pass.chk //g' > cops.out ; \
	mv cops.out cops ; chmod u+x cops)

do-build:
	(cd ${WRKSRC} ; make EXECUTABLE="${EXECUTABLE}" C_SRC="${C_SRC}")

do-install:
	(cd ${WRKDIR} ; rm -rf ${PREFIX}/cops ; ${MKDIR} ${PREFIX}/cops ; \
	${CP} -R ${DISTNAME}/* ${PREFIX}/cops ; \
	chmod -R go-rwx ${PREFIX}/cops ; \
	rm -rf ${PREFIX}/cops/*.old ${PREFIX}/cops/src)

.include <bsd.port.mk>
