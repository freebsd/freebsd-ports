# New ports collection makefile for:    pam-pgsql
# Date created:				Nov 16, 2000
# Whom:	      				Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	pam-pgsql
PORTVERSION=	0.5.2
PORTREVISION=	6
CATEGORIES=	security databases
MASTER_SITES=	${MASTER_SITE_DEBIAN} \
		http://libpam-pgsql.codecastle.com/${PORTNAME}-${PORTVERSION}-${PORTREVISION}/
MASTER_SITE_SUBDIR=	pool/non-US/main/p/pam-pgsql
DISTFILES=	${PORTNAME}_${PORTVERSION}.orig${EXTRACT_SUFX}

PATCHFILES=	${PORTNAME}_${PORTVERSION}-5.diff.gz
PATCH_SITES=	${MASTER_SITES}

MAINTAINER=	m@absolight.fr

LIB_DEPENDS=	pq:${PORTSDIR}/databases/postgresql7

PATCH_DIST_STRIP=	-p1
# When the family of Debian mirrors is added to bsd.port.mk,
# this will suddenly start making sense:
MASTER_SITE_DEBIAN?= http://debian.yorku.ca/debian/non-US/${MASTER_SITE_SUBDIR}/
# This should help the users of MASTER_SORT_REGEX:
.for c in at bg br cz de ee es fi fr hu it jp kr nl no nz pl se si tr uk
MASTER_SITE_DEBIAN+=	http://ftp.$c.debian.org/debian-non-US/${MASTER_SITE_SUBDIR}/
.endfor
MASTER_SITE_DEBIAN+=	http://ftp.au.debian.org/pub/debian-non-US/${MASTER_SITE_SUBDIR}/ \
	ftp://ftp.bora.net/pub/linux/debian-non-US/${MASTER_SITE_SUBDIR}/

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
