# New ports collection makefile for:  pathchar
# Version required:    a0 (a.out systems), a1 (ELF systems)
# Date created:        7 November 1998
# Whom:                Josh Gilliam <josh@quick.net>
#
# $Id: Makefile,v 1.1.1.1 1998/11/15 21:25:16 nectar Exp $
#

DISTNAME=	pathchar-a1-freebsd-3.0
PKGNAME=	pathchar-a1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.ee.lbl.gov/pathchar/

MAINTAINER=	josh@quick.net

.include <bsd.port.pre.mk>
.if ${PORTOBJFORMAT} == "aout"
DISTNAME=	pathchar-a0-freebsd-2.2
PKGNAME=	pathchar-a0
.endif

NO_BUILD=	yes
NO_WRKSUBDIR=   yes

ZCAT?=		zcat
TAR?=		tar

# wierd .. pathchar-a0 is a gzip'd gzip'd tar, while pathchar-a1
# is just a tar.  both have the extension .tar.gz though...
.if ${PORTOBJFORMAT} == "aout"
do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@for file in ${EXTRACT_ONLY}; do                                \
		if ! (cd ${WRKDIR} && ${ZCAT} ${DISTDIR}/$$file |       \
		${TAR} ${EXTRACT_BEFORE_ARGS} - ${EXTRACT_AFTER_ARGS}); \
		then							\
			exit 1;						\
		fi							\
	done
.else
EXTRACT_BEFORE_ARGS=	-xf
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pathchar ${PREFIX}/bin
	${INSTALL_DATA} ${FILESDIR}/README.pathchar \
		${PREFIX}/share/doc/README.pathchar

.include <bsd.port.post.mk>
