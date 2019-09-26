# Created by: Edwin Groothuis <edwin@mavetju.org>
# $FreeBSD$

PORTNAME=	zoneinfo
DISTVERSION=	2019c
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	https://data.iana.org/time-zones/releases/ \
		ftp://ftp.iana.org/tz/releases/
DISTNAME=	tzdata${DISTVERSION}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Updated timezone definitions

LICENSE=	PD

NO_WRKSUBDIR=	yes
PREFIX=		/usr
NO_ARCH=	yes

OPTIONS_DEFINE=	BACKWARD
OPTIONS_DEFAULT=
OPTIONS_SUB=	yes

BACKWARD_DESC=	Include backwards compatible zones
BACKWARD_VARS=	tzfiles+=backward

TZFILES=	africa antarctica asia australasia etcetera europe \
		factory northamerica southamerica systemv
POSIXRULES=	America/New_York

# Run both of:
# "make DEVELOPER=1 WITHOUT=BACKWARD do-clean test-pkgplist"
# and
# "make DEVELOPER=1 WITH=BACKWARD do-clean test-pkgplist"
# before commiting!

# Make sure it breaks when the distfile isn't there anymore.
.if !defined(PACKAGE_BUILDING)
MASTER_SITES+=	http://people.freebsd.org/~edwin/
.endif

# tzsetup objects (fatally) if any entry in zone.tab or zone1970.tab
# refers to a country code that doesn't exist in misc/iso3166. While
# arguably that should be fixed, for compatibility we remove such
# entries here to avoid the problem.
#
# This used to be done by adding patch files for each country to
# remove, but that doesn't work for zone1970.tab.
#
# We generate a list of all 2-letter codes that are NOT in iso3166;
# then, for any entry in zone.tab or zone1970.tab that contains a bad
# code: first emit a commented-out version of the line, then a version
# with the bad codes stripped out of the first field (unless this
# leaves the first field empty).

post-patch:
	cd ${WRKSRC}; \
	badc=$$(${AWK} '/^[^\#]/ { t[$$1]=1; }; \
			END { for (i=0; i<676; ++i) { \
				c = sprintf("%c%c", 65+int(i/26), 65+(i%26)); \
				if (!(c in t)) print c; \
			      } \
			}' \
			/usr/share/misc/iso3166 | \
			${SED} -n -e '1h; 1!H; $${g;s/\n/|/g;p;}'); \
	for fn in zone.tab zone1970.tab; do \
		${MV} $${fn} $${fn}.bak; \
		${AWK} -v FS="\t" -v OFS="\t" -v re="(^|,)($${badc})" \
			'/^[^#]/ && $$1 ~ re { \
				print "#" $$0; \
				gsub(re,"",$$1); \
				sub(/^,/,"",$$1); \
			 }; \
			 $$1 != "" { print; }' <$${fn}.bak >$${fn}; \
	done

do-build:
	umask 022; \
	cd ${WRKSRC}; \
	zic -d ${WRKSRC}/zoneinfo -p ${POSIXRULES} -m ${NOBINMODE} \
		-y ${.OBJDIR}/yearistype ${TZFILES}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/zoneinfo
	(cd ${WRKSRC}/zoneinfo && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/zoneinfo)
	${INSTALL_DATA} ${WRKSRC}/zone.tab ${STAGEDIR}${PREFIX}/share/zoneinfo
	${INSTALL_DATA} ${WRKSRC}/zone1970.tab ${STAGEDIR}${PREFIX}/share/zoneinfo

# check-plist is too lenient for us; it doesn't care if there are
# files in the stage dir that are commented out in plist due to port
# options. But we need to check for an exact match, otherwise the
# final package may be incorrect if entries move into or out of the
# "backward" file.
#
# So this rule makes the additional check that there must be no file in
# STAGEDIR not accounted for by .plist-files-no-comments.

test-pkgplist: check-plist
	@(cd ${STAGEDIR} && ${FIND} . -type f -print) | \
		${SED} -e 's:^[.]::' | sort | \
		${COMM} -23 -- - ${WRKDIR}/.plist-files-no-comments | \
		while read -r f; do echo "MISSING FROM PLIST: $$f" >&2; echo fail; done | \
		! ${GREP} fail >/dev/null

.include <bsd.port.mk>
