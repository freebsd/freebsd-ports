# Created by: Doug Ambrisko <ambrisko@whistle.com>
# $FreeBSD$

PORTNAME=	etherboot
PORTVERSION=	5.2.6
CATEGORIES=	net
MASTER_SITES=	SF http://etherboot.berlios.de/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Network boot of FreeBSD a.out/ELF kernels (improved netboot)

BROKEN=		Installation is intentionally broken

SSP_UNSAFE=	yes
ONLY_FOR_ARCHS=	i386
NO_PACKAGE=	lots of configuration necessary

USES=		gmake perl5 tar:bzip2
USE_PERL5=	build

WRKSRC=		${WRKDIR}/${DISTNAME}/src

NO_STAGE=	yes
do-install:
	@${ECHO_MSG}
	@${ECHO_MSG} Refer to ${DESCR} and ${WRKDIR}/${PKGNAME}/doc for \
		how to build and install the ROM/floppy image. | ${FMT} -w 76
	@${FALSE}

.include <bsd.port.mk>
