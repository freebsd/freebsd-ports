# New ports collection makefile for:    pam-pgsql
# Date created:				Nov 16, 2000
# Whom:	      				Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	pam-pgsql
PORTVERSION=	0.5.1
CATEGORIES=	security databases
MASTER_SITES=	${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=	pool/main/p/pam-pgsql
DISTFILES=	${PORTNAME}_${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	mi@aldan.algebra.com

LIB_DEPENDS=	mhash:${PORTSDIR}/security/mhash \
		pq:${PORTSDIR}/databases/postgresql7

# When the family of Debian mirrors is added to bsd.port.mk,
# this will suddenly start making sense:
MASTER_SITE_DEBIAN?= http://ftp.debian.org/debian/%SUBDIR%/
# This should help the users of MASTER_SORT_REGEX:
.for c in at bg br cz de ee es fi fr hu it jp kr nl no nz pl se si tr uk
MASTER_SITES_DEBIAN+=	http://ftp.$c.debian.org/debian/%SUBDIR%/
.endfor
MASTER_SITES_DEBIAN+=	http://ftp.au.debian.org/pub/debian/%SUBDIR%/ \
	ftp://ftp.bora.net/pub/linux/debian/%SUBDIR%/

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
