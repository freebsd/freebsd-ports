# New ports collection makefile for:	uvscan
# Date created:		01 Sep 2000
# Whom:			Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	uvscan
PORTVERSION=	4.07e
CATEGORIES=	security
MASTER_SITES=	http://download.mcafee.com/products/evaluation/virusscan/english/unix/free_bsd/
DISTNAME=	vbsd407e
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	kris@FreeBSD.org

RUN_DEPENDS+=	${LOCALBASE}/sbin/update_dat:${PORTSDIR}/security/uvscan-dat

ONLY_FOR_ARCHS=	i386
NO_BUILD=	YES
NO_WRKSUBDIR=	YES

LICENSE=	shareware
RESTRICTED=	"restrictive 30 day evaluation license"

do-configure:
	${SED} <${FILESDIR}/uvscan.sh >${WRKSRC}/uvscan.sh \
		-e 's:@@PREFIX@@:${PREFIX}:g'

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/uvscan ${PREFIX}/libexec/uvscan
	${INSTALL_SCRIPT} ${WRKSRC}/uvscan.sh ${PREFIX}/bin/uvscan
.for file in license.dat messages.dat
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/libexec/uvscan
.endfor
.for file in unx47uag.pdf license.txt
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/uvscan
.endfor

.include <bsd.port.mk>
