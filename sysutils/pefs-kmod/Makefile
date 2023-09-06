PORTNAME=	pefs
DISTVERSION=	g20230906
PORTEPOCH=	1
CATEGORIES=	sysutils
PKGNAMESUFFIX=	-kmod

MAINTAINER=	darius@dons.net.au
COMMENT=	PEFS kernel level stacked cryptographic filesystem
WWW=		https://wiki.freebsd.org/PEFS

LICENSE=	BSD2CLAUSE

ONLY_FOR_ARCHS=		amd64 armv6 i386
ONLY_FOR_ARCHS_REASON=	untested on any other arch

USES=		kmod uidfix
USE_GITHUB=	yes
GH_ACCOUNT=	freebsd-pefs
GH_PROJECT=	pefs
GH_TAGNAME=	4d6f95a

MAKE_ENV=	BINDIR="${PREFIX}/sbin" MANDIR="${MANPREFIX}/man/man"
MAKE_JOBS_UNSAFE=yes

PLIST_FILES=	sbin/pefs \
		lib/pam_pefs.so \
		lib/pam_pefs.so.6 \
		man/man8/pam_pefs.8.gz \
		man/man8/pefs.8.gz \
		${KMODDIR}/pefs.ko

.include <bsd.port.mk>
