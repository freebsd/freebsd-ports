PORTNAME=	global-tz
DISTVERSION=	2022agtz
CATEGORIES=	misc
MASTER_SITES=	https://github.com/JodaOrg/${PORTNAME}/releases/download/${DISTVERSION}/:tzdata \
		https://raw.githubusercontent.com/JodaOrg/${PORTNAME}/${DISTVERSION}/:tab
DISTNAME=	tzdata${DISTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:tzdata \
		zone1970.tab:tab
DIST_SUBDIR=	${DISTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	philip@FreeBSD.org
COMMENT=	Fork of the IANA Time Zone Database with expanded pre-1970 data

LICENSE=	PD

NO_WRKSUBDIR=	yes
PREFIX=		/usr
DATADIR=	${PREFIX}/share/zoneinfo
NO_ARCH=	yes

TZFILES=	africa antarctica asia australasia etcetera europe \
		factory northamerica southamerica backward
POSIXRULES=	America/New_York


# XXX The global-tz distribution omits the zone1970.tab file, precluding
# it from being a drop-in replacement for the IANA Time Zone Database.

post-extract:
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/zone1970.tab ${WRKSRC}

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

.include <bsd.port.mk>
