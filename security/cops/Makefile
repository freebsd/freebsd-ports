# new ports collection makefile for:	cops
# Version required:			1.04
# Date created:				29 August 1996
# Whom:					oly

PKGNAME=	cops-1.04
DISTNAME=	cops_104
CATEGORIES+=	security

MASTER_SITES=	ftp://ftp.cert.org/pub/tools/cops/1.04/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	oly@world.std.com

EXECUTABLE = home.chk user.chk is_writable crc crc_check \
             addto clearfiles filewriters members tilde is_able
C_SRC      = home.chk.c user.chk.c is_able.c is_something.c \
             addto.c clearfiles.c filewriters.c members.c tilde.c \
             crc.c crc_check.c

pre-build:
	(cd work/${DISTNAME} ; ./reconfig)
	(cd work/${DISTNAME} ; sed 's,^SECURE=/usr/foo/bar,SECURE=${PREFIX}/cops,g' < cops | sed '/^$$SECURE\/passwd\.chk.*/d' | sed 's,SECURE_USERS="foo@bar\.edu",SECURE_USERS="root@localhost",g' | sed 's/passwd\.chk pass.chk //g' > cops.out ; mv cops.out cops ; chmod u+x cops)

do-build:
	(cd work/${DISTNAME} ; make EXECUTABLE="${EXECUTABLE}" C_SRC="${C_SRC}")

do-install:
	(cd work ; rm -rf /usr/local/cops ; ${MKDIR} /usr/local/cops ; cp -R ${DISTNAME}/* ${PREFIX}/cops ; chmod -R go-rwx ${PREFIX}/cops ; rm -f ${PREFIX}/cops/*.old ; rm -rf ${PREFIX}/cops/src)

.include <bsd.port.mk>
