# New ports collection makefile for:    pam-pgsql
# Date created:				Nov 16, 2000
# Whom:	      				Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	pam-pgsql
PORTVERSION=	0.3
CATEGORIES=	security databases
# When the family of Debian mirrors is added to bsd.port.mk,
# this will suddenly start making sense:
MASTER_SITES=	http://ftp.debian.org/debian/${MASTER_SITE_SUBDIR}/ \
		ftp://ftp.bora.net/pub/linux/debian/${MASTER_SITE_SUBDIR}/ \
		${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=	dists/woody/main/source/admin
DISTFILES=	${PORTNAME}_${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	mi@aldan.algebra.com

LIB_DEPENDS=	pq:${PORTSDIR}/databases/postgresql7

MAKEFILE=	${FILESDIR}/Makefile.bsd
MAKE_ARGS+=	-j 2

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
