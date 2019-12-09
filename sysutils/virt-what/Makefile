# $FreeBSD$

PORTNAME=	virt-what
PORTVERSION=	1.20
CATEGORIES=	sysutils
MASTER_SITES=	https://people.redhat.com/~rjones/virt-what/files/

MAINTAINER=	juraj@lutter.sk
COMMENT=	Utility to determine whether it is being run in virtual environment

LICENSE=	GPLv1

USES=		cpe perl5

GNU_CONFIGURE=	yes

PLIST_FILES=	libexec/virt-what-cpuid-helper \
		man/man1/virt-what.1.gz \
		sbin/virt-what

.include <bsd.port.mk>
