# New ports collection makefile for:	PSCyr
# Date created:				29 Jun 2001
# Whom:					kapr@crosswinds.net
#
# $FreeBSD$
#

PORTNAME=	PSCyr
PORTVERSION=	0.4c1
CATEGORIES=	russian print
MASTER_SITES=	ftp://mch5.chem.msu.su/pub/russian/psfonts/ \
		ftp://ftp.vsu.ru/pub/tex/font-packs/pscyr/
DISTFILES=	${PORTNAME}-${PORTVERSION:S/1/-patch1/}-tex.tar.gz \
		${PORTNAME}-${PORTVERSION:S/1/-patch1/}-type1.tar.gz

MAINTAINER=	kapr@crosswinds.net

RUN_DEPENDS=	mktexlsr:${PORTSDIR}/print/teTeX
# no other TeX is sufficient

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

post-patch:
	${PERL5} -i.bak -pe 's/^mv\b/${INSTALL_DATA}/' ${WRKDIR}/install.sh

do-install:
	(cd ${WRKDIR}; ${SH} install.sh ${PREFIX})

post-install:
	${SH} ${PKGDIR}/pkg-install ${PKGNAME} POST-INSTALL ${PREFIX}

post-deinstall:
	${SH} ${PKGDIR}/pkg-deinstall ${PKGNAME} POST-DEINSTALL ${PREFIX}

.include <bsd.port.mk>
