# New ports collection makefile for:	zoneinfo
# Date created:				27 March 2006
# Whom:					Edwin Groothuis <edwin@mavetju.org>
#
# $FreeBSD$

PORTNAME=	zoneinfo
DISTVERSION=	2006g
CATEGORIES=	misc
MASTER_SITES=	ftp://elsie.nci.nih.gov/pub/
DISTNAME=	tzdata${DISTVERSION}

MAINTAINER=	edwin@mavetju.org
COMMENT=	Updated timezone definitions

WRKSRC=		${WRKDIR}
PREFIX=		/usr

USE_PERL5_BUILD=yes

TZFILES=	africa antarctica asia australasia etcetera europe \
		factory northamerica southamerica systemv
POSIXRULES=	America/New_York

# Prevent packages if on the FreeBSD building cluster. This because
# it overwrite system files and directories.
.if defined(PACKAGE_BUILDING)
NO_PACKAGE=	yes
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
EXTRA_PATCHES=	${FILESDIR}/patch4-zone.tab
.endif

do-build:
	umask 022; \
	cd ${WRKSRC}; \
	zic -d ${WRKSRC}/zoneinfo -p ${POSIXRULES} -m ${NOBINMODE} \
		${LEAPFILE} -y ${.OBJDIR}/yearistype ${TZFILES}

do-install:
	${MKDIR} ${PREFIX}/share/zoneinfo
	${CP} -R -p ${WRKSRC}/zoneinfo/ ${PREFIX}/share/zoneinfo
	${INSTALL_DATA} ${WRKSRC}/zone.tab ${PREFIX}/share/zoneinfo

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
