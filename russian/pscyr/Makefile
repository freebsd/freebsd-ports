# New ports collection makefile for:	PSCyr
# Date created:				29 Jun 2001
# Whom:					kapr@crosswinds.net
#
# $FreeBSD$
#

PORTNAME=	PSCyr
PATCH_LEVEL=	2
PORTVERSION=	0.4c${PATCH_LEVEL}
CATEGORIES=	russian print
MASTER_SITES=	ftp://scon155.phys.msu.su/pub/russian/psfonts/ \
		ftp://ftp.vsu.ru/pub/tex/font-packs/pscyr/
DISTFILES=	${PORTNAME}-${PORTVERSION:S/${PATCH_LEVEL}$/-patch&/}-tex.tar.gz \
		${PORTNAME}-${PORTVERSION:S/${PATCH_LEVEL}$/-patch&/}-type1.tar.gz

MAINTAINER=	kappa@freebsd.org.ua

RUN_DEPENDS=	mktexlsr:${PORTSDIR}/print/teTeX
# no other TeX is sufficient

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

post-patch:
	@${CP} ${WRKDIR}/install.sh ${WRKDIR}/install.sh.orig;
	@${SED} -e 's/^mv /${INSTALL_DATA} /' \
		${WRKDIR}/install.sh.orig > ${WRKDIR}/install.sh

do-install:
	(cd ${WRKDIR}; ${SH} install.sh ${PREFIX})

post-install:
	${SH} ${PKGDIR}/pkg-install ${PKGNAME} POST-INSTALL ${PREFIX}

post-deinstall:
	${SH} ${PKGDIR}/pkg-deinstall ${PKGNAME} POST-DEINSTALL ${PREFIX}

.include <bsd.port.mk>
