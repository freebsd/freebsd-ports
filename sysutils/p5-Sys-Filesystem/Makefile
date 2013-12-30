# Created by: Jim Pirzyk <pirzyk@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Sys-Filesystem
PORTVERSION=	1.401
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Sys
PKGNAMEPREFIX=	p5-

MAINTAINER=	pirzyk@FreeBSD.org
COMMENT=	Perl module to Retrieve list of filesystems and their properties

LICENSE=	APACHE20

RUN_DEPENDS=	p5-Params-Util>=1.0:${PORTSDIR}/devel/p5-Params-Util \
		p5-IPC-Cmd>=0.80:${PORTSDIR}/devel/p5-IPC-Cmd \
		p5-Module-Pluggable>=4.8:${PORTSDIR}/devel/p5-Module-Pluggable
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

MAN3=		Sys::Filesystem::Mswin32.3 \
		Sys::Filesystem.3 \
		Sys::Filesystem::Linux.3 \
		Sys::Filesystem::Darwin.3 \
		Sys::Filesystem::Cygwin.3 \
		Sys::Filesystem::Aix.3 \
		Sys::Filesystem::Unix.3 \
		Sys::Filesystem::Dummy.3 \
		Sys::Filesystem::Freebsd.3 \
		Sys::Filesystem::Solaris.3 \
		Sys::Filesystem::Hpux.3 \
		Sys::Filesystem::Netbsd.3

CONFIGURE_ENV+=	PATH_FSTAB=${WRKDIR}/fstab.phony

NO_STAGE=	yes
pre-configure:
	@${TOUCH} ${WRKDIR}/fstab.phony

.include <bsd.port.mk>
