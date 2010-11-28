# New ports collection makefile for:	gdisk
# Date created:		12 July 2010
# Whom:			Dmitry N Fomin <fdn@okbire.ru>
#
# $FreeBSD$
#

PORTNAME=	gdisk
PORTVERSION=	0.6.13
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gptfdisk/gptfdisk/${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	fdn@okbire.ru
COMMENT=	GPT fdisk

LIB_DEPENDS=	uuid.1:${PORTSDIR}/misc/e2fsprogs-libuuid \
		popt.0:${PORTSDIR}/devel/popt

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

FETCH_ARGS=	-Rr

ONLY_FOR_ARCHS=	i386 amd64

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 701100
IGNORE=		is unsupported on FreeBSD 7.1-RELEASE or earlier
.endif

MAKEFILE=	Makefile.freebsd

MAN8=		gdisk.8 sgdisk.8

post-patch:
	${REINPLACE_CMD} -e 's|/usr/include/||' ${WRKSRC}/guid.h

do-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.endif
.for i in gdisk sgdisk
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/${i}.8 ${MANPREFIX}/man/man8
.if !defined(NOPORTDOCS)
	${INSTALL_MAN} ${WRKSRC}/${i}.html ${DOCSDIR}
.endif
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
