# New ports collection makefile for:	zoneinfo
# Date created:				27 March 2006
# Whom:					Edwin Groothuis <edwin@mavetju.org>
#
# $FreeBSD$

PORTNAME=	zoneinfo
DISTVERSION=	2011m
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.iana.org/tz/releases/ \
		ftp://munnari.oz.au/pub/
DISTNAME=	tzdata${DISTVERSION}

MAINTAINER=	edwin@mavetju.org
COMMENT=	Updated timezone definitions

WRKSRC=		${WRKDIR}
PREFIX=		/usr

TZFILES=	africa antarctica asia australasia etcetera europe \
		factory northamerica southamerica systemv
POSIXRULES=	America/New_York

# Prevent packages if on the FreeBSD building cluster. This because
# it overwrites system files and directories.
.if defined(PACKAGE_BUILDING)
NO_PACKAGE=	Overwrites files in the base system
.endif

# Make sure it breaks when the distfile isn't there anymore.
.if !defined(PACKAGE_BUILDING)
MASTER_SITES+=	http://people.freebsd.org/~edwin/
.endif

.include <bsd.port.pre.mk>

# The following country codes can be missing from /usr/share/misc/iso3166 and
# shouldn't appear in the zoneinfo file.
MISSING=	ax bl bq cw gg im je me mf rs ss sx

.ifndef NOMISSING
.for M in ${MISSING}
HAS_${M:U}!=	${GREP} -c ^${M:U} /usr/share/misc/iso3166 || ${TRUE}
.if ${HAS_${M:U}} == "0"
EXTRA_PATCHES+=	${FILESDIR}/patchremove-${M}
.endif
.endfor
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
	@if [ -f /var/db/zoneinfo -a -O /var/db/zoneinfo -a \
	     -G /var/db/zoneinfo -a \
	     -f /usr/share/zoneinfo/$$(cat /var/db/zoneinfo) ]; then \
		tzsetup -r; \
		echo "/etc/localtime is updated."; \
	else \
		${CAT} ${PKGMESSAGE}; \
	fi

test-patches:
.for M in ${MISSING}
	make clean
	NOMISSING=1 EXTRA_PATCHES=${FILESDIR}/patchremove-${M} make patch
.endfor

.include <bsd.port.post.mk>
