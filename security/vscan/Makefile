# New ports collection makefile for:	uvscan
# Date created:		01 Sep 2000
# Whom:			Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	uvscan
PORTVERSION=	4.24e
CATEGORIES=	security
MASTER_SITES=	http://download.nai.com/products/evaluation/virusscan/english/cmdline/bsd/version_4.24/
DISTNAME=	vbsd424e
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	jeh@FreeBSD.org
COMMENT=	Evaluation version of a DOS/Windows/Linux file virus scanner

RUN_DEPENDS+=	${LOCALBASE}/sbin/update_dat:${PORTSDIR}/security/uvscan-dat
LIB_DEPENDS+=	c.3:${PORTSDIR}/misc/compat3x

ONLY_FOR_ARCHS=	i386
NO_BUILD=	YES
NO_WRKSUBDIR=	YES

LICENSE=	shareware
RESTRICTED=	"restrictive 30 day evaluation license"

do-configure:
	${SED} <${FILESDIR}/uvscan.sh >${WRKSRC}/uvscan.sh \
		-e 's:@@PREFIX@@:${PREFIX}:g'

do-install:
	${MKDIR} ${PREFIX}/libexec/uvscan
	${INSTALL_SCRIPT} ${WRKSRC}/uvscan ${PREFIX}/libexec/uvscan
	${INSTALL_SCRIPT} ${WRKSRC}/uvscan.sh ${PREFIX}/bin/uvscan
	${INSTALL_PROGRAM} ${WRKSRC}/libbsdfv.so ${PREFIX}/lib/libbsdfv.so
	${INSTALL_PROGRAM} ${WRKSRC}/libbsdfv.so.4 ${PREFIX}/lib/libbsdfv.so.4
.for file in license.dat messages.dat
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/libexec/uvscan
.endfor
	${MKDIR} ${PREFIX}/share/doc/uvscan
.for file in e4240upg.pdf license.txt
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/uvscan
.endfor

.include <bsd.port.mk>
