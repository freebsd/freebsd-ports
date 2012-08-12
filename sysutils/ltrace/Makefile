# New ports collection makefile for:  ltrace
# Date created:			  2012-07-31
# Whom:				  Sofian Brabez <sbz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ltrace
PORTVERSION=	0.4
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_FREEBSD_ORG:S,%SUBDIR%,distfiles,} \
		${MASTER_SITE_LOCAL:S,%SUBDIR%,sbz,}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Track runtime library calls in dynamically linked programs

LIB_DEPENDS=	elf:${PORTSDIR}/devel/libelf

LICENCE=	GPLv2
LICENCE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	i386

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=		${PORTNAME}.1
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|^\(CC\)|#\1|' ${WRKSRC}/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/etc/${PORTNAME}.conf ${PREFIX}/etc
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${PREFIX}/man/man1

.include <bsd.port.mk>
