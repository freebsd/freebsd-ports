# New ports collection makefile for:	pkg_tarup
# Date created:		21 Sep 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	pkg_tarup
PORTVERSION=	1.2
CATEGORIES=	misc
MASTER_SITES=	http://cvsweb.netbsd.org/bsdweb.cgi/~checkout~/pkgsrc/pkgtools/pkg_tarup/files/
DISTNAME=	${PORTNAME}\?rev=${PORTVERSION}\&content-type=text%2fplain
EXTRACT_SUFX=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	knu@FreeBSD.org

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/${DISTNAME} ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/sbin/${PORTNAME}

.include <bsd.port.mk>
