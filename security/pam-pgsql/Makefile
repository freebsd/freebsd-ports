# New ports collection makefile for:    pam-pgsql
# Date created:				Nov 16, 2000
# Whom:	      				Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	pam-pgsql
PORTVERSION=	0.5.2
PORTREVISION=	7
CATEGORIES=	security databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://mat.cc/distfiles/
MASTER_SITE_SUBDIR=	pam-pgsql
DISTFILES=	${PORTNAME}_${PORTVERSION}.orig${EXTRACT_SUFX}

PATCHFILES=	${PORTNAME}_${PORTVERSION}-5.diff.gz
PATCH_SITES=	${MASTER_SITES}
PATCH_SITE_SUBDIR=	${MASTER_SITE_SUBDIR}

MAINTAINER=	m@absolight.net
COMMENT=	A pam module for authenticating with PostgreSQL

LIB_DEPENDS=	pq.3:${PORTSDIR}/${POSTGRESQL_PORT}

POSTGRESQL_PORT?=	databases/postgresql7

PATCH_DIST_STRIP=	-p1

MAKEFILE=	${FILESDIR}/Makefile.bsd
MAKE_ARGS+=	FILESDIR=${FILESDIR}

post-install:
	${CAT} ${PKGMESSAGE}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${LOCALBASE}/${DOCDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/debian/changelog \
		${WRKSRC}/debian/copyright ${LOCALBASE}/${DOCDIR}

DOCDIR=		share/doc/pam-pgsql
PLIST_SUB+=	DOCDIR=${DOCDIR}
.endif

.include <bsd.port.mk>
