PORTNAME=	pefs
DISTVERSION=	g20210628
PORTEPOCH=	1
CATEGORIES=	sysutils
PKGNAMESUFFIX=	-kmod

MAINTAINER=	darius@dons.net.au
COMMENT=	PEFS kernel level stacked cryptographic filesystem

LICENSE=	BSD2CLAUSE

ONLY_FOR_ARCHS=		aarch64 amd64 armv6 armv7 i386
ONLY_FOR_ARCHS_REASON=	untested on any other architecture

# PEFS works on -current but out of tree KLDs get incorrectly compiled without INVARIANTS
BROKEN_FreeBSD_14=	crashes on mount due to INVARIANTS

USES=		kmod uidfix
USE_GITHUB=	yes
GH_ACCOUNT=	freebsd-pefs
GH_TAGNAME=	4e03778

MAKE_JOBS_UNSAFE=yes
MAKE_ENV=	BINDIR="${PREFIX}/sbin" MANDIR="${MANPREFIX}/man/man"

PLIST_FILES=	sbin/pefs \
		lib/pam_pefs.so \
		lib/pam_pefs.so.6 \
		man/man8/pam_pefs.8.gz \
		man/man8/pefs.8.gz \
		${KMODDIR}/pefs.ko

.include <bsd.port.mk>
