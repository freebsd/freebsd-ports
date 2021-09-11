PORTNAME=	kvmclock
DISTVERSION=	0.0.0-a4
CATEGORIES=	sysutils
PKGNAMESUFFIX=	-kmod

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Paravirtualized Linux KVM clock support

LICENSE=	BSD2CLAUSE

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
