# New ports collection makefile for:    pam-pgsql
# Date created:				Nov 16, 2000
# Whom:	      				Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	pam-pgsql
PORTVERSION=	0.5.2
PORTREVISION=	8
CATEGORIES=	security databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		${MASTER_SITE_LOCAL:S/$/:local/}
MASTER_SITE_SUBDIR=	pam-pgsql mat/:local
DISTFILES=	${PORTNAME}_${PORTVERSION}.orig${EXTRACT_SUFX}:DEFAULT,local

PATCHFILES=	${PORTNAME}_${PORTVERSION}-5.diff.gz:DEFAULT,local
PATCH_SITES=	${MASTER_SITES}
PATCH_SITE_SUBDIR=	${MASTER_SITE_SUBDIR} mat/:local

MAINTAINER=	mat@FreeBSD.org
COMMENT=	A pam module for authenticating with PostgreSQL

LIB_DEPENDS=	pq.3:${PORTSDIR}/${POSTGRESQL_PORT}

POSTGRESQL_PORT?=	databases/postgresql7

PATCH_DIST_STRIP=	-p1

MAKEFILE=	${FILESDIR}/Makefile.bsd
MAKE_ARGS+=	FILESDIR=${FILESDIR}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 501000
BROKEN=		"Does not compile"
.endif

post-install:
	${CAT} ${PKGMESSAGE}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${LOCALBASE}/${DOCDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/debian/changelog \
		${WRKSRC}/debian/copyright ${LOCALBASE}/${DOCDIR}

DOCDIR=		share/doc/pam-pgsql
PLIST_SUB+=	DOCDIR=${DOCDIR}
.endif

.include <bsd.port.post.mk>
