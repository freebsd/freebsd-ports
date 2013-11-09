# Created by: Gleb Kurtsou <gleb@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pefs
DISTVERSION=	2013-10-13
CATEGORIES=	sysutils
MASTER_SITES=	https://pefs.googlecode.com/files/
PKGNAMESUFFIX=	-kmod

MAINTAINER=	gleb@FreeBSD.org
COMMENT=	PEFS kernel level stacked cryptographic filesystem

LICENSE=	BSD

FETCH_ARGS=	-Fpr		# work around 302 redirect

MAKE_ENV=	BINDIR="${PREFIX}/sbin" MANDIR="${MANPREFIX}/man/man" \
		NO_MANCOMPRESS=

MAN8=		pam_pefs.8 pefs.8

ONLY_FOR_ARCHS=	i386 amd64	# not tested on other archs

NO_STAGE=	yes

USES=		kmod
.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800000
BROKEN=		requires fairly recent FreeBSD-STABLE, or FreeBSD-CURRENT
.endif

.include <bsd.port.post.mk>
