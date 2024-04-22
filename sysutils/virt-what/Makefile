PORTNAME=	virt-what
PORTVERSION=	1.25
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://people.redhat.com/~rjones/virt-what/files/

MAINTAINER=	otis@FreeBSD.org
COMMENT=	Utility to determine whether it is being run in virtual environment
WWW=		https://people.redhat.com/~rjones/virt-what/

LICENSE=	GPLv1

USES=		perl5

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

PLIST_FILES=	libexec/virt-what-cpuid-helper \
		share/man/man1/virt-what.1.gz \
		sbin/virt-what

.include <bsd.port.mk>
