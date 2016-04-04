# Created by: Jim Pirzyk <pirzyk@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Sys-Filesystem
PORTVERSION=	1.401
PORTREVISION=	1
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	pirzyk@FreeBSD.org
COMMENT=	Perl module to Retrieve list of filesystems and their properties

LICENSE=	APACHE20

RUN_DEPENDS=	p5-Params-Util>=1.0:devel/p5-Params-Util \
		p5-IPC-Cmd>=0.80:devel/p5-IPC-Cmd \
		p5-Module-Pluggable>=4.8:devel/p5-Module-Pluggable
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

CONFIGURE_ENV+=	PATH_FSTAB=${WRKDIR}/fstab.phony

pre-configure:
	@${TOUCH} ${WRKDIR}/fstab.phony

.include <bsd.port.mk>
