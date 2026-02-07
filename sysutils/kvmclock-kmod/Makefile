PORTNAME=	kvmclock
DISTVERSION=	0.0.0-a5
CATEGORIES=	sysutils
PKGNAMESUFFIX=	-kmod

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Paravirtualized Linux KVM clock support
WWW=		https://reviews.freebsd.org/D29733

LICENSE=	BSD2CLAUSE

IGNORE_FreeBSD_14=	included in base system
IGNORE_FreeBSD_15=	included in base system
IGNORE_FreeBSD_16=	included in base system
ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	not yet tested for non-x86

USES=		kmod uidfix
KMOD=		kvmclock

USE_GITHUB=	yes
GH_ACCOUNT=	klarasystems

PLIST_FILES=	${KMODDIR}/kvmclock.ko

OPTIONS_DEFINE=	DEBUG
OPTIONS_SUB=	yes

.include <bsd.port.mk>
