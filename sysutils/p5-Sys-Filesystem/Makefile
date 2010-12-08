# New ports collection makefile for:   p5-Sys-Filesystem
# Date created:                        Thu May 25 21:12:53 CDT 2006
# Whom:                                        Jim Pirzyk pirzyk@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	Sys-Filesystem
PORTVERSION=	1.30
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Sys
PKGNAMEPREFIX=	p5-

MAINTAINER=	pirzyk@FreeBSD.org
COMMENT=	Perl module to Retrieve list of filesystems and their properties

RUN_DEPENDS=	p5-Params-Util>=1.0:${PORTSDIR}/devel/p5-Params-Util
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_MODBUILD=	yes

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

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "sparc64"
MANUAL_PACKAGE_BUILD=	accesses /etc/fstab during configure phase
.endif

.include <bsd.port.post.mk>
