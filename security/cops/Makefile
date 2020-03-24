# Created by: oly
# $FreeBSD$

PORTNAME=	cops
PORTVERSION=	1.04
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	https://cschubert.com/distfiles/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}+

MAINTAINER=	cy@FreeBSD.org
COMMENT=	System secureness checker

USES=		groff perl5 shebangfix
USE_PERL5=	run
WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION:S/.//g}+
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	reconfig
MAKEFILE=	makefile
MAKE_ARGS=	EXECUTABLE="${EXECUTABLE}" C_SRC="${C_SRC}"
MAKE_JOBS_UNSAFE=	yes

EXECUTABLE=	home.chk user.chk is_writable crc crc_check \
		addto clearfiles filewriters members tilde is_able
C_SRC=		home.chk.c user.chk.c is_able.c is_something.c \
		addto.c clearfiles.c filewriters.c members.c tilde.c \
		crc.c crc_check.c

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|/usr/bin/perl|${perl_CMD}|' \
		${WRKSRC}/perl/cops

pre-build:
	${SED} \
	    -e 's,^SECURE=/usr/foo/bar,SECURE=${PREFIX}/cops,g' \
	    -e '/^$$SECURE\/passwd\.chk.*/d' \
	    -e 's,SECURE_USERS="foo@bar\.edu",SECURE_USERS="root@localhost",g' \
	    -e 's/passwd\.chk pass.chk //g' \
		${WRKSRC}/cops > ${WRKSRC}/cops.out
	${MV} ${WRKSRC}/cops.out ${WRKSRC}/cops

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/cops
	${TAR} -C ${WRKSRC} --exclude "*.old" -cf - . | \
		${TAR} -C ${STAGEDIR}${PREFIX}/cops --unlink -xf -
	${CHMOD} -R go-rwx ${STAGEDIR}${PREFIX}/cops

.include <bsd.port.mk>
